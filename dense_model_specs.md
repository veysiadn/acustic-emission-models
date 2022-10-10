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
Training Accuracy: 0.9904166460037231
Training Loss: 0.05160149186849594
_________________________________________________________________

Evaluation results
Validation Accuracy: 0.984000027179718
Validation Loss: 0.0769500806927681
_________________________________________________________________

Unoptimized dense_model TFLite test_accuracy: 0.98
Optimized dense_model TFLite test_accuracy: 0.9826
_________________________________________________________________

===========================
**TFLite model size:**
Unoptimized : 18164 Bytes
Optimized : 7048 Bytes  
===========================

========================================================================================================================
========================================================================================================================
**Dense Model Deployment Arduino Nano BLE 33**

<!-- **All ops resolver**
Sketch uses `379544 bytes (38%)` of program storage space. Maximum is 983040 bytes.
Global variables use `68672 bytes (26%)` of dynamic memory, leaving 193472 bytes for local variables. Maximum is 262144 bytes. -->
### ELU Activation

Sketch uses `171808 bytes (17%)` of program storage space. Maximum is 983040 bytes.
Global variables use `63496 bytes (24%)` of dynamic memory, leaving 198648 bytes for local variables. Maximum is 262144 bytes.

tensor_arena_size = `9012 bytes`  
Average inference time : `1083.90 microseconds` (10k samples)
STD of inference time  : `18.31 microseconds`
Max inference time     : `1163 microseconds`
Min inference time     : `1069 microseconds`


========================================================================================================================
**Dense model `Optimized` deployment Arduino Nano BLE 33**

<!-- **All ops resolver**
Sketch uses `367624 bytes (37%)` of program storage space. Maximum is 983040 bytes.
Global variables use `68672 bytes (26%)` of dynamic memory, leaving 193472 bytes for local variables. Maximum is 262144 bytes. -->

**Micro_op_resolver**
Sketch uses `164312 bytes (16%)` of program storage space. Maximum is 983040 bytes.
Global variables use `60712 bytes (23%)` of dynamic memory, leaving 201432 bytes for local variables. Maximum is 262144 bytes.
### REMARK: Optimized model adds to more layers, namely Quantize and Dequantize layers for that reasons inference time is slowed down by 2.8 times.
tensor_arena_size = `6328 bytes`
Average inference time : `2834.05 microseconds` (10k samples)
STD of inference time  : `16.35 microseconds`
Max inference time     : `2866 microseconds`
Min inference time     : `2796 microseconds`


========================================================================================================================

========================================================================================================================
**Dense Model Deployment STM Nucleo L432KC**

<!-- **All ops resolver**
Sketch uses `207052 bytes (78%)` of program storage space. Maximum is 262144 bytes.
Global variables use `22892 bytes (34%)` of dynamic memory, leaving 42644 bytes for local variables. Maximum is 65536 bytes.
R -->

**Micro_op_resolver**
Sketch uses `75548 bytes (28%)` of program storage space. Maximum is 262144 bytes.
Global variables use `18672 bytes (28%)` of dynamic memory, leaving 46864 bytes for local variables. Maximum is 65536 bytes.

tensor_arena_size = `8960`
Average inference time : `1535.30 microseconds`
STD of inference time  : `1.01 microseconds`
Max inference time     : `1548 microseconds`
Min inference time     : `1533 microseconds`


========================================================================================================================
**Dense Model `Optimized` Deployment STM Nucleo L432KC**

**Micro_op_resolver**
Sketch uses `66996 bytes (25%)` of program storage space. Maximum is 262144 bytes.
Global variables use `15816 bytes (24%)` of dynamic memory, leaving 49720 bytes for local variables. Maximum is 65536 bytes.


tensor_arena_size = `6284`
Average inference time : `2300.81 microseconds` (10k samples)
STD of inference time  : `1.48 microseconds`
Max inference time     : `2315 microseconds`
Min inference time     : `2299 microseconds`

======================================================================================================================

======================================================================================================================
**Dense Model Deployment Seeduino Xiao**
<!-- 
**All ops resolver**
Sketch uses `232372 bytes (88%)` of program storage space. Maximum is 262144 bytes.
## GLOBAL VARIABLE MEMORY USAGE WASN'T SHOWN IN THE COMPILER OUTPUT -->

**Micro_op_resolver**
Sketch uses `96324 bytes (36%)` of program storage space. Maximum is 262144 bytes.
## GLOBAL VARIABLE MEMORY USAGE WASN'T SHOWN IN THE COMPILER OUTPUT

tensor_arena_size = `8964 bytes`
Average inference time : `32438.66 microseconds` (10k samples)
STD of inference time  : `2.77 microseconds`
Max inference time     : `32449 microseconds`
Min inference time     : `32432 microseconds`

