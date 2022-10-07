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
**My Custom Conv Model Deployment Arduino Nano BLE 33**

**Micro_op_resolver**
Sketch uses `222944 bytes (22%) `of program storage space. Maximum is 983040 bytes.
Global variables use `105656 bytes (40%)` of dynamic memory, leaving 156488 bytes for local variables. Maximum is 262144 bytes.

tensor_arena_size = `49252 bytes`
Average inference time : `125408.72 microseconds`
STD of inference time  : `111.23 microseconds`
Max inference time     : `125792 microseconds`
Min inference time     : `125253 microseconds`


========================================================================================================================
**My Custom Conv model `Optimized` deployment Arduino Nano BLE 33**

**Micro_op_resolver**
Sketch uses `190840 bytes (19%)` of program storage space. Maximum is 983040 bytes.
Global variables use `68880 bytes (26%)` of dynamic memory, leaving 193264 bytes for local variables. Maximum is 262144 bytes.

### REMARK: 
#### Optimized model improved inference time by ~2 times.
tensor_arena_size = `13476 bytes`
Average inference time : `64625.84 microseconds`
STD of inference time  : `339.44 microseconds`
Max inference time     : `65436 microseconds`
Min inference time     : `62756 microseconds`

========================================================================================================================

========================================================================================================================
**My Custom Conv model Deployment STM Nucleo L432KC**

**Micro_op_resolver**
Sketch uses `126124 bytes (48%)` of program storage space. Maximum is 262144 bytes.
Global variables use `57204 bytes (87%)` of dynamic memory, leaving 8332 bytes for local variables. Maximum is 65536 bytes.



tensor_arena_size = `49216 bytes`
Average inference time : `102685.07 microseconds`
STD of inference time  : `10.77 microseconds`
Max inference time     : `102792 microseconds`
Min inference time     : `102683 microseconds`


========================================================================================================================
**My Custom Conv model `Optimized` Deployment STM Nucleo L432KC**

**Micro_op_resolver**
Sketch uses `92936 bytes (35%)` of program storage space. Maximum is 262144 bytes.
Global variables use `21440 bytes (32%)` of dynamic memory, leaving 44096 bytes for local variables. Maximum is 65536 bytes.


tensor_arena_size = `13456 bytes`
Average inference time : `43147.72 microseconds`
STD of inference time  : `12.20 microseconds`
Max inference time     : `43269 microseconds`
Min inference time     : `43145 microseconds`


======================================================================================================================

======================================================================================================================
**My Custom Conv model Deployment Seeduino Xiao**

`**NOT POSSIBLE DUE TO 32KB SRAM SIZE**`

========================================================================================================================

**My Custom Conv model `Optimized` Deployment Seeduino Xiao**

**Micro_op_resolver**
Sketch uses `113788 bytes (43%)` of program storage space. Maximum is 262144 bytes.
## GLOBAL VARIABLE MEMORY USAGE WASN'T SHOWN IN THE COMPILER OUTPUT

tensor_arena_size = `13444 bytes`
Average inference time : `185580.59 microseconds` (10 samples)
STD of inference time  : `3.70 microseconds`
Max inference time     : `185604 microseconds`
Min inference time     : `185573 microseconds`



========================================================================================================================

======================================================================================================================
**My Custom Conv model Deployment Nucleo F401RE**

**Micro_op_resolver**
Sketch uses `122524 bytes (23%)` of program storage space. Maximum is 524288 bytes.
Global variables use `57120 bytes (58%)` of dynamic memory, leaving 41184 bytes for local variables. Maximum is 98304 bytes.

tensor_arena_size = `49220 bytes`
Average inference time : `99225.88 microseconds`  (1000 samples)
STD of inference time  : `10.59 microseconds`
Max inference time     : `99296 microseconds`
Min inference time     : `99192 microseconds`


========================================================================================================================

**My Custom Conv model `Optimized` Deployment Nucleo F401RE**

**Micro_op_resolver**
Sketch uses `89336 bytes (17%)` of program storage space. Maximum is 524288 bytes.
Global variables use `21356 bytes (21%)` of dynamic memory, leaving 76948 bytes for local variables. Maximum is 98304 bytes.

### REMARK: 
#### Optimized model improved inference time by ~2.4 times.
tensor_arena_size = `13444`
Average inference time : `39306.54 microseconds` (1000 samples)
STD of inference time  : `7.09 microseconds`
Max inference time     : `39371 microseconds`
Min inference time     : `39305 microseconds`


========================================================================================================================
======================================================================================================================
**My Custom Conv model Deployment Raspberry Pi Pico**

**COULDN'T RUN MODEL ON PICO, INVOCATION ERROR OCCURS**

========================================================================================================================

**My Custom Conv model `Optimized` Deployment Raspberry Pi Pico**

**COULDN'T RUN MODEL ON PICO, INVOCATION ERROR OCCURS**
**Type INT32 (2) not supported.**
**Node STRIDED_SLICE (number 2) failed to invoke with status 1**

========================================================================================================================

======================================================================================================================
**My Custom Conv model Deployment ESP-32S -NodeMCU v1.3**

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
