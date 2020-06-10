#include "ThreadedFilteredImage.hpp"
#include <vector>
#include <thread>

ThreadedFilteredImage::ThreadedFilteredImage( Image & img, int numberThreads ):FilteredImage(img),_numberThreads(numberThreads){
  ////////////////////////// YOUR CODE HERE ////////////////////////////////
}

void
ThreadedFilteredImage::applyKernel( Image & input, Image & output, Kernel & K ) {
  ////////////////////////// YOUR CODE HERE ////////////////////////////////
  if(output.size()==0){
    output.resize(input.rows(),input.cols());
  }
  int h=(K.rows()-1)/2;
  int w=(K.cols()-1)/2;
  output.resize(input.rows(),input.cols());

  Image extention = Image::Zero(input.rows()+2*h,input.cols()+2*w);
  extention.block(h,w,input.rows(),input.cols())=input;

  std::vector<std::thread> threads;
  int startcols=0;

  for(int i=0;i<_numberThreads;i++){
    threads.push_back(std::thread(std::bind(&ThreadedFilteredImage::applyKernelThread,this,startcols,std::ref(extention),std::ref(output),std::ref(K))));
    startcols+=(input.cols()/_numberThreads);
  }

  for(int i=0;i<_numberThreads;i++){
    threads[i].join();
  }

}

void
ThreadedFilteredImage::applyKernelThread( int startingCol, Image & input, Image & output, Kernel & K ) {
  ////////////////////////// YOUR CODE HERE ////////////////////////////////
  //Warning: In this function input is Extension!!!
  int h=(K.rows()-1)/2;
  int w=(K.cols()-1)/2;

  for(int i=0;i<input.rows()-2*h;i++){
    for(int j=startingCol;j<startingCol+(input.cols()-2*w)/_numberThreads;j++){
      output(i,j)=(K * input.block(i,j,K.rows(),K.cols())).sum();
    }
  }
}