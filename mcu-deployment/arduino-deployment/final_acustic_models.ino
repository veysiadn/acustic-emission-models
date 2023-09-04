#include <TensorFlowLite.h>

#include "main_functions.h"
#include "model.h"
#include "tensorflow/lite/micro/all_ops_resolver.h"
#include "tensorflow/lite/micro/tflite_bridge/micro_error_reporter.h"
#include "tensorflow/lite/micro/micro_interpreter.h"
#include "tensorflow/lite/micro/micro_mutable_op_resolver.h"
// #include "tensorflow/lite/micro/system_setup.h"
#include "tensorflow/lite/schema/schema_generated.h"

namespace
{
  tflite::ErrorReporter *error_reporter = nullptr;
  const tflite::Model *model = nullptr;
  tflite::MicroInterpreter *interpreter = nullptr;
  TfLiteTensor *model_input = nullptr;
    TfLiteTensor *output = nullptr;
  // RecognizeCommands *recognizer = nullptr;

  // Create an area of memory to use for input, output, and intermediate arrays.
  // The size of this will depend on the model you're using, and may need to be
  // determined by experimentation.
  #if DENSE_MODEL
    constexpr int kTensorArenaSize = 8828;
  #endif
  #if DENSE_MODEL_OPTIMIZED && !ALL_OPS_RESOLVER
    constexpr int kTensorArenaSize = 8828;
  #endif
  #if CUSTOM_CONV_MODEL
    constexpr int kTensorArenaSize = 75 * 1024;
  #endif
  #if CUSTOM_CONV_MODEL_OPTIMIZED
    constexpr int kTensorArenaSize = 20 * 1024;
  #endif
  #if CONV_MODEL_PAPER
    constexpr int kTensorArenaSize = 100 * 1024;
  #endif      
  #if CONV_MODEL_PAPER_2D
    constexpr int kTensorArenaSize = 100 * 1024;
  #endif  
  #if CONV_MODEL_PAPER_2D_OPTIMIZED
    constexpr int kTensorArenaSize = 40 * 1024;
  #endif    
  static uint8_t tensor_arena[kTensorArenaSize]; // Maybe we should move this to external
} // namespace

enum error_status
{
  kNoError = 0,
  kVersionError,
  kResolverError,
  kInterpreterError,
  kInputTensorError,
  kTensorAllocationError,
  kInvokeError,
};
uint8_t error_code = kNoError;

