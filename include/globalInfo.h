//
// Created by Lingfeng Li on 8/1/19.
//

#ifndef FALLINGBALLS_GLOBALINFO_H
#define FALLINGBALLS_GLOBALINFO_H

#include <iostream>
std::string stage_setup="clear\n"
                        "screen 600 600\n"
                        "background 0.8 0.8 0.8\n"
                        "camera 225 225 300 0 0 -1 0 1 0 575\n"
                        "light 0.9 0.9 0.9 -1 -1 0\n"
                        "light 0.5 0.4 0.9 0 -1 0\n"
                        "box -200 -20 -600 650 0 -300 0.3529 0.3529 0.3529 0.3529 0.3529 0.3529 1 1 1\n"
                        "box 400 25 -400 470 95 -300 0.0209 0.09 0.5 0.7 0.9 0.5 0.5 0.5 0.5\n";

std::string stage_ending = "quit";

char pawnData[]="sphere 50 150 120 -400 0.418 0.2667 0.107 0.4118 0.2863 0.396  0.2 1 1;"
                "sphere 120 100 300 -400 0.28 0.1 0.5 0.005 0.7 0.3 0.5 1 1;"
                "sphere 100 80 180 -600 0.286 0.117 0.007 0.509 0.32 0.043 1 1 1;"
                "sphere 65 290 80 -270 0.0138 0.0680 0.510 0.122 0.427 0.278 1 0.3 0.7";


const double actionTime=15.0;
const double pace=0.04;
#endif //FALLINGBALLS_GLOBALINFO_H
