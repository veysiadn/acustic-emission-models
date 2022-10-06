### Model: "custom_2D_conv_model"
_________________________________________________________________
 Layer (type)                Output Shape              Param #   
=================================================================

 Reshape (Reshape)           (None, 1000, 1, 1)        0         
                                                                 
 conv2d_14 (Conv2D)          (None, 1000, 1, 8)        208       
                                                                 
 max_pooling2d_18 (MaxPoolin  (None, 500, 1, 8)        0         
 g2D)                                                            
                                                                 
 flatten_19 (Flatten)        (None, 4000)              0         
                                                                 
 output (Dense)              (None, 3)                 12003     
                                                                 
=================================================================

Total params: 12,211
Trainable params: 12,211
Non-trainable params: 0
_________________________________________________________________

**Training results**
Training Accuracy: 0.9974166750907898
Training Loss: 0.012660179287195206
_________________________________________________________________

**Evaluation results**
Validation Accuracy: 0.9886666536331177
Validation Loss: 0.05800541117787361
_________________________________________________________________

Unoptimized custom_conv_model TFLite test_accuracy: 0.9886666666666667
Optimized custom_conv_model TFLite test_accuracy: 0.988
_________________________________________________________________

TFLite model size:
===========================
Unoptimized : 52432 Bytes
Optimized : 16712 Bytes

========================================================================================================================
## DEPLOYMENTS ##
========================================================================================================================
**Dense Model Deployment Arduino Nano BLE 33**

**All ops resolver**
Sketch uses `379544 bytes (38%)` of program storage space. Maximum is 983040 bytes.
Global variables use `68672 bytes (26%)` of dynamic memory, leaving 193472 bytes for local variables. Maximum is 262144 bytes.

**Micro_op_resolver**
Sketch uses `177472 bytes (18%)` of program storage space. Maximum is 983040 bytes.
Global variables use `63176 bytes (24%)` of dynamic memory, leaving 198968 bytes for local variables. Maximum is 262144 bytes.

tensor_arena_size = `8868 bytes`
Average inference time: `993.27 us` (10k samples)
========================================================================================================================
**Dense model `Optimized` deployment Arduino Nano BLE 33**

**All ops resolver**
Sketch uses `367624 bytes (37%)` of program storage space. Maximum is 983040 bytes.
Global variables use `68672 bytes (26%)` of dynamic memory, leaving 193472 bytes for local variables. Maximum is 262144 bytes.

**Micro_op_resolver**
Sketch uses `169328 bytes (17%)` of program storage space. Maximum is 983040 bytes.
Global variables use `60440 bytes (23%)` of dynamic memory, leaving 201704 bytes for local variables. Maximum is 262144 bytes.
### REMARK: Optimized model adds to more layers, namely Quantize and Dequantize layers for that reasons inference time is slowed down by 2.8 times.
tensor_arena_size = `6040 bytes`
Average inference time: `2801.10 us` (10k samples)
========================================================================================================================

========================================================================================================================
**Dense Model Deployment STM Nucleo L432KC**

**All ops resolver**
Sketch uses `207052 bytes (78%)` of program storage space. Maximum is 262144 bytes.
Global variables use `22892 bytes (34%)` of dynamic memory, leaving 42644 bytes for local variables. Maximum is 65536 bytes.
R

**Micro_op_resolver**
Sketch uses `77692 bytes (29%)` of program storage space. Maximum is 262144 bytes.
Global variables use `18308 bytes (27%)` of dynamic memory, leaving 47228 bytes for local variables. Maximum is 65536 bytes.


tensor_arena_size = `8828`
Average inference time : `1412.28 microseconds` (10k samples)
STD of inference time  : `0.79 microseconds`
Max inference time     : `1425 microseconds`
Min inference time     : `1411 microseconds`


========================================================================================================================
**Dense Model `Optimized` Deployment STM Nucleo L432KC**

**Micro_op_resolver**
Sketch uses `68908 bytes (26%)` of program storage space. Maximum is 262144 bytes.
Global variables use `15548 bytes (23%)` of dynamic memory, leaving 49988 bytes for local variables. Maximum is 65536 bytes.

tensor_arena_size = `5996`
Average inference time : `2214.97 microseconds` (10k samples)
STD of inference time  : `0.72 microseconds`
Max inference time     : `2238 microseconds`
Min inference time     : `2214 microseconds`

======================================================================================================================

======================================================================================================================
**Dense Model Deployment Seeduino Xiao**

**All ops resolver**
Sketch uses `232372 bytes (88%)` of program storage space. Maximum is 262144 bytes.
## GLOBAL VARIABLE MEMORY USAGE WASN'T SHOWN IN THE COMPILER OUTPUT

