# Image Classification in C++

## How to use

+ First build mxnet by following the [guide](http://mxnet.readthedocs.org/en/latest/build.html)
+ Then run:
  ```
  mkdir model; python train_mnist.py --model-prefix model/mnist
  ```
  ```
  make
  ```
  ```
  convert -size 28x28 -background "#CCCCCC" -fill "#000000" -font aquafont.ttf caption:" 2 " testx.jpg
  ```
  ```
  ./predict
  ```