float example_signal[1000] = { -6.06968882e-04, -6.06968882e-04, -6.06968882e-04, -6.06968882e-04,
       -6.06968882e-04, -6.06968882e-04, -6.06968882e-04, -6.06968882e-04,
       -6.06968882e-04, -6.06968882e-04, -6.06968882e-04, -6.06968882e-04,
       -6.06968882e-04, -6.06968882e-04, -6.06968882e-04, -6.06968882e-04,
       -6.06968882e-04, -6.06968882e-04, -6.06968882e-04, -6.06968882e-04,
       -6.06968882e-04, -6.06968882e-04, -6.06968882e-04, -6.06968882e-04,
       -6.06968882e-04, -6.06968882e-04, -6.06968882e-04, -6.06968882e-04,
       -6.06968882e-04, -6.06968882e-04, -6.06968882e-04, -6.06968882e-04,
       -6.06968882e-04, -6.06968882e-04, -6.06968882e-04, -6.06968882e-04,
       -6.06968882e-04, -6.06968882e-04, -6.06968882e-04, -6.06968882e-04,
       -6.06968882e-04, -6.06968882e-04, -6.06968882e-04, -6.06968882e-04,
       -6.06968882e-04, -6.06968882e-04, -6.06968882e-04, -6.06968882e-04,
       -6.06968882e-04, -6.06968882e-04, -4.01920862e-02, -1.28762713e-02,
        3.82509222e-03,  1.68201290e-02,  2.86066663e-02,  2.55132839e-02,
        1.53290657e-02,  1.47925951e-02,  8.07582028e-03,  2.86964746e-03,
       -1.08785089e-02, -4.53233765e-03, -3.73841356e-03, -5.56930620e-03,
        5.91305690e-03, -4.11000196e-03, -5.45279868e-03, -1.76281741e-04,
       -8.56024027e-03, -5.84325520e-04,  7.25831510e-03,  1.36548793e-02,
        2.42781844e-02,  6.37822552e-03, -1.83432270e-02, -2.74016988e-02,
       -5.73926270e-02, -8.07848945e-02, -9.49636772e-02, -1.16835371e-01,
       -1.34597063e-01, -1.44888192e-01, -1.49487764e-01, -1.75604194e-01,
       -2.02419922e-01, -1.99895516e-01, -1.87883675e-01, -1.82030648e-01,
       -1.47759065e-01, -9.72567797e-02, -4.23409343e-02,  1.92453302e-02,
        7.39182606e-02,  1.35531604e-01,  1.92638367e-01,  2.51738310e-01,
        3.22105110e-01,  3.84768665e-01,  4.34173018e-01,  4.80880648e-01,
        5.23660719e-01,  5.38383663e-01,  5.02934873e-01,  3.85173708e-01,
        2.41622016e-01,  1.08509779e-01,  5.76855894e-03, -1.93713009e-01,
       -3.73276770e-01, -4.50103968e-01, -5.28263986e-01, -5.62702954e-01,
       -6.25185907e-01, -7.80293047e-01, -8.78775060e-01, -9.50143695e-01,
       -9.62434173e-01, -8.66784513e-01, -6.37653828e-01, -2.75426567e-01,
        1.38436094e-01,  4.77184594e-01,  6.84547067e-01,  7.63317883e-01,
        7.65211761e-01,  7.61436105e-01,  8.22463810e-01,  9.88621294e-01,
        1.11110651e+00,  1.08165801e+00,  1.19891429e+00,  1.35249972e+00,
        1.21630204e+00,  8.86056900e-01,  5.89023411e-01,  2.71931767e-01,
       -1.34423807e-01, -5.62174201e-01, -9.49381113e-01, -1.24134719e+00,
       -1.42080832e+00, -1.51698709e+00, -1.54414666e+00, -1.49505544e+00,
       -1.40910172e+00, -1.33117294e+00, -1.28838336e+00, -1.27369010e+00,
       -1.24042916e+00, -1.15553463e+00, -9.91003036e-01, -7.30008721e-01,
       -4.07007426e-01, -1.14110030e-01,  2.04047903e-01,  5.79413533e-01,
        8.90265226e-01,  1.04589009e+00,  1.21754396e+00,  1.39150560e+00,
        1.48176396e+00,  1.51911771e+00,  1.54842389e+00,  1.52859974e+00,
        1.41275001e+00,  1.20648956e+00,  9.83216226e-01,  7.88043082e-01,
        6.16401792e-01,  4.55417573e-01,  2.84299701e-01,  9.70719382e-02,
       -1.01042144e-01, -3.05567950e-01, -5.12466788e-01, -7.25013912e-01,
       -9.28849280e-01, -1.08330071e+00, -1.14712965e+00, -1.10676396e+00,
       -1.02904928e+00, -9.48207498e-01, -8.16501558e-01, -6.63494945e-01,
       -5.72623968e-01, -4.86964613e-01, -3.64110142e-01, -2.53840536e-01,
       -2.15187997e-01, -2.27862045e-01, -2.19602585e-01, -1.41162410e-01,
       -1.11017330e-02,  1.49674624e-01,  3.47189039e-01,  5.45849800e-01,
        6.38413191e-01,  6.04526103e-01,  4.83024776e-01,  2.76895851e-01,
        4.56610415e-03, -2.35512137e-01, -3.70209098e-01, -3.77080947e-01,
       -2.96519965e-01, -1.91713467e-01, -8.08480531e-02,  5.06298915e-02,
        1.68665245e-01,  2.05929250e-01,  1.69512674e-01,  1.31834298e-01,
        1.02510601e-02, -1.31629899e-01, -2.18174964e-01, -2.82780975e-01,
       -2.85973549e-01, -1.62379354e-01,  3.76093611e-02,  2.50497371e-01,
        4.22307312e-01,  4.96945143e-01,  4.76043224e-01,  3.83344233e-01,
        2.62479901e-01,  1.51369587e-01,  9.08361152e-02,  7.36510679e-02,
        6.44058809e-02,  1.22159794e-02, -1.04810998e-01, -2.61903703e-01,
       -4.53372031e-01, -7.00399935e-01, -9.77269411e-01, -1.19947720e+00,
       -1.45772028e+00, -1.67624545e+00, -1.77669430e+00, -1.81376195e+00,
       -1.85529125e+00, -1.82887459e+00, -1.68989933e+00, -1.50552523e+00,
       -1.26078606e+00, -8.87459815e-01, -4.90370780e-01, -1.84829414e-01,
        1.57338724e-01,  5.49064636e-01,  8.73487532e-01,  1.22102404e+00,
        1.63857055e+00,  1.98970139e+00,  2.31387115e+00,  2.66932893e+00,
        2.95126772e+00,  3.09109926e+00,  3.15937471e+00,  3.19080091e+00,
        3.12233400e+00,  2.90901470e+00,  2.54203987e+00,  2.10599184e+00,
        1.67169333e+00,  1.27340353e+00,  8.43351662e-01,  3.69736940e-01,
        1.44881960e-02, -2.45549440e-01, -5.28891325e-01, -7.88192034e-01,
       -9.89917696e-01, -1.18261611e+00, -1.38818252e+00, -1.50773335e+00,
       -1.52590203e+00, -1.48667002e+00, -1.39331496e+00, -1.24605179e+00,
       -1.03131759e+00, -7.50173390e-01, -4.22307819e-01, -7.94331133e-02,
        2.46314675e-01,  5.54818153e-01,  8.56619537e-01,  1.13204014e+00,
        1.34171510e+00,  1.45956862e+00,  1.52730143e+00,  1.49363923e+00,
        1.34554017e+00,  1.11398864e+00,  7.77502179e-01,  3.49480897e-01,
       -1.21304356e-01, -6.20055854e-01, -1.21481490e+00, -1.93639624e+00,
       -2.53444695e+00, -3.04545736e+00, -3.46774673e+00, -3.72144413e+00,
       -3.82625365e+00, -3.82445621e+00, -3.74022245e+00, -3.56510401e+00,
       -3.28203869e+00, -2.91092563e+00, -2.47766757e+00, -1.98267865e+00,
       -1.42667675e+00, -8.60062897e-01, -2.83353657e-01,  3.57686281e-01,
        1.01309133e+00,  1.57590926e+00,  2.06356788e+00,  2.50043392e+00,
        2.82137251e+00,  3.00943637e+00,  3.10595441e+00,  3.10069156e+00,
        2.96549988e+00,  2.70854616e+00,  2.33285284e+00,  1.82325840e+00,
        1.23858857e+00,  6.19892538e-01, -1.16454940e-02, -6.37294650e-01,
       -1.21202254e+00, -1.70298481e+00, -2.12194586e+00, -2.39357185e+00,
       -2.47201490e+00, -2.50738955e+00, -2.51826811e+00, -2.36719155e+00,
       -2.07731318e+00, -1.75272894e+00, -1.38570988e+00, -1.01179194e+00,
       -6.53656781e-01, -3.17566574e-01,  6.19923882e-02,  4.87385064e-01,
        9.08682704e-01,  1.36906242e+00,  1.85648954e+00,  2.26090312e+00,
        2.51208282e+00,  2.60064101e+00,  2.54939985e+00,  2.38342834e+00,
        2.14684939e+00,  1.84411430e+00,  1.48649788e+00,  1.12731540e+00,
        7.32199609e-01,  2.47317269e-01, -3.21979523e-01, -8.90056729e-01,
       -1.40010273e+00, -1.86636734e+00, -2.25310493e+00, -2.47961473e+00,
       -2.57604718e+00, -2.55046296e+00, -2.41358614e+00, -2.20817900e+00,
       -1.96226680e+00, -1.68095779e+00, -1.36625898e+00, -1.01692486e+00,
       -6.05994880e-01, -1.19002610e-01,  3.67497295e-01,  7.15950310e-01,
        1.07741392e+00,  1.41963458e+00,  1.61711395e+00,  1.80471551e+00,
        2.02032948e+00,  2.15630269e+00,  2.22629237e+00,  2.29670811e+00,
        2.26316237e+00,  2.04435825e+00,  1.80668855e+00,  1.49690771e+00,
        1.05398214e+00,  5.55190980e-01,  9.99235511e-02, -3.24511707e-01,
       -7.53561497e-01, -1.10479677e+00, -1.34067440e+00, -1.57331502e+00,
       -1.79431856e+00, -1.89747214e+00, -1.92477322e+00, -1.91203046e+00,
       -1.79835010e+00, -1.56361568e+00, -1.31736314e+00, -1.07033396e+00,
       -7.56883383e-01, -4.65486676e-01, -2.32782200e-01, -5.37060574e-02,
        1.02437697e-01,  2.48823538e-01,  4.00019795e-01,  5.73953509e-01,
        7.75729418e-01,  9.82720017e-01,  1.16664612e+00,  1.26129341e+00,
        1.24810100e+00,  1.21923959e+00,  1.17083490e+00,  1.04133546e+00,
        8.28296542e-01,  5.69611788e-01,  2.65149444e-01, -1.00228921e-01,
       -4.14163053e-01, -6.35940313e-01, -7.89672256e-01, -8.01085591e-01,
       -7.22060204e-01, -6.11379445e-01, -4.87929434e-01, -3.73337299e-01,
       -2.58237332e-01, -1.56854361e-01, -7.43156970e-02, -5.83826052e-03,
        3.32737304e-02,  7.74446949e-02,  1.31101757e-01,  1.54904112e-01,
        1.71772033e-01,  2.01940805e-01,  1.83089763e-01,  5.07717915e-02,
       -1.07302540e-03, -4.91363071e-02, -7.48551860e-02, -7.73526803e-02,
       -5.68617098e-02, -3.15909710e-04,  5.55601753e-02,  6.89629391e-02,
        5.03899194e-02, -6.32004114e-03, -5.68335578e-02, -4.52937149e-02,
       -1.23775899e-01, -1.62133664e-01, -1.10467643e-01, -7.53426626e-02,
        7.09213223e-03,  1.16451092e-01,  2.10931376e-01,  2.67004102e-01,
        2.76561707e-01,  2.50355750e-01,  2.04919711e-01,  1.93684921e-01,
        2.08498493e-01,  1.85637355e-01,  1.36314005e-01,  7.70039111e-02,
       -5.27664386e-02, -1.72255903e-01, -2.44105652e-01, -2.99460620e-01,
       -3.09403718e-01, -3.12633336e-01, -2.97435135e-01, -2.21129596e-01,
       -1.61962196e-01, -7.78408945e-02,  5.38219325e-02,  1.54060528e-01,
        2.24279329e-01,  2.20080107e-01,  1.78476542e-01,  8.97173733e-02,
       -1.68063790e-02, -8.70990604e-02, -1.36875167e-01, -1.34018123e-01,
       -7.88413659e-02, -4.61471789e-02,  1.66015048e-02,  8.00568163e-02,
        3.32705937e-02,  9.05398093e-03,  1.37869641e-02, -3.42847481e-02,
       -2.44308412e-02,  2.04163752e-02,  3.02908216e-02,  4.10473235e-02,
       -1.38345035e-02, -3.55427600e-02, -9.50495377e-02, -1.40914500e-01,
       -1.27734885e-01, -5.59428036e-02,  4.11427431e-02,  1.34193957e-01,
        2.44364500e-01,  3.61923039e-01,  4.15859938e-01,  3.94630462e-01,
        3.33815843e-01,  2.20222846e-01,  6.87984377e-02, -7.12430477e-02,
       -2.20279276e-01, -3.67711276e-01, -4.42990005e-01, -5.07793903e-01,
       -6.00807726e-01, -7.25455165e-01, -8.82013440e-01, -1.03851628e+00,
       -1.15417230e+00, -1.20359230e+00, -1.15742481e+00, -1.04076505e+00,
       -8.47518623e-01, -6.09025717e-01, -3.55660737e-01, -9.60073024e-02,
        1.75483823e-01,  4.31372911e-01,  6.47693634e-01,  8.26936364e-01,
        9.99794006e-01,  1.16691816e+00,  1.30673385e+00,  1.39992666e+00,
        1.43623137e+00,  1.47355556e+00,  1.51741159e+00,  1.49222231e+00,
        1.40276802e+00,  1.21455169e+00,  9.48219836e-01,  5.77777863e-01,
        1.58622980e-01, -2.40057617e-01, -6.39255345e-01, -1.00976360e+00,
       -1.31170535e+00, -1.54115951e+00, -1.70582092e+00, -1.81418490e+00,
       -1.88488972e+00, -1.91081667e+00, -1.88410139e+00, -1.82031250e+00,
       -1.72197378e+00, -1.57664382e+00, -1.37616754e+00, -1.13145685e+00,
       -8.53825212e-01, -5.45318246e-01, -1.91999406e-01,  1.59188583e-01,
        4.67471808e-01,  7.59615600e-01,  1.00099885e+00,  1.20365465e+00,
        1.37522590e+00,  1.46788669e+00,  1.53539920e+00,  1.56103623e+00,
        1.52283525e+00,  1.41872859e+00,  1.26882708e+00,  1.07406378e+00,
        8.48789752e-01,  5.97140491e-01,  3.11810315e-01,  1.33288177e-02,
       -2.85534441e-01, -5.74481189e-01, -8.33227575e-01, -1.04296434e+00,
       -1.18420994e+00, -1.24330401e+00, -1.20505321e+00, -1.08415449e+00,
       -8.84320855e-01, -6.27376020e-01, -3.44088644e-01, -5.60351796e-02,
        2.18366832e-01,  4.65339541e-01,  7.11172581e-01,  9.35800493e-01,
        1.12421012e+00,  1.29465950e+00,  1.44001532e+00,  1.53924930e+00,
        1.58734596e+00,  1.54589939e+00,  1.44008636e+00,  1.28359532e+00,
        1.02569854e+00,  6.98175073e-01,  2.88938910e-01, -9.70881805e-02,
       -5.05066931e-01, -8.06600571e-01, -1.10329819e+00, -1.36346412e+00,
       -1.53830171e+00, -1.64632249e+00, -1.68551481e+00, -1.64084983e+00,
       -1.53451014e+00, -1.38157928e+00, -1.17834485e+00, -9.58235502e-01,
       -6.93331957e-01, -4.13440764e-01, -1.38508677e-01,  1.45588666e-01,
        4.29860324e-01,  7.02747524e-01,  9.51105356e-01,  1.16440475e+00,
        1.27613342e+00,  1.28447521e+00,  1.19513476e+00,  1.02643323e+00,
        8.15147519e-01,  5.60124755e-01,  2.83055544e-01,  4.73789498e-02,
       -1.61798567e-01, -3.29674482e-01, -4.59952474e-01, -5.73682368e-01,
       -6.64355636e-01, -7.25208521e-01, -7.72547543e-01, -8.02047551e-01,
       -7.98152685e-01, -7.65221715e-01, -6.80751801e-01, -5.63037813e-01,
       -4.20280278e-01, -2.31650904e-01, -3.16687636e-02,  1.42735541e-01,
        2.96279877e-01,  4.38909203e-01,  5.56080818e-01,  6.26416922e-01,
        6.50799155e-01,  6.53296053e-01,  6.44559324e-01,  5.75389624e-01,
        4.67649698e-01,  3.72260332e-01,  2.85796851e-01,  1.60470381e-01,
       -3.06902500e-03, -1.40714124e-01, -3.11972082e-01, -5.08472025e-01,
       -6.74280405e-01, -7.77248383e-01, -8.27880979e-01, -8.12107325e-01,
       -6.78173065e-01, -5.22812724e-01, -4.19470221e-01, -2.24701241e-01,
       -5.03040068e-02,  1.09527901e-01,  2.87783802e-01,  4.61575300e-01,
        6.05723381e-01,  6.64377511e-01,  8.01412582e-01,  9.54183936e-01,
        9.71082032e-01,  9.73339260e-01,  1.01403010e+00,  9.82000887e-01,
        8.92969728e-01,  7.96825826e-01,  6.27066672e-01,  3.97990942e-01,
        1.63646996e-01, -6.43091872e-02, -2.85331905e-01, -4.91543263e-01,
       -6.57235980e-01, -8.02491128e-01, -9.39807236e-01, -1.03243315e+00,
       -1.06578505e+00, -1.05708146e+00, -1.02521861e+00, -9.25996304e-01,
       -7.69977748e-01, -6.05790913e-01, -4.31087404e-01, -2.17856303e-01,
        2.69079655e-02,  2.69192308e-01,  4.69132066e-01,  6.37887537e-01,
        8.07246566e-01,  9.50095057e-01,  1.02143669e+00,  1.02938235e+00,
        9.78116095e-01,  9.28064883e-01,  8.80380511e-01,  8.31371605e-01,
        7.79034555e-01,  7.22629607e-01,  6.21848226e-01,  4.62378114e-01,
        2.81544268e-01,  7.52248690e-02, -1.58551812e-01, -3.64582956e-01,
       -5.48303604e-01, -6.94054186e-01, -7.68910289e-01, -8.36295128e-01,
       -8.63868952e-01, -8.41247201e-01, -7.87071109e-01, -7.27394879e-01,
       -6.36141717e-01, -5.01204371e-01, -3.72726232e-01, -2.54609019e-01,
       -4.97969761e-02,  1.67990118e-01,  3.34562480e-01,  4.76490408e-01,
        6.13931715e-01,  7.12325454e-01,  7.38761902e-01,  7.06552148e-01,
        6.80778086e-01,  6.27250850e-01,  5.18113196e-01,  4.22327578e-01,
        3.26330572e-01,  1.90669879e-01,  1.95788741e-02, -1.12541109e-01,
       -2.23670974e-01, -3.30700815e-01, -4.44432735e-01, -5.50559819e-01,
       -6.13108456e-01, -6.51071072e-01, -6.94574416e-01, -6.85673177e-01,
       -6.39736056e-01, -5.81957757e-01, -4.77931082e-01, -3.29677999e-01,
       -1.69756338e-01,  1.65623296e-02,  2.05313995e-01,  3.64290476e-01,
        5.07525384e-01,  6.31611943e-01,  6.99240088e-01,  7.29641438e-01,
        7.32237995e-01,  6.63395941e-01,  6.31704152e-01,  5.49274564e-01,
        4.74258006e-01,  3.81890059e-01,  2.71796316e-01,  1.89258352e-01,
        1.00891076e-01, -4.38743457e-03, -1.07079431e-01, -2.33237892e-01,
       -3.56604785e-01, -5.16739547e-01, -6.41735673e-01, -7.58243382e-01,
       -8.24719250e-01, -8.16290081e-01, -8.02064776e-01, -7.48222709e-01,
       -6.44630551e-01, -5.49039960e-01, -4.49504972e-01, -3.32953483e-01,
       -2.06642151e-01, -6.01459108e-02,  1.04985073e-01,  2.77861536e-01,
        4.45277244e-01,  5.95952272e-01,  7.13451505e-01,  8.01823378e-01,
        8.57108414e-01,  8.63041997e-01,  8.09952438e-01,  7.40030050e-01,
        6.53830707e-01,  5.06907344e-01,  3.28878015e-01,  1.90350667e-01,
        5.18254898e-02, -7.96547532e-02, -1.97032019e-01, -3.22388649e-01,
       -4.36735868e-01, -5.17589271e-01, -5.93825519e-01, -6.73479080e-01,
       -7.25198746e-01, -7.60953665e-01, -7.99067438e-01, -7.96873808e-01,
       -7.97069132e-01, -7.60399401e-01, -6.51803255e-01, -5.46804667e-01,
       -4.25559759e-01, -2.50871450e-01, -1.13467060e-01,  9.88437096e-04,
        1.15188792e-01,  1.64194778e-01,  2.21499324e-01,  2.86958337e-01,
        3.52881789e-01,  4.22972918e-01,  4.70523834e-01,  5.31172037e-01,
        6.48533940e-01,  7.12004721e-01,  7.41702020e-01,  7.43088663e-01,
        7.42393851e-01,  7.15978503e-01,  6.79985046e-01,  6.30769432e-01,
        5.64854801e-01,  4.63549882e-01,  3.63143682e-01,  2.45593071e-01,
        1.17442392e-01, -2.84566395e-02, -2.14554057e-01, -3.50286722e-01,
       -5.06073475e-01, -6.53976023e-01, -7.29685426e-01, -7.94380367e-01,
       -7.95888126e-01, -7.44564712e-01, -6.51210964e-01, -5.12699246e-01,
       -3.43152553e-01, -1.46255031e-01,  3.83677930e-02,  1.99921325e-01,
        3.71442199e-01,  4.92966235e-01,  5.90364218e-01,  7.00584173e-01,
        7.62622893e-01,  8.01647842e-01,  8.55128706e-01,  9.13229167e-01,
        9.31114376e-01,  9.24056053e-01,  8.49886417e-01,  7.33273208e-01,
        5.76611757e-01,  3.39150339e-01,  9.15868208e-02, -1.30790651e-01,
       -3.33248854e-01, -5.19730806e-01, -6.77058578e-01, -7.88649082e-01,
       -8.93034101e-01, -9.91404951e-01, -1.05515790e+00, -1.08294332e+00,
       -1.06994104e+00, -1.01140809e+00, -9.12790537e-01, -7.74160206e-01,
       -5.64856768e-01, -3.44903618e-01, -1.07372403e-01,  1.15868725e-01,
        3.41777593e-01,  5.45771658e-01,  7.08119273e-01,  8.37473750e-01,
        9.32640433e-01,  9.99404192e-01,  1.07840466e+00,  1.09263241e+00,
        1.09413159e+00,  1.08693182e+00,  1.04604530e+00,  9.62093353e-01,
        8.87290001e-01,  7.56292939e-01,  5.37600517e-01,  3.66854072e-01,
        1.55281812e-01, -9.65992883e-02, -3.18472952e-01, -5.09754360e-01,
       -7.31595635e-01, -8.63854051e-01, -9.53424633e-01, -9.92916107e-01,
       -9.67656910e-01, -9.04961348e-01, -8.18558455e-01, -6.88515306e-01,
       -5.86893916e-01, -4.57126975e-01, -3.16238999e-01, -1.49053872e-01,
        2.10913792e-02,  1.58604339e-01,  3.10203135e-01,  4.56215590e-01,
        5.81928432e-01,  6.53617561e-01,  7.05457926e-01,  7.46800065e-01,
        7.47853458e-01,  7.19600439e-01,  6.70456886e-01,  5.90317190e-01,
        5.16784370e-01,  4.33190972e-01,  3.32293391e-01,  2.26598099e-01,
        1.43966943e-01,  6.20187111e-02, -3.91717032e-02, -1.31062865e-01,
       -2.29868174e-01, -3.28523278e-01, -3.85429591e-01, -4.36791301e-01,
       -4.91843045e-01, -5.05998433e-01, -4.83699322e-01, -4.57246184e-01,
       -4.25606668e-01, -3.72417659e-01, -3.10692459e-01, -2.46234462e-01,
       -1.74061015e-01, -9.68265906e-02, -3.88200618e-02,  5.61898313e-02,
        1.37441128e-01,  1.86226532e-01,  2.34807149e-01,  2.65417904e-01,
        2.79870600e-01,  2.99319148e-01,  3.28898489e-01,  3.51963609e-01,
        3.38124931e-01,  3.34003448e-01,  3.42653990e-01,  3.40951651e-01,
        3.09643686e-01,  2.54878074e-01,  2.00003654e-01,  1.51090160e-01};

