#ifndef HOSPITAL_DATABASE_H
#define HOSPITAL_DATABASE_H

#include "Date.h"
#include "User.h"
#include <sqlite3.h>
#include <string>
#include <vector>

class Schedule {};

class HospitalDatabase {
  private:
    sqlite3 *db;
    sqlite3_stmt *stmt;
    char *errMsg;
    int returnCode;
    string getFromSchedule(const char *);

  public:
    HospitalDatabase();

    sqlite3 *getDBPointer();
    char *getErrMsg();
    int getReturnCode();

    void setDBPointer(sqlite3 *);
    void setErrMsg(char *);
    void setReturnCode(int);

    void createPatient(User patient);
    void createDoctor(User doctor);
    void createAppointment(User doctor, User patient, Date);
    void createAttendant(User attendant);
    void createManager(User manager);

    string getSchedule();

    string getScheduleByPatient(User);

    string getScheduleByDoctor(User);

    string getScheduleByDate(Date);

    string getScheduleBetweenDates(Date, Date);
};

#endif // !HOSPITAL_DATABASE_H
