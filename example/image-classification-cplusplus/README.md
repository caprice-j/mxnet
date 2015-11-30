# Image Classification

This fold contains examples for image classifications. In this task, we assign
labels to an image with confidence scores, see the following figure for example ([source](http://papers.nips.cc/paper/4824-imagenet-classification-with-deep-convolutional-neural-networks.pdf)):

<img src=https://raw.githubusercontent.com/dmlc/web-data/master/mxnet/image/image-classification.png
width=400/>

## How to use

+ First build mxnet by following the [guide](http://mxnet.readthedocs.org/en/latest/build.html)
+ Then run:
  ```bash
  mkdir model; python train_mnist.py --model-prefix model/mnist
  make
  ```

