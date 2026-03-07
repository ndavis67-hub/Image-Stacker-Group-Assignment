
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
  int count =1;
  int finalpix =591 * 600;
 vector<vector<int>> vector1(finalpix, {0, 0, 0}) ;
//l pixel number 
cout<<"enter file name"<<endl;
string filename ="";
cin>>filename;
while(count <= 10){
  fstream file ;
  int pnum =0;
  if(count != 10){
  file.open(filename + "_00"+ to_string(count) +".ppm");
  }
  else if(count == 10) {
  file.open(filename + "_010"+".ppm"); 
}

  if(!file.is_open()){
    cout<<"file not good "<<filename<<"_00"<<count<<".ppm"<<endl;
    return 1;
  }
// dont forget 
  string garbage;
  getline(file, garbage);
  getline(file, garbage);
  getline(file, garbage);

  
//run something to remove the first 1 ,2 ,3 line of file input ie P3 591 600 255
  while(file>>f>>o>>u){
      if(pnum>=vector1.size()){
        cout<<"warning pixel inconistent"<<pnum<<" "<<filename<<" "<<count;
        return 1;
      }
      vector1[pnum][0] +=f;
      vector1[pnum][1] +=o;
      vector1[pnum][2] +=u;
      
      pnum++;
     
    
    
}
 file.close();
    count++;
    cout << "Processed file " << count << endl;

//end of loop
}
 for(int a = 0; a< vector1.size(); a++){
 vector1[a][0] /=10;
 vector1[a][1] /=10;
 vector1[a][2] /=10;
 
}
//print it 
cout<<"devision done";
ofstream file;
//right here we need to export the vector into a new file 
file.open(filename + "Finial" +".ppm");
 file<<"P3\n";
 file<<"591 600\n";
 file<<"255\n";

for(int b =0; b<vector1.size(); b++){
  file<<vector1[b][0]<<" "<<vector1[b][1]<<" "<<vector1[b][2]<<"\n";

}
cout<<"files loaded";
file.close();
    return 0;
  }

