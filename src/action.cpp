//
// Created by Lingfeng Li on 8/5/19.
//

#include "../include/action.h"

#include <cmath>

Action::Action( double _pace)
:timeLapsePace(_pace){}

double Action::getTimePace() {
    return timeLapsePace;
}

double Action::calcResistance(Pawn &actor) {
    double force= dragCoeff*pow(actor.getR(),2)*pow(actor.getSpeed()/velocityMultiplier,2)/2;
    if(actor.getSpeed()<0)
        force=-force;
    //side effect
    actor.changeRes(force);
    return force;
}

double Action::calcSpeed(Pawn &actor) {
    double curSpeed=actor.getSpeed();
    double curResisForce=calcResistance(actor);
    double mass=10*4/3*3.1415926*pow(actor.getR(),3);
    double curResisAcc=curResisForce/mass;
    double curAcc=acceleration-curResisAcc;
    double deltaSpeed=timeLapsePace*curAcc*velocityMultiplier;
    double newSpeed=deltaSpeed+curSpeed;
    //side effect
    actor.changeSpeed(newSpeed);
    return newSpeed;
}

Location Action::calcLoc(Pawn &actor) {
    double currentY=actor.getLoc().y;
    double deltaY=calcSpeed(actor)*timeLapsePace;

    double nextY=currentY-deltaY;
    if(nextY<actor.getR())
        nextY=actor.getR();
    Location newLoc(actor.getLoc().x, nextY, actor.getLoc().z);
    //side effect
    actor.changeLoc(newLoc);
    return newLoc;
}

bool Action::touchDown(Pawn &actor) {
    double error=2;
    if(actor.getLoc().y-actor.getR()<error){
        //side effect
        if(abs(actor.getSpeed()/velocityMultiplier)<1)
            actor.changeSpeed(0);
        else
            actor.changeSpeed(-actor.getSpeed()*bouncingCoeff);
        return true;
    }else
        return false;
}