unsigned int inference_time[NUM_SAMPLES] = {};
unsigned int inference_index = 0;
unsigned int min_inference_time = 0xFFFFFFFF;
unsigned int max_inference_time = 0;
float mean_inference_time = 0;
float std_inference_time = 0;

void CalculateInferenceStandardDeviation()
{
    unsigned int sum = 0;
    float mean = 0;
    float std = 0;
    for (int i = 0; i < NUM_SAMPLES; i++)
    {
        sum += inference_time[i];
    }
    mean = float(sum) / NUM_SAMPLES;
    mean_inference_time = mean;
    for (int i = 0; i < NUM_SAMPLES; i++)
    {
        std += (inference_time[i] - mean) * (inference_time[i] - mean);
    }
    std = std / NUM_SAMPLES;
    std_inference_time = sqrt(std);
}

void CalculateMaxMinInferenceTime()
{
    for (int i = 0; i < NUM_SAMPLES; i++)
    {
        if (inference_time[i] < min_inference_time)
        {
            min_inference_time = inference_time[i];
        }
        if (inference_time[i] > max_inference_time)
        {
            max_inference_time = inference_time[i];
        }
    }
}

void setup()
{
  Serial.begin(9600);
  // Set up logging. Google style is to avoid globals or statics because of
  // lifetime uncertainty, but since this has a trivial destructor it's okay.
  // NOLINTNEXTLINE(runtime-global-variables)
  static tflite::MicroErrorReporter micro_error_reporter;
  error_reporter = &micro_error_reporter;
  // Map the model into a usable data structure. This doesn't involve any
  // copying or parsing, it's a very lightweight operation.
  #if DENSE_MODEL
    model = tflite::GetModel(dense_model_tflite);
  #endif
  
  #if DENSE_MODEL_OPTIMIZED
    model = tflite::GetModel(dense_model_optimized_tflite);
  #endif
  
  #if CUSTOM_CONV_MODEL
    model = tflite::GetModel(my_custom_model_tflite);
  #endif
  
  #if CUSTOM_CONV_MODEL_OPTIMIZED
    model = tflite::GetModel(my_custom_model_optimized_tflite);
  #endif
  
  #if CONV_MODEL_PAPER
    model = tflite::GetModel(conv_model_paper_tflite);
  #endif

  #if CONV_MODEL_PAPER_2D
    model = tflite::GetModel(conv_model_paper_2D_tflite);
  #endif
  
  #if CONV_MODEL_PAPER_2D_OPTIMIZED
    model = tflite::GetModel(conv_model_paper_2D_optimized_tflite);
  #endif



  if (model->version() != TFLITE_SCHEMA_VERSION)
  {
    TF_LITE_REPORT_ERROR(error_reporter,
                         "Model provided is schema version %d not equal "
                         "to supported version %d.",
                         model->version(), TFLITE_SCHEMA_VERSION);
    error_code = kVersionError;
    return;
  }
  Serial.print("Standalone inferencing (BLE 33 Nano)\n");


  #if DENSE_MODEL && !ALL_OPS_RESOLVER
    static tflite::MicroMutableOpResolver<4> micro_op_resolver;
    micro_op_resolver.AddReshape();
    micro_op_resolver.AddFullyConnected();
    micro_op_resolver.AddElu();
    micro_op_resolver.AddSoftmax();
  #endif
  #if DENSE_MODEL_OPTIMIZED
  static tflite::MicroMutableOpResolver<6> micro_op_resolver;
  micro_op_resolver.AddQuantize();
  micro_op_resolver.AddReshape();
  micro_op_resolver.AddFullyConnected();
  micro_op_resolver.AddElu();
  micro_op_resolver.AddDequantize();
  micro_op_resolver.AddSoftmax();
#endif
#if CUSTOM_CONV_MODEL
  static tflite::MicroMutableOpResolver<8> micro_op_resolver;
  micro_op_resolver.AddShape();
  micro_op_resolver.AddStridedSlice();
  micro_op_resolver.AddPack();
  micro_op_resolver.AddReshape();
  micro_op_resolver.AddConv2D();
  micro_op_resolver.AddMaxPool2D();
  micro_op_resolver.AddFullyConnected();
  micro_op_resolver.AddSoftmax();
#endif 

#if CUSTOM_CONV_MODEL_OPTIMIZED
  static tflite::MicroMutableOpResolver<10> micro_op_resolver;
  micro_op_resolver.AddQuantize();
  micro_op_resolver.AddShape();
  micro_op_resolver.AddStridedSlice();
  micro_op_resolver.AddPack();
  micro_op_resolver.AddReshape();
  micro_op_resolver.AddConv2D();
  micro_op_resolver.AddMaxPool2D();
  micro_op_resolver.AddFullyConnected();
  micro_op_resolver.AddSoftmax();
  micro_op_resolver.AddDequantize();
#endif
#if CONV_MODEL_PAPER_2D
  static tflite::MicroMutableOpResolver<8> micro_op_resolver;
  micro_op_resolver.AddShape();
  micro_op_resolver.AddStridedSlice();
  micro_op_resolver.AddPack();
  micro_op_resolver.AddReshape();
  micro_op_resolver.AddConv2D();
  micro_op_resolver.AddMaxPool2D();
  micro_op_resolver.AddFullyConnected();
  micro_op_resolver.AddSoftmax();
#endif
#if CONV_MODEL_PAPER_2D_OPTIMIZED
  static tflite::MicroMutableOpResolver<10> micro_op_resolver;
  micro_op_resolver.AddQuantize();
  micro_op_resolver.AddShape();
  micro_op_resolver.AddStridedSlice();
  micro_op_resolver.AddPack();
  micro_op_resolver.AddReshape();
  micro_op_resolver.AddConv2D();
  micro_op_resolver.AddMaxPool2D();
  micro_op_resolver.AddFullyConnected();
  micro_op_resolver.AddSoftmax();
  micro_op_resolver.AddDequantize();

#endif
#if  CONV_MODEL_PAPER ||  ALL_OPS_RESOLVER
  static tflite::AllOpsResolver micro_op_resolver;
#endif

  Serial.print("Resolver assigned\n");

  // Build an interpreter to run the model with.
  static tflite::MicroInterpreter static_interpreter(
      model, micro_op_resolver, tensor_arena, kTensorArenaSize);
  interpreter = &static_interpreter;
  Serial.print("Static interpreter assigned\n");

  // Allocate memory from the tensor_arena for the model's tensors.
  TfLiteStatus allocate_status = interpreter->AllocateTensors();
  if (allocate_status != kTfLiteOk)
  {
    TF_LITE_REPORT_ERROR(error_reporter, "AllocateTensors() failed");
    error_code = kTensorAllocationError;
    return;
  }
  Serial.print("Tensor allocation is done\n");

  // Get information about the memory area to use for the model's input.
  model_input = interpreter->input(0);
if ((model_input->dims->size != 2) || (model_input->dims->data[0] != 1) ||
      (model_input->dims->data[1] !=1000) ||
      (model_input->type != kTfLiteFloat32)) {
    TF_LITE_REPORT_ERROR(error_reporter,
                         "Bad input tensor parameters in model");
    error_code = kInputTensorError;
    return;
  }
  Serial.print("Model input assigned\n");
  for(int i = 0; i < 1000; i++) {
     model_input->data.f[i] = example_signal[i];
   }
//  model_input->data.f = example_signal;
  output = interpreter->output(0);

  Serial.print("Model output assigned\n");

}

