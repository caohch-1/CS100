#include "image_io.hpp"

#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

  //  * Implementation of `Image loadImage( const std::string & pathToRaw )` 
  //  * You should open the file corresponds to `pathToRaw`, and read the content of it.
  //  * The input file contains `m+1` lines, the first line contains two integer `m` and `n`
  //  * `m` is the number of lines, `n` is the number of columns of the matrix
  //  * For the next `m` lines, each line contains `n` integers, which are the pixels of image.
  //  * When load a image, you should divide each pixel by 255
  //  * E.g. if the matrix_file[i][j] = 128, then image[i][j] = 128.0f/255.0f
  //  * For a sample, you can refer to `soccer.txt` in directory `data`
  //  * @param pathToRaw: The image matrix file path, eg: `../data/soccer.txt`
  //  * @return: The image object load from TXT file

Image
loadImage( const std::string & pathToRaw ) {
    ////////////////////////// YOUR CODE HERE ////////////////////////////////

  //Get data 
  //Warning:first is row 
  //        second is col
  ifstream infile;
  infile.open( pathToRaw.data() );
  vector<vector<float>> resultset;
  vector<float> dataset;
  string s;
  while(getline(infile,s)){
    istringstream is(s);
    float data;
    while(!is.eof()){
      is >> data;
      dataset.emplace_back(data);
    }
    resultset.emplace_back(dataset);
    dataset.clear();
    s.clear();
  }
  infile.close();

  //Store real data without row and col information
  Image result((int)resultset[0][0],(int)resultset[0][1]);
  for(int i=1;i<=(int)resultset[0][0];i++){
    for(int j=0;j<(int)resultset[0][1];j++){
      result(i-1,j)=(resultset[i][j])/255.0f;
    }
  }

  return result;
}
  //  * Implementation of `void saveImage( Image & img, const std::string & pathToRaw )` 
  //  * You should open/create the file corresponds to `pathToRaw`, and write the given image to it.
  //  * The output file contains `m` lines
  //  * For the each line in `m` lines, it contains `n` floats, which are the pixels of image.
  //  * Each float ranges from 0 to 1.
  //  * @param img: The image object need to write.
  //  * @param pathToRaw: The image matrix file path, eg: `../data/soccer_derx.txt`
void
saveImage( Image & img, const std::string & pathToRaw ) {
  ////////////////////////// YOUR CODE HERE ////////////////////////////////
  //Get row and col
  //std::cout<<"   hb";
  int row=img.rows();
  int col=img.cols();
  //std::cout<<row<<endl;
  //Create outfile
  ofstream outfile;
  outfile.open(pathToRaw.data(),ios::trunc);
  for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
      outfile<<img(i,j)<<" "; //something maybe wrong; maybe Okay
    }
    outfile<<"\n";
  }
  outfile.close();
}