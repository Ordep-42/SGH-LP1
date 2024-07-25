// Date.h
#ifndef DATE_H
#define DATE_H

class Date {
private:
  short days;
  short year;
  bool isLeapYear;
  // void fixDate();

public:
  Date(short newDays, short newYear);
  Date() = default;

  void fixDate();

  short getDay() const;
  short getMonth() const;
  short getYear() const;
  short getDays() const;

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


#endif // DATE_H