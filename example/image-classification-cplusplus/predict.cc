/*!
 *  Copyright (c) 2015 by caprice-j
 * \file predict.cc
 * \brief read jpg image and classify in C++
 *  Image Record Format: zeropad[64bit] imid[64bit] img-binary-content
 *
 *  Image List Format: unique-image-index label[s] path-to-image
 */
// #include <opencv2/opencv.hpp>
#include <stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "../../include/mxnet/c_api.h"

int main(){
  // cv::Mat test_x = cv::imread("empty.jpg", 0); // 0 means reading as a grayscale image
  mx_uint out_size;         // alias of unsigned int
  NDArrayHandle* out_arr;   // alias of void*
  mx_uint out_name_size;
  const char** out_names;
  // refer to R-package/src/ndarray.cc
  MXRandomSeed(0);
  int failure = MXNDArrayLoad("model/mnist-0-0001.params", &out_size, &out_arr, &out_name_size, &out_names);
  if( failure ){
    printf("failure: %d \n", failure);
    return 1;
  }
  // MXNotifyShutdown();
  return 0;
}

  // MX_CALL(MXNDArrayLoad(filename.c_str(),
  //                       ));
  // Rcpp::List out(out_size);
  // for (mx_uint i = 0; i < out_size; ++i) {
  //   out[i] = NDArray::RObject(out_arr[i], true);
  // }
  // if (out_name_size != 0) {
  //   std::vector<std::string> lst_names(out_size);
  //   for (mx_uint i = 0; i < out_size; ++i) {
  //     lst_names[i] = out_names[i];
  //   }
  //   out.names() = lst_names;
  // }
