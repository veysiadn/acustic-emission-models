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

===========================
**TFLite model size:**
Unoptimized : 18412 Bytes
Optimized : 6496 Bytes
===========================

===================================================================
**Dense Model Deployment Arduino Nano BLE 33**

**All ops resolver**
Sketch uses `379544 bytes (38%)` of program storage space. Maximum is 983040 bytes.
Global variables use `68672 bytes (26%)` of dynamic memory, leaving 193472 bytes for local variables. Maximum is 262144 bytes.

**Micro_op_resolver**
Sketch uses **177280 bytes (18%)** of program storage space. Maximum is 983040 bytes.
Global variables use **63168 bytes (24%)** of dynamic memory, leaving 198976 bytes for local variables. Maximum is 262144 bytes.

tensor_arena_size = `8864`
Average inference time: `9778.27 us` (10k samples)
=======================================================================
**Dense model optimized deployment Arduino Nano BLE 33**

**All ops resolver**
Sketch uses `367624 bytes (37%)` of program storage space. Maximum is 983040 bytes.
Global variables use `68672 bytes (26%)` of dynamic memory, leaving 193472 bytes for local variables. Maximum is 262144 bytes.

**Micro_op_resolver**
Sketch uses `165360 bytes (16%) `of program storage space. Maximum is 983040 bytes.
Global variables use `63176 bytes (24%)` of dynamic memory, leaving 198968 bytes for local variables. Maximum is 262144 bytes.

tensor_arena_size = `8864`
Average inference time: `8569.34 us` (10k samples)
========================================================================
