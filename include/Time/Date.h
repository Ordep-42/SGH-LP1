// Date.h
#ifndef DATE_H
#define DATE_H

#include <string>

using namespace std;

class Date {
private:
  short days;
  short year;
  bool isLeapYear;
  // void fixDate();

public:
  Date(short newDays, short newYear);
  Date(short newDay, short Month, short newYear); // um pouco de overloading n faz mal... 
  Date() = default;

  void fixDate();

  short getDay() const;
  short getMonth() const;
  short getYear() const;
  short getDays() const;
  string toString();

  bool isBeforeThan(Date thisDate);
  bool isEqualTo(Date anotherDate);
  bool isBetween(Date date1, Date date2);
  Date tomorrow();
};

// Funções auxiliares
Date firstDate(Date date1, Date date2);
Date lastDate(Date date1, Date date2);
bool leapYearTest(short year);
short *daysToDateBF(short day, short year);
short dateToDaysBF(short day, short month, short year);
Date stringToDate(string convertMe);
// Date(short newDay, short Month, short newYear);

#endif // DATE_H