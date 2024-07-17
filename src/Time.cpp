#include "../include/Time.h"
#include <string>

using namespace std;

Time::Time(short newHour, short newMin, short newSec)
    : hour(newHour), minute(newMin), second(newSec) {}

    //getters:
    short Time::getHour() { return hour; }
    short Time::getMin() { return minute; }
    short Time::getSec() { return second; }

    //setters: 
    void Time::setHour(short newHour) { hour = newHour; }
    void Time::setMin(short newMin) { minute = newMin; }
    void Time::setSec(short newSec) { second = newSec; }

    //resto: 
    // void Time::fixTime(){ }
    // void Time::sumTime(Time toSum){}