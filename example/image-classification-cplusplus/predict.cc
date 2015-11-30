/*!
 *  Copyright (c) 2015 by caprice-j
 * \file predict.cc
 * \brief read jpg image and classify in C++
 */
#include <stdio.h>
// #include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "../../include/mxnet/c_api.h"
#include "../../include/mxnet/c_predict_api.h"
#include "../../include/mxnet/operator.h"
#include "../../src/operator/fully_connected-inl.h"

// MXNET_REGISTER_OP_PROPERTY(FullyConnected, mxnet::op::FullyConnectedProp);

class RawCharObject {
public:
  std::string input_file_name;
  int len;
  char* buf;

  // constructor
  RawCharObject(std::string filename)
  : input_file_name(filename) {
    std::ifstream ifs (filename,
                       std::ios::in | std::ios::binary);
    if (!ifs)
    {
      std::cerr << "Can't open the file. Perhaps you didn't run train_mnist.py? \n";
      assert(false);
    }

    ifs.seekg (0, std::ios::end);
    len = ifs.tellg();
    ifs.seekg (0, std::ios::beg);
    std::cout << filename.c_str() << " ... "
              << len              << " bytes\n";

    // RAII : Resourse Acquisition is Initialization
    buf = new char [ sizeof(char) * len ] ;
    ifs.read(buf, len);
    ifs.close();
  }

  // Destructor for freeing buffer
  ~RawCharObject(){

    delete[] buf;

  }
};

int main(){
  // cv::Mat test_x = cv::imread("empty.jpg", 0); // 0 means reading as a grayscale image
  // mx_uint out_size;         // alias of unsigned int
  // NDArrayHandle* out_arr;   // alias of void*
  // mx_uint out_name_size;
  // const char** out_names;

  /*  */

  // For parameter specification, see: mxnet/include/mxnet/c_api.h
  // For parameter usage, I refered to R-package/src/ndarray.cc

  // int failure = MXNDArrayLoad("model/mnist-0-0001.params", &out_size, &out_arr, &out_name_size, &out_names);
  // if( failure ){
  //   printf("failure: %d \n", failure);
  //   return 1;
  // }

  // For parameter specification, see: mxnet/include/mxnet/c_predict_api.h
  // ifs.read(buf, param_byte_len);

  RawCharObject jsonStr("model/mnist-0-symbol.json");
  // byte length of jsonStr is not needed, so overwrite it
  RawCharObject paramStr("model/mnist-0-0001.params");

  // I refered to mxnet_predict.py for usage
  int dev_type = 1; // 1: cpu, 2: gpu
  int dev_id = 0; // arbitrary.
  mx_uint num_input_nodes = 1; // 1 for feedforward
  const char* input_key[1] = {"data"};
  const char** input_keys = input_key;
  const mx_uint input_shape_indptr[2] = {(const mx_uint)0, (const mx_uint)784};
  // ( trained_width, trained_height, channel, num)
  const mx_uint input_shape_data[4] = {(const mx_uint) 224, (const mx_uint)244, (const mx_uint)3, (const mx_uint)1};
  PredictorHandle * out= 0; // alias for void *

  printf("paramStr.len %d\n", paramStr.len);
  MXPredCreate((const char* ) jsonStr.buf,
               (const char* ) paramStr.buf,
               (size_t) paramStr.len,
               dev_type,
               dev_id,
               num_input_nodes,
               input_keys,
               input_shape_indptr,
               input_shape_data,
               out
              );

  // MXRandomSeed(0);
  // MXPredSetInput(out,
  //                input_keys,
  //                input_shape_data,
  //                (mx_uint) 784);

  // MXPredForward(out);
  // mx_uint output_index = 0;
  // mx_uint output_buf_size = 1000;
  // mx_float output_buf[output_buf_size];

  // MXPredGetOutput(out,
  //                 output_index,
  //                 output_buf,
  //                 output_buf_size);

  // MXPredFree(out);

  // MXNotifyShutdown();

  // implicitly call destructors of RawCharObject
  return 0;
}

  // MX_CALL(MXNDArrayLoad(fiparam_byte_lename.c_str(),
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
