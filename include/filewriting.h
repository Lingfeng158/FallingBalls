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
     * wite available data to file given name 'name'
     * @param name the name of file to be written
     */
    void writeFile(std::string name);

};
#endif //FALLINGBALLS_FILEWRITING_H
