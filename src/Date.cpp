// Date.cpp
#include "../include/Date.h"

// Construtor:

Date::Date(short newDays, short newYear)
    : days(newDays), year(newYear), isLeapYear(leapYearTest(year)) {
    this->fixDate();
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

bool Date::isBeforeThan(Date thisDate) {
    // this->fixDate();
    // thisDate.fixDate();
    if (this->year > thisDate.getYear()) {
        return false;
    } else if (this->year == thisDate.getYear()) {
        if (this->days >= thisDate.getDays()) {
            return false;
        }
    }
    return true;
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

bool Date::isEqualTo(Date anotherDate){
  fixDate(); anotherDate.fixDate();
  if(days == anotherDate.getDays() && year == anotherDate.getYear()){
    return true;
  }
  else{
    return false;
  }
}