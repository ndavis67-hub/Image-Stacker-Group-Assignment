#include <iostream>
#include <fstream>
#include <string>
#include <vector> 
#include <sstream>
#include "stacker.h"
using namespace std;
//copy constructor
Stacker::Stacker(){
  magic_number = ""; 
  width = 0;
  height = 0;
  max_color = 0;
}

//builds filename similar to example output in our assignment ex: orion/orion_001.ppm
string Stacker::buildFilename(std::string filename, int count){ 
  string num;
  if(count != 10){
    num = "00" + to_string(count); //produces 001 through 009
  } else {
    num = "010"; //produces 010
  }
  return filename + "_" + num + ".ppm";
}

bool Stacker::stackerImages(std::string filename, int count){
  int f = 0; //red 
  int o = 0; //green
  int u = 0; //blue
  //Allocate enough pixels for a 591x600 image
  int finalpix = 591 * 600;
  p.assign(finalpix, {0, 0, 0});
  //save original count before the loop
  int totalImages = count;
  int imageCount = 1;

  while(imageCount <= count){
    fstream file;
    //tracks which pixel we are currently reading into
    int pnum = 0;
    //Open the current image file
    file.open(buildFilename(filename, imageCount));
    //return false if the file name does not match an actual file
    if(!file.is_open()){
      cout << "file not good: " << buildFilename(filename, imageCount) << endl;
      return false;
    }
    // dont forget
    string garbage;
    getline(file, garbage); //P3
    getline(file, garbage); // 591 600
    getline(file, garbage); //255
    //run something to remove the first 1 ,2 ,3 line of file input ie P3 591 600 255
    while(file >> f >> o >> u){
      if(pnum >= (int)p.size()){
	//more pixels in file than expected
        cout << "warning pixel inconsistent " << pnum << " " << filename << " " << count;
        return false;
      }
      p[pnum].red   += f;
      p[pnum].green += o;
      p[pnum].blue  += u;
      pnum++;
    }
    file.close();
    imageCount++;
    cout << "Processed file " << imageCount - 1 << endl;
  }

  for(int a = 0; a < (int)p.size(); a++){
    p[a].red   /= totalImages;
    p[a].green /= totalImages;
    p[a].blue  /= totalImages;
  }
  cout<<"devision done" << endl;
  return true;
}
//Writes the averaged 
bool Stacker::writeOutput(std::string filename){
  //print it
  ofstream file;
  //right here we need to export the vector into a new file
  file.open(filename + "Finial" +".ppm");
  file << "P3 ";
  file << "591 600 ";
  file << "255 ";

  for(int b = 0; b < (int)p.size(); b++){
    file << p[b].red << " " << p[b].green << " " << p[b].blue;
    //new line after every pixel row
    if((b + 1) % 591 == 0){
      file << " ";
    } else {
      file << " ";
    }
  }
  cout << "File written: " << filename << "Final.ppm" << endl;
  file.close();
  return true;
}
