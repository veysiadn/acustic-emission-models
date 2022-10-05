Model: "dense_model"
_________________________________________________________________
 Layer (type)                Output Shape              Param #   
=================================================================
 flatten_20 (Flatten)        (None, 1000)              0         
                                                                 
 dense_49 (Dense)            (None, 4)                 4004      
                                                                 
 dense_50 (Dense)            (None, 3)                 15        
                                                                 
=================================================================
Total params: 4,019
Trainable params: 4,019
Non-trainable params: 0
_________________________________________________________________

Training results
Training Accuracy: 0.9957500100135803
Training Loss: 0.026185650378465652
_________________________________________________________________

Evaluation results
Validation Accuracy: 0.9773333072662354
Validation Loss: 0.14419926702976227
_________________________________________________________________

Unoptimized dense_model TFLite test_accuracy: 0.9686666666666667
Optimized dense_model TFLite test_accuracy: 0.9686666666666667
_________________________________________________________________

TFLite model size:
===========================
Unoptimized : 18412 Bytes
Optimized : 6496 Bytes
