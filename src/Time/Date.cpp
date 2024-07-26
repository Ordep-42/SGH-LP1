// Date.cpp
#include "../../include/Time/Date.h"

using namespace std;

// ConstrutorES*:

Date::Date(short newDays, short newYear)
    : days(newDays), year(newYear), isLeapYear(leapYearTest(newYear)) {
    fixDate();
}

Date::Date(short newDay, short newMonth, short newYear)
    : days(dateToDaysBF(newDay, newMonth, newYear)), year(newYear),
      isLeapYear(leapYearTest(newYear)) {
    fixDate();
}

// ------------------------------------------------------------------------------
// Métodos:
// ------------------------------------------------------------------------------

bool leapYearTest(short year) {
    // Verifica se o ano é divisível por 4
    if (year % 4 == 0) {
        // Verifica se o ano não é divisível por 100, a menos que seja divisível
        // por 400
        if (year % 100 != 0 || year % 400 == 0) {
            return true; // Ano bissexto
        } else {
            return false; // Não é um ano bissexto
        }
    } else {
        return false; // Não é um ano bissexto
    }
}

// BF vem de "Brute Force"
short *daysToDateBF(short days, short year) {

    bool isLeapYear = leapYearTest(year);

    /*const*/ short daysInMonths[] = {31, 28, 31, 30, 31, 30,
                                      31, 31, 30, 31, 30, 31};
    if (isLeapYear)
        daysInMonths[1] = 29;

    // short daysCount = 0;
    short month = 0;

    // Itera pelos meses para determinar o mês e o dia correspondentes
    while (month < 12 && days > /*daysCount*/ daysInMonths[month]) {
        // daysCount += daysInMonths[month];
        days -= daysInMonths[month];
        month++;
    }
    // Calcula o dia do mês (fixed?)
    short justDay = days; // - daysCount;
    // Aloca memória para armazenar dia, mês e ano
    short *date = new short[3];
    date[0] = justDay;   // Dia
    date[1] = month + 1; // Mês (de 1 a 12)
    date[2] = year;      // Ano
    return date;
}

short dateToDaysBF(short day, short month, short year) {
    // Verifica se o ano é bissexto
    bool isLeapYear = leapYearTest(year);
    // Dias em cada mês (define fevereiro separadamente)
    short daysInMonths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear)
        daysInMonths[1] = 29;

    // Calcula o total de dias até o mês anterior ao fornecido
    int totalDays = 0;
    for (int i = 0; i < month - 1; ++i) {
        totalDays += daysInMonths[i];
    }
    // Adiciona os dias do próprio mês
    totalDays += day;
    return totalDays;
}

short Date::getDay() const {
    short *date = daysToDateBF(this->days, this->year);
    short day = date[0];

    delete[] date; // Comente esta linha se daysToDateBF NÃO aloca memória
                   // dinamicamente

    return day;
}

short Date::getMonth() const {
    short *date = daysToDateBF(this->days, this->year);
    short mounth = date[1];

    delete[] date; // Comente esta linha se daysToDateBF NÃO aloca memória
                   // dinamicamente

    return mounth;
}

short Date::getYear() const { return this->year; }

short Date::getDays() const { return this->days; }

//------------------------------------------
// É preciso pensar sobre oq fazer com isso:
//------------------------------------------
// void Date::setDay(unsigned char new_day) {
//     this->day = new_day;
//     this->fixDate();
// }

// void Date::setMonth(unsigned char new_month) {
//     this->month = new_month;
//     this->fixDate();
// }

// void Date::setYear(short new_year) {
//     this->year = new_year;
// }

bool Date::isBeforeThan(Date thatDate) {
    fixDate();
    thatDate.fixDate(); // fixers
    if (year > thatDate.getYear()) {
        return false;
    } else if (year == thatDate.getYear()) {
        if (days >= thatDate.getDays()) {
            return false;
        }
    }
    return true;
}

Date firstDate(Date date1, Date date2) { // "min" binário
    if (date1.isBeforeThan(date2)) {
        return date1;
    }
    return date2;
}

Date lastDate(Date date1, Date date2) { // "max" binário
    if (date1.isBeforeThan(date2)) {
        return date2;
    }
    return date1;
}

Date Date::tomorrow() {
    // Assim ficou mais seguro por causa dos ponteiros e blah blah blah
    Date newDate = Date(this->days + 1, this->year);
    newDate.fixDate();
    return newDate;
}

void Date::fixDate() {
    short daysInYear = (leapYearTest(this->year) ? 366 : 365);
    while (days > daysInYear) {
        days -= daysInYear;
        year++;
        daysInYear = (leapYearTest(this->year) ? 366 : 365);
    }
}

bool Date::isEqualTo(Date thatDate) {
    fixDate();
    thatDate.fixDate(); // fixers
    if (days == thatDate.getDays() && year == thatDate.getYear()) {
        return true;
    } else {
        return false;
    }
}

bool Date::isBetween(
    Date date1, Date date2) { // Intervalo fechado (incluindo data 1 e data 2)
    Date first = firstDate(date1, date2);
    Date last = lastDate(date1, date2);
    if ((isBeforeThan(last) && first.isBeforeThan(*this)) || isEqualTo(first) ||
        isEqualTo(last)) { // talvez esse asterisco bugue muito no futuro...
                           // CUIDADO!!!
        return true;
    }
    return false;
}

string Date::toString() {
    string dateString = "";
    // Dias
    if (getDay() < 10) {
        dateString += "0";
    }
    dateString += to_string(getDay()) + "/";
    // Mês
    if (getMonth() < 10) {
        dateString += "0";
    }
    dateString += to_string(getMonth()) + "/";
    // Ano
    if (getYear() < 1000) {
        dateString += "0";
    }
    if (getYear() < 100) {
        dateString += "0";
    }
    if (getYear() < 10) {
        dateString += "0";
    }
    dateString += to_string(getYear());

    return dateString;
}

Date stringToDate(string convertMe) {
    short day = stoi(convertMe.substr(0, 2));
    short month = stoi(convertMe.substr(3, 2));
    short year = stoi(convertMe.substr(6, 4));
    return Date(day, month, year);
}
