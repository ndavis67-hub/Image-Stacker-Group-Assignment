
#include <iostream>
#include <fstream>
#include <string>
#include <vector> 
#include <sstream>
#include "stacker.h"
using namespace std;
//hello world
int main() {
  //name of the image you want to process
 string name = "";
 //count for how many images you want to process
 int count =0;
 //prompt the user
 cout<<"Please enter the general name of the image to stack"<<endl;
 cin>>name;
 cout<<"please enter the amount of images to be proccessed"<<endl;
 cin>>count;
 
//processing code hear
 //builds stacker object and assign to s
  Stacker s;
  s.stackerImages(name, count);
  s.writeOutput(name);
  return 0;
}

