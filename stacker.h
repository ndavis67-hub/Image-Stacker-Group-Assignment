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
     * @param name 
     * @return true 
     * @return false 
     */
    bool output(std::string name) const;
    
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

    /**
     * @brief 
     * 
     * @param filename 
     * @param index 
     * @return string 
     */
    std::string buildFilename(std::string filename, int index);

    /**
     * @brief 
     * 
     * @param filename 
     * @param isImage 
     * @return true 
     * @return false 
     */
    bool ppmFile(std::string filename, bool isImage);

};
#endif