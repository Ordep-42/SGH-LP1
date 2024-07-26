#ifndef HOSPITAL_DATABASE_H
#define HOSPITAL_DATABASE_H

#include "../Time/Date.h"
#include "../Users/Doctor.h"
#include "../Users/Manager.h"
#include "../Users/User.h"
#include <set>
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

    static void setDBPointer(sqlite3 *);
    static void setErrMsg(char *);
    static void setReturnCode(int);

    static void createPatient(User patient);
    static void listPatients();
    static void deletePatient(short unsigned);

    static void createDoctor(Doctor);
    static set<int> listDoctors();
    static void deleteDoctor(short unsigned);

    static void createAppointment(User doctor, User patient, Date);
    static void listAppointments();
    static void listAppointmentsByDoctor();
    static void listAppointmentsByPatient();
    static void listAppointmentsByDate();
    static void deleteAppointment(short unsigned);

    static void createAttendant(User);
    static void listAttendants();
    static void deleteAttendant(short unsigned);

    static void createManager(Manager);
    static void listManagers();
    static void deleteManager(short unsigned);

    string getScheduleByDate(Date);
    string getScheduleBetweenDates(Date, Date);
    static vector<string> getAppointmentsByDoctor(short unsigned);

    static bool verifyErrorCode();
};

#endif // !HOSPITAL_DATABASE_H
