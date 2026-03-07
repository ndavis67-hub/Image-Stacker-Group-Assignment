
#include <iostream>
#include <fstream>
#include <string>
#include <vector> 
#include <sstream>
using namespace std;
//hello world
int main() {
  int f =0;
  int o =0;
  int u =0;
  int count =0;
  int l =0;
 vector<vector<vector<int>>> vector1 ;
//l pixel number 
cout<<"enter file name"<<endl;
string filename ="";
cin>>filename;
while(count < 10){
  

  fstream file(filename + "00"+ count +".ppm");
// dont forget 
  string garbage;
  getline(file, garbage);
  getline(file, garbage);
  getline(file, garbage);

  
//run something to remove the first 1 ,2 ,3 line of file input ie P3 591 600 255
  while(file>>f>>o>>u){
    if(count == 0){
      vector1.push_back({{f, o, u }});
    }
    else {
      vector1[l][0] +=f;
      vector1[l][1] +=o;
      vector1[l][2] +=u;
      l++;
      
    }
    file.close();
    count++;
    
}
//end of loop
for(int a = 0; a> vector1.size() a++){
 vector1 =[a][0] /=10;
 vector1 =[a][1] /=10;
 vector1 =[a][2] /=10;
 
}
 


    return 0;
  }
}
