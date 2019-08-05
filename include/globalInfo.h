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
                        "box -200 -20 -600 650 0 -300 0.3529 0.3529 0.3529 0.3529 0.3529 0.3529 1 1 1\n";

std::string stage_ending = "quit";

char pawnData[]="sphere 50 150 200 -400 0.418 0.2667 0.107 0.4118 0.2863 0.396  0.2 1 1;sphere 120 100 400 -400 0.28 0.1 0.5 0.005 0.7 0.3 0.5 1 1;;";

const double acceleration=9.80;
#endif //FALLINGBALLS_GLOBALINFO_H
