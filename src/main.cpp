//
// Created by Lingfeng Li on 8/1/19.
//
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <typeinfo>
#include "../include/filewriting.h"
#include "../include/globalInfo.h"
#include "../include/pawn.h"
int main(){
    Filewriting f;
    f.changeBkground(stage_setup);
    f.changeEnding(stage_ending);
    char* ptr;
    char* tmp=strtok_r(pawnData, ";", &ptr);
    Pawn bar(tmp);
    tmp=strtok_r(NULL, ";", &ptr);
    Pawn foo(tmp);
    std::cout<<bar.toString()<<foo.toString();


}