========================================================================================================================

**Dense Model `Optimized` Deployment Seeduino Xiao**

<!-- **All ops resolver**
Sketch uses `220452 bytes (84%)` of program storage space. Maximum is 262144 bytes.
## GLOBAL VARIABLE MEMORY USAGE WASN'T SHOWN IN THE COMPILER OUTPUT -->

**Micro_op_resolver**
Sketch uses `87756 bytes (33%)` of program storage space. Maximum is 262144 bytes.
## GLOBAL VARIABLE MEMORY USAGE WASN'T SHOWN IN THE COMPILER OUTPUT

tensor_arena_size = `6284`
Average inference time : `20868.58 microseconds` (10k samples)   
STD of inference time  : `1.93 microseconds`
Max inference time     : `20875 microseconds`
Min inference time     : `20862 microseconds`



========================================================================================================================

======================================================================================================================
**Dense Model Deployment Nucleo F401RE**

**Micro_op_resolver**
Sketch uses `71948 bytes (13%)` of program storage space. Maximum is 524288 bytes.
Global variables use `18588 bytes (18%)` of dynamic memory, leaving 79716 bytes for local variables. Maximum is 98304 bytes.



tensor_arena_size = `8964 bytes`
Average inference time : `1350.44 microseconds` (10k samples)
STD of inference time  : `0.71 microseconds`
Max inference time     : `1357 microseconds`
Min inference time     : `1350 microseconds`


========================================================================================================================

**Dense Model `Optimized` Deployment Nucleo F401RE**

**Micro_op_resolver**
Sketch uses `63396 bytes (12%)` of program storage space. Maximum is 524288 bytes.
Global variables use `16448 bytes (16%)` of dynamic memory, leaving 81856 bytes for local variables. Maximum is 98304 bytes.



tensor_arena_size = `6284`
Average inference time : `2106.13 microseconds` (10k samples)
STD of inference time  : `0.44 microseconds`
Max inference time     : `2112 microseconds`
Min inference time     : `2105 microseconds`


========================================================================================================================
======================================================================================================================
**Dense Model Deployment Raspberry Pi Pico**

**Micro_op_resolver**
UF2 file size `274944 bytes`

tensor_arena_size = `8680 bytes`
Average inference time : `7441.3696 microseconds.`
STD of inference time  : `40.7673 microseconds.`
Max inference time     : `8631 microseconds`
Min inference time     : `7351 microseconds`

========================================================================================================================

**Dense Model `Optimized` Deployment Raspberry Pi Pico**

**Micro_op_resolver**
UF2 file size `265216 bytes bytes`

tensor_arena_size = `5848`
Average inference time : `3491.7595 microseconds.`
STD of inference time  : `47.7116 microseconds.`
Max inference time     : `3886 microseconds`
Min inference time     : `3394 microseconds`

========================================================================================================================

======================================================================================================================
**Dense Model Deployment ESP-32S -NodeMCU v1.3**

**Micro_op_resolver**
Total sizes:
Used static DRAM:   30444 bytes ( 150292 remain, 16.8% used)
      .data size:   14404 bytes
      .bss  size:   16040 bytes
Used static IRAM:   43818 bytes (  87254 remain, 33.4% used)
      .text size:   42791 bytes
   .vectors size:    1027 bytes
Used Flash size :  175463 bytes
      .text     :  115607 bytes
      .rodata   :   59600 bytes
Total image size:  233685 bytes (.bin may be padded larger)


tensor_arena_size = `8996 bytes`
Average inference time : `354.8293 microseconds.` (10k samples)
STD of inference time  : `3.5063 microseconds.`
Max inference time     : `556 microseconds`
Min inference time     : `354 microseconds`

========================================================================================================================

**Dense Model `Optimized` ESP-32S -NodeMCU v1.3**

**Micro_op_resolver**
Total sizes:
Used static DRAM:   28268 bytes ( 152468 remain, 15.6% used)
      .data size:   14404 bytes
      .bss  size:   13864 bytes
Used static IRAM:   43818 bytes (  87254 remain, 33.4% used)
      .text size:   42791 bytes
   .vectors size:    1027 bytes
Used Flash size :  171839 bytes
      .text     :  122183 bytes
      .rodata   :   49400 bytes
Total image size:  230061 bytes (.bin may be padded larger)

tensor_arena_size = `6308`
Average inference time : `1051.6000 microseconds.` (10k samples)
STD of inference time  : `3.9706 microseconds.`
Max inference time     : `1126 microseconds`
Min inference time     : `1050 microseconds`
========================================================================================================================