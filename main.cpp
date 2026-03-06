
#include <iostream>
#include <fstream>
#include <string>
#include <vector> 
#include <sstream>
using namespace std;
//hello world
int main() {
  int i =0, j=0, k=0;
  int count =0;
 vector<vector<vector<int>>> vector1 ;
 vector1[i] = {f, o, u };
//i = Red 
//j = Green
//k = Blue
//l pixel number 
cout<<"enter file name"<<endl;
string filename ="";
cin>>filename;
while(count < 10){
  

  fstream file(filename + "00"+ count +".ppm");
// dont forget 
  int f =0;
  int o =0;
  int u =0;
  
//run something to remove the first 1 ,2 ,3 line of file input ie P3 591 600 255
  while(file>>f>>o>>u){
    vector1[i] = {f, o, u };
    i++
  }
    file.close()
   
    count++;
}
//end of loop 


  return 0;
}
