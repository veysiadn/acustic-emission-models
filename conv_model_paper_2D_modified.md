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

`**NOT POSSIBLE DUE TO 64KB SRAM SIZE**`

========================================================================================================================
**Modified Paper Conv Model to 2D `Optimized` Deployment STM Nucleo L432KC**

**Micro_op_resolver**
Sketch uses `138960 bytes (53%)` of program storage space. Maximum is 262144 bytes.
Global variables use `46680 bytes (71%)` of dynamic memory, leaving 18856 bytes for local variables. Maximum is 65536 bytes.


tensor_arena_size = `38672`
Average inference time : `390100.00 microseconds`
STD of inference time  : `61.67 microseconds`
Max inference time     : `390285 microseconds`
Min inference time     : `390079 microseconds`

======================================================================================================================

======================================================================================================================
**Modified Paper Conv Model to 2D Deployment Seeduino Xiao**

`**NOT POSSIBLE DUE TO 32KB SRAM SIZE**`
========================================================================================================================

**Modified Paper Conv Model to 2D `Optimized` Deployment Seeduino Xiao**

`**NOT POSSIBLE DUE TO 32KB SRAM SIZE**`

========================================================================================================================

======================================================================================================================
**Modified Paper Conv Model to 2D Deployment Nucleo F401RE**

`**NOT POSSIBLE DUE TO 96KB SRAM SIZE**`

========================================================================================================================

**Modified Paper Conv Model to 2D `Optimized` Deployment Nucleo F401RE**
**Micro ops resolver**
Sketch uses `135360 bytes (25%)` of program storage space. Maximum is 524288 bytes.
Global variables use `46596 bytes (47%)` of dynamic memory, leaving 51708 bytes for local variables. Maximum is 98304 bytes.

tensor_arena_size = `38676`
Average inference time : `364486.31 microseconds`
STD of inference time  : `32.58 microseconds`
Max inference time     : `364584 microseconds`
Min inference time     : `364474 microseconds`

========================================================================================================================
======================================================================================================================
**Modified Paper Conv Model to 2D Deployment Raspberry Pi Pico**

**COULDN'T RUN MODEL ON PICO, INVOCATION ERROR OCCURS** `Initial issue, but fixed after some time.`
### Remark: I had to change strided slice.cc file in the library and add Int32 support to strided slice opeation.

**Micro ops resolver**
UF2 file size `726016 bytes bytes`
tensor_arena_size = `146312 bytes`
Average inference time : `3236171.0000 microseconds.` (100 samples)
STD of inference time  : `187.8904 microseconds.`
Max inference time     : `3236439 microseconds`
Min inference time     : `3235901 microseconds`


========================================================================================================================

**Modified Paper Conv Model to 2D `Optimized` Deployment Raspberry Pi Pico**

**All ops resolver**
UF2 file size `794112 bytes bytes`

tensor_arena_size = `38456 bytes`
Average inference time : `589597.5000 microseconds.`  (1000 samples)
STD of inference time  : `50.8473 microseconds.`
Max inference time     : `589705 microseconds`
Min inference time     : `589537 microseconds`
**Micro_op_resolver**
UF2 file size `424448 bytes`
**All other specs are same.**

========================================================================================================================

======================================================================================================================
**Modified Paper Conv Model to 2D Deployment ESP-32S -NodeMCU v1.3**

**Micro_op_resolver**
`**DEPLOYED BUT COULND'T RUN MODEL ON MCU**`
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

