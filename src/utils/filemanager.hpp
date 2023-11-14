
/*
* File manager class
*/

#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "colour.hpp"

#include "SFML/Graphics.hpp"

class FileManager {

/*
Write outout to ppm image file
Read scene from input file
*/

private:

    std::string inputPath_;
    std::string outputPath_;

public: 

    FileManager(const std::string &outputPath);
    FileManager(const std::string &inputPath, const std::string &outputPath);

    bool writeOutput(const std::vector<std::vector<Colour>> &outputBuffer, unsigned int xDim, unsigned int yDim);
    /*
    * Writes output buffer to ppm image file
    */

    void saveRenderImage(sf::Image &image);
    /*
    * Saves image using SMLF method
    */


    std::string readInput();
    /*
    * Reads scene information from input file
    * Not implemented yet
    * 
    */

};


#endif // FILEMANAGER_HPP