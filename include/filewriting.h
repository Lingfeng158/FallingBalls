//
// Created by Lingfeng Li on 8/1/19.
//

#ifndef FALLINGBALLS_FILEWRITING_H
#define FALLINGBALLS_FILEWRITING_H

#include <iostream>
class Filewriting{
private:
    //beginning of file
    std::string bkground;
    //ending of file
    std::string ending;

public:
    //ctor
    Filewriting();

    //alt ctor
    Filewriting(std::string _bkground, std::string _ending);

    void changeBkground(std::string text);

    void changeEnding(std::string text);

    ~Filewriting()= default;

    /**
     * write available data to file for image creation
     * @param name to be saved as txt
     * @param content to be written in file
     * @param nameOfImg to output image
     */
    void writeFile(std::string name, std::string content, std::string nameOfImg);

};
#endif //FALLINGBALLS_FILEWRITING_H
