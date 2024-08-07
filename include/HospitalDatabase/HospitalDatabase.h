#ifndef HOSPITAL_DATABASE_H
#define HOSPITAL_DATABASE_H

#include "../Time/Date.h"
#include "../Users/Doctor.h"
#include "../Users/Manager.h"
#include "../Users/Patient.h"
#include "../Users/User.h"
#include <optional>
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
    static optional<Patient> getPatientByID(int patientID);
    static optional<Patient> getPatientByNameAndPassword(string name,
                                                         string password);
    static void listPatients();
    static void deletePatient(short unsigned);
    static void updatePatient(short unsigned, string, string);
    static string getPatientData(short unsigned, string);

    static void createDoctor(Doctor);
    static optional<Doctor> getDoctorByID(int doctorID);
    static optional<Doctor> getDoctorByNameAndPassword(string name,
                                                       string password);

    static set<int> listDoctors();
    static void deleteDoctor(short unsigned);
    static bool validateDoctor(string name, string password);

    static void createAttendant(User);
    static optional<User> getAttendantByID(int attendantID);
    static optional<User> getAttendantByNameAndPassword(string name,
                                                        string password);
    static void listAttendants();
    static void deleteAttendant(short unsigned);

    static void createManager(Manager);
    static optional<Manager> getManagerByID(int attendantID);
    static optional<Manager> getManagerByNameAndPassword(string name,
                                                         string password);
    static void listManagers();
    static void deleteManager(short unsigned);

    static void createAppointment(Appointment newAppointment);
    static optional<Appointment> getAppointmentByID(int appointmentID);
    static void listAppointments();
    static void listAppointmentsByDoctor();
    static vector<Appointment> getAppointmentsByPatientID(int patientId);
    static vector<Appointment> getAppointmentsByDoctorID(int doctorID);
    static void listAppointmentsByDate();
    static void deleteAppointment(int);

    static optional<WorkSession> getWSessionByID(int WSessionID);
    static vector<WorkSession> getWorkSessionsByDoctorID(int doctorID);
    static void createWSession(int, Session);
    static void listWSessions();
    static void listWsessionByDoctor(int DoctorID);
    static void deleteWSession(int wSessionID);

    string getScheduleByDate(Date);
    string getScheduleBetweenDates(Date, Date);
    static vector<string> getAppointmentsByDoctor(short unsigned);
    static Schedule getScheduleByDoctorID(int doctorID);
    static set<int> getAllDoctors();

    static bool verifyErrorCode();
};

#endif // !HOSPITAL_DATABASE_H
