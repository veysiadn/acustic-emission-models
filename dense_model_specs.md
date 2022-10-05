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
## Remark : Optimized model should be completely quantized otherwise it is giving NaN output values.
===========================

===================================================================
**Dense Model Deployment Arduino Nano BLE 33**

**All ops resolver**
Sketch uses `379544 bytes (38%)` of program storage space. Maximum is 983040 bytes.
Global variables use `68672 bytes (26%)` of dynamic memory, leaving 193472 bytes for local variables. Maximum is 262144 bytes.

**Micro_op_resolver**
Sketch uses `177280 bytes (18%)` of program storage space. Maximum is 983040 bytes.
Global variables use `63168 bytes (24%)` of dynamic memory, leaving 198976 bytes for local variables. Maximum is 262144 bytes.

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
Average inference time: `856.34 us` (10k samples)
========================================================================

========================================================================
**Dense Model Deployment STM Nucleo L432KC**

**All ops resolver**
Sketch uses `206916 bytes (78%)` of program storage space. Maximum is 262144 bytes.
Global variables use `22884 bytes (34%)` of dynamic memory, leaving 42652 bytes for local variables. Maximum is 65536 bytes.


**Micro_op_resolver**
Sketch uses `77556 bytes (29%)` of program storage space. Maximum is 262144 bytes.
Global variables use `18300 bytes (27%)` of dynamic memory, leaving 47236 bytes for local variables. Maximum is 65536 bytes.

tensor_arena_size = `8824`
Average inference time: `1412.45 us` (10k samples)
=======================================================================
========================================================================
**Dense Model `Optimized` Deployment STM Nucleo L432KC**

**Micro_op_resolver**
Sketch uses `65836 bytes (25%)` of program storage space. Maximum is 262144 bytes.
Global variables use `18308 bytes (27%)` of dynamic memory, leaving 47228 bytes for local variables. Maximum is 65536 bytes.


tensor_arena_size = `8824`
Average inference time: `1412.45 us` (10k samples)
=======================================================================


========================================================================
**Dense Model Deployment Seeduino Xiao**

**All ops resolver**
Sketch uses `232372 bytes (88%)` of program storage space. Maximum is 262144 bytes.
## GLOBAL VARIABLE MEMORY USAGE WASN'T SHOWN IN THE COMPILER OUTPUT
#### Note after uploading remove the USB and reconnect.

**Micro_op_resolver**
Sketch uses `98028 bytes (37%)` of program storage space. Maximum is 262144 bytes.
## GLOBAL VARIABLE MEMORY USAGE WASN'T SHOWN IN THE COMPILER OUTPUT

tensor_arena_size = `8828`
Average inference time: `32166.25 us` (10k samples)
=======================================================================
========================================================================
**Dense Model `Optimized` Deployment Seeduino Xiao**

**All ops resolver**
Sketch uses `220452 bytes (84%)` of program storage space. Maximum is 262144 bytes.
## GLOBAL VARIABLE MEMORY USAGE WASN'T SHOWN IN THE COMPILER OUTPUT
#### Note after uploading remove the USB and reconnect.

**Micro_op_resolver**
Sketch uses `86116 bytes (32%)` of program storage space. Maximum is 262144 bytes.
## GLOBAL VARIABLE MEMORY USAGE WASN'T SHOWN IN THE COMPILER OUTPUT

tensor_arena_size = `8828`
Average inference time: `30640.19 us` (10k samples)
=======================================================================
