//
// Created by Lingfeng Li on 8/1/19.
//
#include <iostream>
#include "../include/filewriting.h"
#include "../include/globalInfo.h"
int main(){
    Filewriting f;
    f.changeBkground(stage_setup);
    f.changeEnding(stage_ending);
    f.writeFile("gre.txt");
}
