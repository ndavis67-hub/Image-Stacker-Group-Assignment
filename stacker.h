#ifndef STACKER_H
#define STACKER_H
#include <vector>
#include <string>

class Stacker {
public:
    /**
     * @brief Construct a new Stacker object
     * 
     */
    Stacker();

    /**
     * @brief 
     * 
     * @param name 
     * @param numImages 
     * @return true
     * @return false 
     * We want to know whether all the images were read correctly
     */
    bool stackerImages(std::string name, int count);
    /**
     * @brief 
     * 
     * @param filename 
     * @param index 
     * @return std::string 
     */
    std::string buildFilename(std::string filename, int count);

    bool writeOutput(std::string filename);
    
private:
    /**
     * @brief 
     * 
     */
    std::string magic_number;

    /**
     * @brief 
     * 
     */
    int width, height, max_color;

    /**
     * @brief 
     * 
     */
    struct pixel{
        int red, green, blue;
    };

    /**
     * @brief 
     * 
     */
    std::vector<pixel> p;

};
#endif