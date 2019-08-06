//
// Created by Lingfeng Li on 8/1/19.
//
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <typeinfo>
#include <vector>
#include "../include/filewriting.h"
#include "../include/globalInfo.h"
#include "../include/pawn.h"
#include "../include/action.h"
int main(){
    Filewriting fd;
    fd.changeBkground(stage_setup);
    fd.changeEnding(stage_ending);

    //initialize actors
    char* ptr;
    std::vector<Pawn> actors;
    char* tmp=strtok_r(pawnData, ";", &ptr);
    do{
        actors.push_back(Pawn(tmp));
    }
    while(tmp=strtok_r(NULL, ";", &ptr));

    //initialize action stage
    Action act(pace);
    double time=actionTime;
    int timeCounter=0;
    int totalTimeFrameCount=time/pace;
    //int totalTimeFrameCount=3;
    while(timeCounter<totalTimeFrameCount){
        //update actors
        for(int i=0;i<actors.size();i++){
           act.touchDown(actors[i]);
           act.calcLoc(actors[i]);
        }
        //write files
        std::string content="";
        for(int i=0;i<actors.size();i++){
            content+=actors[i].toString();
        }
        fd.writeFile(std::to_string(timeCounter)+".txt", content,std::to_string(timeCounter)+".tif");

        timeCounter++;
    }


}
