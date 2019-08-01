//
// Created by Lingfeng Li on 8/1/19.
//

#include "../include/filewriting.h"
#include <fstream>

Filewriting::Filewriting(std::string _bkground, std::string _ending)
:bkground(_bkground),ending(_ending) {

}

void Filewriting::writeFile(std::string name) {
    std::ofstream fd;
    fd.open("../txt/"+name);
    if(fd.is_open()){
        fd << bkground<<ending;
        fd.close();
    }
}