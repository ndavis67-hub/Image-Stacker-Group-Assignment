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
     * @brief builds ppm file from a base name and index 
     * 
     * @param filename 
     * @param index 
     * @return std::string
     * 
     */
    std::string buildFilename(std::string filename, int count);
    /**
     * @brief Writes the pixel data to a new PPM file.
     * 
     * Outputs a valid P3 PPM file with a 591x600 header and one row of pixels
     * per line. The output file is named filename + "Final.ppm".
     * 
     * @param filename The base name used for the output file
     * @return true if the file was written successfully
     * @return false if the file could not be opened
     */
    bool writeOutput(std::string filename);
    
private:
    /**
     * @brief P3 
     * 
     */
    std::string magic_number;

    /**
     * @brief width, height, and max color of image in pixels
     * 
     */
    int width, height, max_color;

    /**
     * @brief represents a single pixel with red, green, and blue 
     * 
     */
    struct pixel{
        int red, green, blue; 
    };

    /**
     * @brief stores the accumulated and averaged pixel data for the output
     * 
     */
    std::vector<pixel> p;

};
#endif
