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
