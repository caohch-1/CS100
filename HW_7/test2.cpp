#include <stdlib.h>
#include <string>
#include "types.hpp"
#include "image_io.hpp"
#include "FilteredImage.hpp"
#include<chrono>


int main( int argc, char ** argv ) {
  std::chrono::high_resolution_clock::time_point now=std::chrono::high_resolution_clock::now();

  //the program expects two parameters
  //1: the directory to the data (without trailing '/')
  //2: the name of the input image file (without trailing ".txt")

  std::string inputImage = std::string(argv[1]) + std::string("/") + std::string(argv[2]) + std::string(".txt");
  Image img = loadImage(inputImage);

  FilteredImage fimg(img);
  Image & blurredImg = fimg.get(BLUR);
  Image & derxImg = fimg.get(DER_X);
  Image & deryImg = fimg.get(DER_Y);
  Image & derMagImg = fimg.get(DER_MAG);

  
  saveImage(blurredImg, std::string(argv[1]) + std::string("/") + std::string(argv[2]) + std::string("_blurred.txt"));
  saveImage(derxImg, std::string(argv[1]) + std::string("/") + std::string(argv[2]) + std::string("_derx.txt"));
  saveImage(deryImg, std::string(argv[1]) + std::string("/") + std::string(argv[2]) + std::string("_dery.txt"));
  saveImage(derMagImg, std::string(argv[1]) + std::string("/") + std::string(argv[2]) + std::string("_dermag.txt"));

  std::chrono::high_resolution_clock::time_point later=std::chrono::high_resolution_clock::now();
  double duration=(double)std::chrono::duration_cast<std::chrono::microseconds>(later-now).count();
  printf("%lf\n",duration);
  return 0;
}