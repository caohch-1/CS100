#include "FilteredImage.hpp"
#include <iostream>
//Function required
FilteredImage::FilteredImage( Image & img ) : _img(img){
  ////////////////////////// YOUR CODE HERE ////////////////////////////////
}

Image &
FilteredImage::get( int type ) {
  //Judge
  if(_filteredImages[type] != nullptr){
    return *_filteredImages[type];
  }

  //prepare
  int row=_img.rows();
  int col=_img.cols();

  //calculate
  switch( type ) {
    case BLUR: {
      ////////////////////////// YOUR CODE HERE ////////////////////////////////
      Kernel K_blur(5,5);
      K_blur <<(2.0f/159.0f),(4.0f/159.0f),(5.0f/159.0f),(4.0f/159.0f),(2.0f/159.0f),
                (4.0f/159.0f),(9.0f/159.0f),(12.0f/159.0f),(9.0f/159.0f),(4.0f/159.0f),
                (5.0f/159.0f),(12.0f/159.0f),(15.0f/159.0f),(12.0f/159.0f),(5.0f/159.0f),
                (4.0f/159.0f),(9.0f/159.0f),(12.0f/159.0f),(9.0f/159.0f),(4.0f/159.0f),
                (2.0f/159.0f),(4.0f/159.0f),(5.0f/159.0f),(4.0f/159.0f),(2.0f/159.0f);
      Image outImg(row,col);
      applyKernel(_img,outImg,K_blur);

      Image result=Image::Zero(row,col);
      result.block(2,2,row-4,col-4)=outImg.block(2,2,row-4,col-4);

      std::shared_ptr<Image> result_(new Image(result));
      _filteredImages[0]=result_;
      return *(_filteredImages.find(0)->second);
    }
    case DER_X: {
      ////////////////////////// YOUR CODE HERE ////////////////////////////////
      Kernel K_der_x(3,3);
      K_der_x <<-1.0f,0.0f,1.0f,
                -2.0f,0.0f,2.0f,
                -1.0f,0.0f,1.0f;
      Image outImg(row,col);
      applyKernel(_img,outImg,K_der_x);

      Image result=Image::Zero(row,col);
      result.block(1,1,row-2,col-2)=outImg.block(1,1,row-2,col-2);

      std::shared_ptr<Image> result_(new Image(result));
      _filteredImages[1]=result_;
      return *(_filteredImages.find(1)->second);
    }
    case DER_Y: {
      ////////////////////////// YOUR CODE HERE ////////////////////////////////
      Kernel K_der_y(3,3);
      K_der_y <<-1.0f,-2.0f,-1.0f,
                0.0f,0.0f,0.0f,
                1.0f,2.0f,1.0f;
      Image outImg(row,col);
      applyKernel(_img,outImg,K_der_y);

      Image result=Image::Zero(row,col);
      result.block(1,1,row-2,col-2)=outImg.block(1,1,row-2,col-2);

      std::shared_ptr<Image> result_(new Image(result));
      _filteredImages[2]=result_;
      return *(_filteredImages.find(2)->second);
    }
    case DER_MAG: {
      ////////////////////////// YOUR CODE HERE ////////////////////////////////    
      Kernel K_der_x(3,3);
      K_der_x <<-1.0f,0.0f,1.0f,
                -2.0f,0.0f,2.0f,
                -1.0f,0.0f,1.0f;

      Kernel K_der_y(3,3);
      K_der_y <<-1.0f,-2.0f,-1.0f,
                0.0f,0.0f,0.0f,
                1.0f,2.0f,1.0f;
      Image dxRes(row,col);
      applyKernel(_img,dxRes,K_der_x);
      
      Image dyRes(row,col);
      applyKernel(_img,dyRes,K_der_y);
      
      Image outImg(row,col);
      
      outImg= sqrt(pow(dxRes,2)+pow(dyRes,2));

      Image result=Image::Zero(row,col);
      result.block(1,1,row-2,col-2)=outImg.block(1,1,row-2,col-2);

      std::shared_ptr<Image> result_(new Image(result));
      _filteredImages[3]=result_;
      return *(_filteredImages.find(3)->second);
    }
    default: {
      std::cout << "Error: unrecognized kernel option\n";
    }
  }
  return _img;
}

void
FilteredImage::applyKernel( Image & input, Image & output, Kernel & K ) {
  ////////////////////////// YOUR CODE HERE ////////////////////////////////

  int h=(K.rows()-1)/2;
  int w=(K.cols()-1)/2;
  output.resize(input.rows(),input.cols());

  Image extention = Image::Zero(input.rows()+2*h,input.cols()+2*w);
  extention.block(h,w,input.rows(),input.cols())=input;

  for(int i=0;i<input.rows();i++){
    for(int j=0;j<input.cols();j++){
      output(i,j)=(K*extention.block(i,j,K.rows(),K.cols())).sum();
    }
  }
}
