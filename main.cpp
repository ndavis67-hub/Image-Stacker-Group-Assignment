
#include <iostream>
#include <fstream>
#include <string>
#include <vector> 
#include <sstream>
#include "stacker.h"
using namespace std;
//hello world
int main() {
 string name = "";
 int count =0;
 cout<<"Please enter the general name of the image to stack"<<endl;
 cin>>name;
 cout<<"please enter the amount of images to be proccessed"<<endl;
 cin>>count;
 
//processing code hear 
  Stacker s;
  s.stackerImages(name, count);
  s.writeOutput(name);
  return 0;
}

