#include <iostream>
#include <fstream>
#include <string>
#include <vector> 
#include <sstream>
#include "stacker.h"
using namespace std;
int main() {
 string name = "";
 int count =0;
 cout<<"Please enter the general name of the image to stack"<<endl;
 cin>>name;
 cout<<"please enter the amount of images to be proccessed"<<endl;
 cin>>count;
 
//processing code hear 

cout<<"stacking images "<<count<<endl;
  return 0;
}

Stacker::Stacker(){
  string magic_number = ""; 
  int width = 0;
  int height = 0;
  int max_color = 0;
}
//builds filename similar to example output in our assignment ex: orion/orion_001.ppm
string Stacker::buildFilename(std::string filename, int index){
  ostringstream img;

  img << filename << "/" << filename << "_" << index << ".ppm";

  return img.str();
}

bool Stacker::ppmFile(std::string filename, bool isImage){

}

bool Stacker::stackerImages(std::string name, int count){
  //First lets loop through the images 
  for (int i = 1; i <= count; i++){
    string filename = buildFilename(name, i);
    cout << "     " << filename;
  }
  cout << endl;

}