#ifndef TIME_H
#define TIME_H

#include <string>
#include <vector>

using namespace std;
// Fiz 4fun msm. Devia ter uns mlres na net :P Mas nem deu trabai

class Time {
private:
    short hour;
    short minute;
    short second; 

public:
    Time(short newHour, short newMin, short newSec);
    Time();

    //getters:
    short getHour();
    short getMin();
    short getSec();
    string toString();
    //setters: 
    void setHour(short newHour); 
    void setMin(short newMin); 
    void setSec(short newSec); 

    //resto: 
    void fixSec();
    void fixMin();   
    void fixHour(); 
    void fixTime();
    void sumTime(Time toSum);

    bool isEqualTo(Time anotherTime);
    bool isBeforeThan(Time thisTime);

    bool isBetween(Time time1, Time time2);

};

// Funções auxiliares
Time firsTime(Time time1, Time time2);
Time lastTime(Time time1, Time time2);
Time stringToTime(string convertMe);


#endif // !TIME_H
