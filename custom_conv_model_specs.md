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
