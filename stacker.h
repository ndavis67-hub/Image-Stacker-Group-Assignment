#ifndef STACKER_H
#define STACKER_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Stacker {

private:
    string magic_number;

    int width, height, max_color;

    struct pixel{
        int red, green, blue;
    };

    vector<int> pixel;

public:
    Stacker();
    


};
#endif