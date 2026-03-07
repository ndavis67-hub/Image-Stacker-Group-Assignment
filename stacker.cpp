#include <iostream>
#include <fstream>
#include <string>
#include <vector> 
#include <sstream>
#include "stacker.h"
using namespace std;

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
    num = "00" + to_string(count);
  } else {
    num = "010"; 
  }
  return filename + "_" + num + ".ppm";
}

bool Stacker::stackerImages(std::string filename, int count){
  int f = 0;
  int o = 0;
  int u = 0;
  int finalpix = 591 * 600;
  p.assign(finalpix, {0, 0, 0});
  int totalImages = count;
  int imageCount = 1;

  while(imageCount <= count){
    fstream file;
    int pnum = 0;
    file.open(buildFilename(filename, imageCount));  // no subfolder prefix

    if(!file.is_open()){
      cout << "file not good: " << buildFilename(filename, imageCount) << endl;
      return false;
    }
    // dont forget
    string garbage;
    getline(file, garbage);
    getline(file, garbage);
    getline(file, garbage);
    //run something to remove the first 1 ,2 ,3 line of file input ie P3 591 600 255
    while(file >> f >> o >> u){
      if(pnum >= (int)p.size()){
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