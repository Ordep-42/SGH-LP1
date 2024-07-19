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

  public:
    HospitalDatabase();

    sqlite3 *getDBPointer();
    char *getErrMsg();
    int getReturnCode();

    void setDBPointer(sqlite3 *);
    void setErrMsg(char *);
    void setReturnCode(int);

    string getAgenda();

    string getAgendaByPatient(User);

    string getAgendaByDoctor(User);

    string getAgendaByDate(Date);

    string getAgendaBetweenDates(Date, Date);
};

#endif // !HOSPITAL_DATABASE_H