void loop()
{
   for(int i = 0; i < 1000; i++) {
     model_input->data.f[i] = example_signal[i];
   }
  if(error_code != kNoError) {
    Serial.print("Error code:");
    Serial.println(error_code);
    delay( 1000 );
    return;
  }
  unsigned int t1 = micros();
  TfLiteStatus invoke_status = interpreter->Invoke();
  if (invoke_status != kTfLiteOk)
  {
    TF_LITE_REPORT_ERROR(error_reporter, "Invoke failed");
    error_code = kInvokeError;
    return;
  }
  unsigned int t2 = micros();
  if(inference_index!=NUM_SAMPLES){
    inference_time[inference_index] = t2-t1;
    inference_index++;
  }else{
    CalculateInferenceStandardDeviation();
    CalculateMaxMinInferenceTime();
    Serial.print("Average inference time : "); Serial.print(mean_inference_time); Serial.println(" microseconds");
    Serial.print("STD of inference time  : "); Serial.print(std_inference_time); Serial.println(" microseconds");
    Serial.print("Max inference time     : "); Serial.print(max_inference_time); Serial.println(" microseconds");
    Serial.print("Min inference time     : "); Serial.print(min_inference_time); Serial.println(" microseconds");
    Serial.print(interpreter->arena_used_bytes(),DEC);  
    Serial.println(" bytes used.");
    Serial.print("Recognized val_0 = ");
    Serial.println(output->data.f[0],4);
    Serial.print("Recognized val_1 = ");
    Serial.println(output->data.f[1],4);
    Serial.print("Recognized val_2 =");
    Serial.println(output->data.f[2],4);
    inference_index = 0;
    max_inference_time = 0;
    min_inference_time = 0xFFFFFFFF;
    mean_inference_time = 0;
    std_inference_time = 0;
  }

}
