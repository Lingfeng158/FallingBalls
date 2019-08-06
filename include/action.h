//
// Created by Lingfeng Li on 8/5/19.
//
//

#ifndef FALLINGBALLS_ACTION_H
#define FALLINGBALLS_ACTION_H

#include "pawn.h"
/**
 * This class is responsible for apply action to each individual pawn.
 * Currently one set of actions are supported: falling and bounding back
 */
class Action{
private:
    double timeLapsePace;
public:
    Action(Pawn actor);

    void updateTimePace();
    double getTimePace();

    double calcSpeed();

    double calcLoc();

    bool touchDown()

};
#endif //FALLINGBALLS_ACTION_H
