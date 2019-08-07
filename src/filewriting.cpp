//
// Created by Lingfeng Li on 8/1/19.
//

#include "../include/filewriting.h"
#include <fstream>

Filewriting::Filewriting() {}

Filewriting::Filewriting(std::string _bkground, std::string _ending)
:bkground(_bkground),ending(_ending) {

}

void Filewriting::changeBkground(std::string text) {
    bkground=text;
}

void Filewriting::changeEnding(std::string text) {
    ending=text;
}

void Filewriting::writeFile(std::string name, std::string content, std::string nameOfImg) {
    std::ofstream fd;
    fd.open("../txt/"+name);
    if(fd.is_open()){
        int length=nameOfImg.length();
        std::string placeholder="";
        while(length<8){
            placeholder+='0';
            length+=+1;
        }
        fd << bkground<<content<<"trace\ntiffwrite ../Images/"<<placeholder<<nameOfImg<<std::endl<<ending;
        fd.close();
    }
}