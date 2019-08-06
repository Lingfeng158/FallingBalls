//
// Created by Lingfeng Li on 8/5/19.
//

#ifndef FALLINGBALLS_PAWN_H
#define FALLINGBALLS_PAWN_H

#import <iostream>
struct Location{
public:
    double x;
    double y;
    double z;
    Location()= default;
    Location(double _x, double _y, double _z);

friend std::ostream& operator<<(std::ostream & osObj, const Location& rhs);
std::string toString();
};

std::ostream& operator<<(std::ostream & osObj, const Location& rhs);

//spheres on stage
class Pawn{
    //drag coefficient of sphere = 0.47
    //set bouncing energy loss coefficient = 0.9
    //set acc = global acceleration
private:

    //current speed of sphere
    double speed;
    //current location of sphere
    Location loc;
    //volume of current obj
    double r;
    //air resistence force of obj
    double resistence;
    //all properties of sphere other than location
    char* args;

public:
    Pawn()= default;

    Pawn(char* _input);

    void changeSpeed(double _speed);

    void changeLoc(Location _loc);

    void changeRes(double _res);

    Location getLoc()const;

    double getRes()const ;

    double getSpeed()const;

    char* getArgs()const;

    double getR()const;

    std::string toString()const;

friend std::ostream& operator<<(std::ostream & osObj,  const Location& rhs);
friend std::ostream& operator<<(std::ostream & osObj, const Pawn& rhs);;

};

std::ostream& operator<<(std::ostream & osObj, const Pawn& rhs);
#endif //FALLINGBALLS_PAWN_H
