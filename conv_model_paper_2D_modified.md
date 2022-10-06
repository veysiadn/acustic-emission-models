Model: "modified_conv_model_paper_paper_2D"
_________________________________________________________________
 Layer (type)                Output Shape              Param #   
=================================================================
 Reshape (Reshape)           (None, 1000, 1, 1)        0         
                                                                 
 conv2d_12 (Conv2D)          (None, 1000, 1, 32)       1600      
                                                                 
 max_pooling2d_15 (MaxPoolin  (None, 125, 1, 32)       0         
 g2D)                                                            
                                                                 
 conv2d_13 (Conv2D)          (None, 125, 1, 48)        38448     
                                                                 
 max_pooling2d_16 (MaxPoolin  (None, 32, 1, 48)        0         
 g2D)                                                            
                                                                 
 max_pooling2d_17 (MaxPoolin  (None, 8, 1, 48)         0         
 g2D)                                                            
                                                                 
 flatten_18 (Flatten)        (None, 384)               0         
                                                                 
 dense_46 (Dense)            (None, 32)                12320     
                                                                 
 dense_47 (Dense)            (None, 32)                1056      
                                                                 
 dense_48 (Dense)            (None, 3)                 99        
                                                                 
=================================================================
Total params: 53,523
Trainable params: 53,523
Non-trainable params: 0
_________________________________________________________________

**Training results**
Training Accuracy: 1.0
Training Loss: 0.00013645575381815434
_________________________________________________________________

**Evaluation results**
Validation Accuracy: 0.9959999918937683
Validation Loss: 0.02530823089182377
_________________________________________________________________

Unoptimized modified_conv_model_paper TFLite test_accuracy: 0.9926666666666667
Optimized modified_conv_model_paper TFLite test_accuracy: 0.9926666666666667
_________________________________________________________________

TFLite model size:
===========================
Unoptimized : 219920 Bytes
Optimized : 62736 Bytes


========================================================================================================================
## DEPLOYMENTS ##
========================================================================================================================
**Modified Paper Conv Model to 2D Deployment Arduino Nano BLE 33**

**All ops resolver**
Sketch uses 581648 bytes (59%) of program storage space. Maximum is 983040 bytes.
Global variables use 213432 bytes (81%) of dynamic memory, leaving 48712 bytes for local variables. Maximum is 262144 bytes.

tensor_arena_size = `145932 bytes`
Average inference time : `1130094.37 microseconds`
STD of inference time  : `17.98 microseconds`
Max inference time     : `1130115 microseconds`
Min inference time     : `1130053 microseconds`

========================================================================================================================
**Modified Paper Conv Model to 2D `Optimized` deployment Arduino Nano BLE 33**

**All ops resolver**
Sketch uses `424464 bytes (43%)` of program storage space. Maximum is 983040 bytes.
Global variables use `99768 bytes (38%)` of dynamic memory, leaving 162376 bytes for local variables. Maximum is 262144 bytes.
### REMARK: 
#### Optimized model improved inference time by ~2 times.
tensor_arena_size = `38732 bytes`
Average inference time : `626224.00 microseconds`
STD of inference time  : `129.70 microseconds`
Max inference time     : `626550 microseconds`
Min inference time     : `626105 microseconds`


========================================================================================================================

========================================================================================================================
**Modified Paper Conv Model to 2D Deployment STM Nucleo L432KC**

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
**Modified Paper Conv Model to 2D `Optimized` Deployment STM Nucleo L432KC**

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
**Modified Paper Conv Model to 2D Deployment Seeduino Xiao**

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

**Modified Paper Conv Model to 2D `Optimized` Deployment Seeduino Xiao**

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
**Modified Paper Conv Model to 2D Deployment Nucleo F401RE**

**Micro_op_resolver**
Sketch uses `74548 bytes (14%)` of program storage space. Maximum is 524288 bytes.
Global variables use `18240 bytes (18%)` of dynamic memory, leaving 80064 bytes for local variables. Maximum is 98304 bytes.


tensor_arena_size = `8816 bytes`
Average inference time : `1251.34 microseconds` (10k samples)
STD of inference time  : `0.48 microseconds`
Max inference time     : `1258 microseconds`
Min inference time     : `1251 microseconds`

========================================================================================================================

**Modified Paper Conv Model to 2D `Optimized` Deployment Nucleo F401RE**



========================================================================================================================
======================================================================================================================
**Modified Paper Conv Model to 2D Deployment Raspberry Pi Pico**

**COULDN'T RUN MODEL ON PICO, INVOCATION ERROR OCCURS**

========================================================================================================================

**Modified Paper Conv Model to 2D `Optimized` Deployment Raspberry Pi Pico**

**COULDN'T RUN MODEL ON PICO, INVOCATION ERROR OCCURS**

========================================================================================================================

======================================================================================================================
**Modified Paper Conv Model to 2D Deployment ESP-32S -NodeMCU v1.3**

**Micro_op_resolver**
**DEPLOYED BUT COULND'T RUN MODEL ON MCU**
    Used static DRAM:  165892 bytes (  14844 remain, 91.8% used)
        .data size:   14404 bytes
        .bss  size:  151488 bytes
    Used static IRAM:   43818 bytes (  87254 remain, 33.4% used)
        .text size:   42791 bytes
    .vectors size:    1027 bytes
    Used Flash size :  405015 bytes
        .text     :  141639 bytes
        .rodata   :  263120 bytes
    Total image size:  463237 bytes (.bin may be padded larger)

========================================================================================================================

**Modified Paper Conv Model to 2D `Optimized` Deployment ESP-32S -NodeMCU v1.3**

**All ops resolver**
Total sizes:
Used static DRAM:   66708 bytes ( 114028 remain, 36.9% used)
      .data size:   14404 bytes
      .bss  size:   52304 bytes
Used static IRAM:   44018 bytes (  87054 remain, 33.6% used)
      .text size:   42991 bytes
   .vectors size:    1027 bytes
Used Flash size :  629467 bytes
      .text     :  487019 bytes
      .rodata   :  142192 bytes
Total image size:  687889 bytes (.bin may be padded larger)

**Micro_op_resolver**
Total sizes:
Used static DRAM:   61396 bytes ( 119340 remain, 34.0% used)
      .data size:   14404 bytes
      .bss  size:   46992 bytes
Used static IRAM:   43818 bytes (  87254 remain, 33.4% used)
      .text size:   42791 bytes
   .vectors size:    1027 bytes
Used Flash size :  255219 bytes
      .text     :  148187 bytes
      .rodata   :  106776 bytes
Total image size:  313441 bytes (.bin may be padded larger)

tensor_arena_size = `38636 bytes`
Average inference time : `172106.2969 microseconds.`
STD of inference time  : `72.0834 microseconds.`
Max inference time     : `172322 microseconds`
Min inference time     : `172078 microseconds`
========================================================================================================================

