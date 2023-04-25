# Tiny Machine Learning for Damage Classification in Concrete Using Acoustic Emission Signals
<font size="4">This repository contains a python code for lightweight artificial neural network model, consisting of one hidden layer with four neurons, to classify damage types in concrete material using a public acoustic emission signal dataset. The model achieves 98.4% accuracy on the test data with only 4019 parameters. 
The developed model is compared with literature models in the <a href="./convert_deploy.ipynb" class="header__link">convert_deploy.ipynb</a> file.  
 After the model development the models are deployed to several microcontroller devleopment boards and comparison graphs are created for the comparison in <a href="./plots.ipynb" class="header__link">plots.ipynb</a> file.
 The deployment to different microcontrollers is in the mcu-deployment folder. The deployment code for now is not documented, it will be documented in the future.
 To be able to run the code, you need to install the following libraries:
```sh 
gdown==4.5.1
matplotlib==3.6.1
mltk==0.0.5
numpy==1.21.5
scikit_learn==1.1.3
scipy==1.7.3
seaborn==0.11.2
silabs_mltk==0.12.0
tensorflow==2.10.0
pandas==1.4.2
```

To install the libraries, you can use the following command:
```sh
pip install -r requirements.txt
```
Then you can run the code in the <a href="./convert_deploy.ipynb" class="header__link">convert_deploy.ipynb</a> file to train the model and compare it with the literature models and plot the results using the <a href="./plots.ipynb" class="header__link">plots.ipynb</a> file.

This Readme file will be updated with more information about the project.
</font>
