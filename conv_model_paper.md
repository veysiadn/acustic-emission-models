Model: "conv_model_paper"
_________________________________________________________________
 Layer (type)                Output Shape              Param #   
=================================================================
 conv1d_8 (Conv1D)           (None, 994, 32)           256       
                                                                 
 batch_normalization_14 (Bat  (None, 994, 32)          128       
 chNormalization)                                                
                                                                 
 activation_8 (Activation)   (None, 994, 32)           0         
                                                                 
 max_pooling1d_12 (MaxPoolin  (None, 124, 32)          0         
 g1D)                                                            
                                                                 
 conv1d_9 (Conv1D)           (None, 120, 48)           7728      
                                                                 
 batch_normalization_15 (Bat  (None, 120, 48)          192       
 chNormalization)                                                
                                                                 
 activation_9 (Activation)   (None, 120, 48)           0         
                                                                 
 max_pooling1d_13 (MaxPoolin  (None, 30, 48)           0         
 g1D)                                                            
                                                                 
 max_pooling1d_14 (MaxPoolin  (None, 7, 48)            0         
 g1D)                                                            
                                                                 
 dropout_9 (Dropout)         (None, 7, 48)             0         
                                                                 
 flatten_17 (Flatten)        (None, 336)               0         
                                                                 
 dense_43 (Dense)            (None, 32)                10784     
                                                                 
 dense_44 (Dense)            (None, 32)                1056      
                                                                 
 dense_45 (Dense)            (None, 3)                 99        
                                                                 
=================================================================
Total params: 20,243
Trainable params: 20,083
Non-trainable params: 160
_________________________________________________________________

**Training results**
Training Accuracy: 0.9763333201408386
Training Loss: 0.06763042509555817
_________________________________________________________________

**Evaluation results**
Validation Accuracy: 0.9933333396911621
Validation Loss: 0.024722926318645477
_________________________________________________________________

### COULDN'T CONVERT TO OPTIMIZED TF-LITE DUE TO UNSUPPORTED LAYERS
_________________________________________________________________

TFLite model size: `COULDN'T CONVERT TO OPTIMIZED TF-LITE DUE TO UNSUPPORTED LAYERS`
===========================
Unoptimized : 88312 Bytes
Optimized : XXXX Bytes