**Micro_op_resolver**
Sketch uses `98028 bytes (37%)` of program storage space. Maximum is 262144 bytes.
## GLOBAL VARIABLE MEMORY USAGE WASN'T SHOWN IN THE COMPILER OUTPUT

tensor_arena_size = `8828`
Average inference time : `32160.86 microseconds` (10k samples)
STD of inference time  : `2.08 microseconds`
Max inference time     : `32172 microseconds`
Min inference time     : `32154 microseconds`
========================================================================================================================

**Dense Model `Optimized` Deployment Seeduino Xiao**

**All ops resolver**
Sketch uses `220452 bytes (84%)` of program storage space. Maximum is 262144 bytes.
## GLOBAL VARIABLE MEMORY USAGE WASN'T SHOWN IN THE COMPILER OUTPUT

**Micro_op_resolver**
Sketch uses `86116 bytes (32%)` of program storage space. Maximum is 262144 bytes.
## GLOBAL VARIABLE MEMORY USAGE WASN'T SHOWN IN THE COMPILER OUTPUT

tensor_arena_size = `6000`
Average inference time : `20384.15 microseconds` (10k samples)
STD of inference time  : `2.72 microseconds`
Max inference time     : `20392 microseconds`
Min inference time     : `20378 microseconds`


========================================================================================================================

======================================================================================================================
**Dense Model Deployment Nucleo F401RE**

**Micro_op_resolver**
Sketch uses `74548 bytes (14%)` of program storage space. Maximum is 524288 bytes.
Global variables use `18240 bytes (18%)` of dynamic memory, leaving 80064 bytes for local variables. Maximum is 98304 bytes.


tensor_arena_size = `8816 bytes`
Average inference time : `1251.34 microseconds` (10k samples)
STD of inference time  : `0.48 microseconds`
Max inference time     : `1258 microseconds`
Min inference time     : `1251 microseconds`

========================================================================================================================

**Dense Model `Optimized` Deployment Nucleo F401RE**

**Micro_op_resolver**
Sketch uses `65756 bytes (12%)` of program storage space. Maximum is 524288 bytes.
Global variables use `18312 bytes (18%)` of dynamic memory, leaving 79992 bytes for local variables. Maximum is 98304 bytes.


tensor_arena_size = `6000`
Average inference time : `2037.93 microseconds` (10k samples)
STD of inference time  : `0.71 microseconds`
Max inference time     : `2044 microseconds`
Min inference time     : `2037 microseconds`

========================================================================================================================
======================================================================================================================
**Dense Model Deployment Raspberry Pi Pico**

**COULDN'T RUN MODEL ON PICO, INVOCATION ERROR OCCURS**

========================================================================================================================

**Dense Model `Optimized` Deployment Raspberry Pi Pico**

**COULDN'T RUN MODEL ON PICO, INVOCATION ERROR OCCURS**

========================================================================================================================

======================================================================================================================
**Dense Model Deployment ESP-32S -NodeMCU v1.3**

**Micro_op_resolver**
Total sizes:
Used static DRAM:   72572 bytes ( 108164 remain, 40.2% used)
      .data size:   14404 bytes
      .bss  size:   58168 bytes
Used static IRAM:   43818 bytes (  87254 remain, 33.4% used)
      .text size:   42791 bytes
   .vectors size:    1027 bytes
Used Flash size :  237535 bytes
      .text     :  141647 bytes
      .rodata   :   95632 bytes
Total image size:  295757 bytes (.bin may be padded larger)

tensor_arena_size = `49284 bytes`
Average inference time : `47669.9648 microseconds.`
STD of inference time  : `5.0980 microseconds.`
Max inference time     : `47676 microseconds`
Min inference time     : `47621 microseconds`

========================================================================================================================

**My Custom Conv Model `Optimized` ESP-32S -NodeMCU v1.3**

**Micro_op_resolver**
Used static DRAM:   35796 bytes ( 144940 remain, 19.8% used)
      .data size:   14404 bytes
      .bss  size:   21392 bytes
Used static IRAM:   43818 bytes (  87254 remain, 33.4% used)
      .text size:   42791 bytes
   .vectors size:    1027 bytes
Used Flash size :  209195 bytes
      .text     :  148187 bytes
      .rodata   :   60752 bytes
Total image size:  267417 bytes (.bin may be padded larger)


tensor_arena_size = `13452`
Average inference time : `22744.2129 microseconds.`
STD of inference time  : `19.7841 microseconds.`
Max inference time     : `23351 microseconds`
Min inference time     : `22738 microseconds`

========================================================================================================================
