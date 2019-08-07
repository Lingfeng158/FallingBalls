//
// Created by Lingfeng Li on 8/5/19.
//
//

#ifndef FALLINGBALLS_ACTION_H
#define FALLINGBALLS_ACTION_H

#include "pawn.h"
//#include "../include/globalInfo.h"
/**
 * This class is responsible for apply action to each individual pawn.
 * Currently one set of actions are supported: falling and bounding back
 */
class Action{
private:
    double timeLapsePace;
    const double acceleration=9.80;
    const double dragCoeff=0.47;
    const double velocityMultiplier=20.0;
public:
    Action( double _pace);

    void updateTimePace();
    double getTimePace();

    /**
     * NOTE: This function has side effects
     * resistance force based on last known speed
     * based on kv^2=ro*drag_coeff*area/2*v^2
     * Set air density = 1 kg/m^3
     * set downward force as positive, upward negative
     * change actor's resistence to latest val
     * @param actor
     * @return force acting on obj
     */
    double calcResistance(Pawn &actor);

    /**
     * NOTE: This function has side effects
     * speed based on last known speed and current resistance
     * set sphere density = 10 kg/m^3
     * change actor's speed to latest val
     * @param actor
     * @return current speed of obj
     */
    double calcSpeed(Pawn &actor);

    /**
     * NOTE: This function has side effects
     * location based on last known location and current speed
     * change actor's location to latest val
     * @param actor
     * @return
     */
    Location calcLoc(Pawn &actor);



    /**
     * NOTE: This function has side effects
     * If the obj touch the ground (y=0) based on last location
     * If true; reverse the magnitude of speed
     * @param actor
     * @return
     */
    bool touchDown(Pawn &actor);

};
#endif //FALLINGBALLS_ACTION_H
