all: predict

# Assume installation of:
#
# 1. g++
# 2. CBLAS ( -lcblas )



# Set variables. You can modify CXXFLAGS and LDFLAGS.
# For all variable lists, see: https://www.gnu.org/software/make/manual/html_node/Implicit-Variables.html

# CXX: Program for compiling C++ programs. X denotes plus.
CXX=g++

# CXXFLAGS : C++ compilation flags.
# -g    : add debug information
# -O0   : set optimization level 0 (lowest). Useful for debugging.
# -Wall : display all warnings.
# -std=c++11 : enable notation of C++11
# -I : include path. It's a little awkward notation but you have to add your include path immediately after '-I'.
CXXFLAGS += -g -O0 -Wall -std=c++11 -I/usr/local/include -I../../dmlc-core/include/ -I../../include/ -I../../mshadow/ -I. -DMSHADOW_USE_CBLAS=0 -DMSHADOW_USE_MKL=0 -DMSHADOW_USE_CUDA=0

# LDFLAGS : linker (ld) flags.
# -g : add debug information
# -l : Library flag. It's a little awkward notation but you have to add your library name immediately after '-l'.
LDFLAGS += -g -lopencv_core -lopencv_highgui ../../lib/libmxnet.a ../../dmlc-core/libdmlc.a -lcblas

TARGET_OBJECT_FILES= predict.o

# $(target file name):  (ingredients)

# mxnet_c_api_error.o: $(MXNET_SOURCE_FILES)
# 	$(CXX)  $(CXXFLAGS)   ../../src/c_api/c_api_error.cc   -c --output   mxnet_c_api_error.o
# mxnet_c_api_example.o: $(MXNET_SOURCE_FILES)
# 	$(CXX)  $(CXXFLAGS)   ../../src/c_api/c_api.cc         -c --output   mxnet_c_api_example.o

predict:  $(TARGET_OBJECT_FILES)
  # $@ means 'target file name'. In the following line, that's the characters before colon: 'predict'.
	$(CXX)  $(CXXFLAGS)   $(LDFLAGS)   $(TARGET_OBJECT_FILES)     --output   $@
	#####   Compiled.  USAGE :  ./predict

.PHONY: all clean
clean:
	rm *.o