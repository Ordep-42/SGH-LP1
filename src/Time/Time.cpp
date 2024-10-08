#include "../../include/Time/Time.h"
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

Time::Time(short newHour, short newMin, short newSec)
    : hour(newHour), minute(newMin), second(newSec) {
    fixTime();
}

Time::Time() : hour(-1), minute(-1), second(-1) {}

// getters:
short Time::getHour() { return hour; }
short Time::getMin() { return minute; }
short Time::getSec() { return second; }

// setters:
void Time::setHour(short newHour) { hour = newHour; }
void Time::setMin(short newMin) { minute = newMin; }
void Time::setSec(short newSec) { second = newSec; }

// resto:

void Time::fixHour() {
    while (hour >= 24)
        hour -= 24; // bizarrinho...
}

void Time::fixMin() {
    // int x, y;

    // if(minute >= 60) { x = -60; y = 1; b = minute >= 60 }
    // else { x = 60; y = -1; }
    // fix minuto >= 60

    while (minute >= 60) {
        minute -= 60;
        hour++;
    }

    // fix minute < 0;
    while (minute < 0) {
        minute += 60;
        hour--;
    }
}

void Time::fixSec() {

    while (second >= 60) {
        second -= 60;
        minute++;
    }

    // fix minute < 0;
    while (second < 0) {
        second += 60;
        minute--;
    }
}

// Precisei pensar em como lidar com "02:-42:05"
void Time::fixTime() {
    fixSec();
    fixMin();
    fixHour();
    if (hour < 0) {
        hour = -1;
        minute = -1;
        second = -1; /* Padrão pra saber qnd deu algum erro. */
    }
}

// Dá pra subtrair horas :)
// UM OVERLOAD CAIRIA BEM AQUI!!!
void Time::sumTime(Time toSum) {
    hour += toSum.getHour();
    minute += toSum.getMin();
    second += toSum.getSec();

    fixTime();
}

bool Time::isEqualTo(Time thatTime) {
    fixTime();
    thatTime.fixTime(); // fixers
    if (hour == thatTime.getHour() && minute == thatTime.getMin() &&
        second == thatTime.getSec()) {
        return true;
    } else {
        return false;
    }
}

bool Time::isBeforeThan(Time thatTime) {
    fixTime();
    thatTime.fixTime(); // fixers
    if (hour < thatTime.getHour()) {
        return true;
    }
    if (hour == thatTime.getHour() && minute < thatTime.getMin()) {
        return true;
    }
    if (hour == thatTime.getHour() && minute == thatTime.getMin() &&
        second < thatTime.getSec()) {
        return true;
    }
    return false;
}

Time firsTime(Time time1, Time time2) { // "min" binário
    if (time1.isBeforeThan(time2)) {
        return time1;
    }
    return time2;
}

Time lastTime(Time time1, Time time2) { // "max" binário
    if (time1.isBeforeThan(time2)) {
        return time2;
    }
    return time1;
}

bool Time::isBetween(
    Time time1, Time time2) { // Intervalo fechado (incluindo data 1 e data 2)
    Time first = firsTime(time1, time2);
    Time last = lastTime(time1, time2);
    if ((isBeforeThan(last) && first.isBeforeThan(*this)) || isEqualTo(first) ||
        isEqualTo(last)) { // talvez esse asterisco bugue muito no futuro...
                           // CUIDADO!!!
        return true;
    }
    return false;
}

string Time::toString() {
    string timeString = "";
    timeString += to_string(this->getHour()) + ":";
    timeString += to_string(this->getMin()) + ":";
    timeString += to_string(this->getSec());
    return timeString;
}

vector<string> splitString(string str, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(str);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

Time stringToTime(string convertMe) {
    vector<string> parts = splitString(convertMe, ':');

    if (parts.size() != 3) {
        throw invalid_argument("Invalid time format");
    }

    int hour = stoi(parts[0]);
    int minute = stoi(parts[1]);
    int second = stoi(parts[2]);

    Time newTime(hour, minute, second);
    return newTime;
}
