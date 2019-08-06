//
// Created by Lingfeng Li on 8/5/19.
//
#include <stdio.h>
#include <string>
#include "../include/pawn.h"

Location::Location(double _x, double _y, double _z)
:x(_x),y(_y), z(_z){}

Pawn::Pawn(char* _input) {
    if(_input!=NULL){
        char* tmp=strtok (_input," ");
        tmp=strtok (NULL," ");
        r=atoi(tmp);
        loc.x=atof(strtok (NULL," "));
        loc.y=atof(strtok (NULL," "));
        loc.z=atof(strtok (NULL," "));
        args=strtok (NULL,"");
        speed=0;
        resistence=0;
    }else{
        args="Error in initialization";
    }

}

char* Pawn::getArgs() const{
    return args;
}

Location Pawn::getLoc() const{
    return loc;
}

double Pawn::getRes() const{
    return resistence;
}

double Pawn::getR() const{
    return r;
}

double Pawn::getSpeed() const{
    return speed;
}

void Pawn::changeSpeed(double _speed) {
    speed=_speed;
}

void Pawn::changeRes(double _res) {
    resistence=_res;
}

void Pawn::changeLoc(Location _loc) {
    loc=_loc;
}

std::string Pawn::toString() const {
    std::string result="sphere ";
    result=result+std::to_string(r)+" "+getLoc().toString()+args+"\n";
    return result;

}

std::ostream& operator<<(std::ostream &osObj, const Pawn &rhs) {
    osObj<<"The current location of the sphere is: "<<rhs.getLoc()<<std::endl;
    osObj<<"The current speed of the sphere is: "<<rhs.getSpeed()<<std::endl;
    osObj<<"The current resistance of the sphere is: "<<rhs.getRes()<<std::endl;
    return osObj;
}

std::ostream& operator<<(std::ostream & osObj,  const Location& rhs){
    osObj<<"x: "<<rhs.x<<" y: "<<rhs.y<<" z: "<<rhs.z;
    return osObj;
}

std::string Location::toString() {
    std::string result=std::to_string(x)+" "+std::to_string(y)+" "+std::to_string(z)+" ";
    return result;
}

