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
Optimized dense_model TFLite test_accuracy: 0.968
_________________________________________________________________

===========================
**TFLite model size:**
Unoptimized : 18340 Bytes
Optimized : 7024 Bytes  
===========================

========================================================================================================================
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