#ifndef HOSPITAL_DATABASE_H
#define HOSPITAL_DATABASE_H

#include "Date.h"
#include "Doctor.h"
#include "User.h"
#include <sqlite3.h>
#include <string>
#include <vector>

class HospitalDatabase {
  public:
    static sqlite3 *db;
    static sqlite3_stmt *stmt;
    static char *errMsg;
    static int returnCode;
    string getFromSchedule(const char *);

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

    string getScheduleByDoctor(Doctor);

    string getScheduleByDate(Date);

    string getScheduleBetweenDates(Date, Date);

    static vector<string> getAppointmentsByDoctor(short unsigned);
};

#endif // !HOSPITAL_DATABASE_H
