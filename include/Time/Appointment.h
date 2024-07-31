#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include "Session.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Appointment {
  private:
    int id;
    Session session;
    string status; // Marcada, confirmada, cancelada Xou finalizada

    int patientID;
    int doctorID;
    string procedure; // Exame Xou consulta, apenas.

  public:
    Appointment(Session newSession, string newStatus, int newPatientID,
                int newDoctorID, string newProcedure);
    Appointment(int newID, Session newSession, string newStatus,
                int newPatientID, int newDoctorID, string newProcedure);

    // getters:
    int getId();

    Session getSession();
    string getStatus();
    int getPatientID();
    int getDoctorID();
    string getProcedure();

    // setters:
    void setStatus(string newStatus); // precisa conferir se é um status válido

    // Métodos:
    vector<string> toString() {
        vector<string> appString(7);

        appString[0] = "Appointment ID: " + id;
        appString[0] += id;

        appString[1] = "Status: ";
        appString[1] += status;

        appString[2] = "Patient ID: ";
        appString[2] += patientID;

        appString[3] = "Doctor ID: ";
        appString[3] += doctorID;

        appString[4] = "Procedure: ";
        appString[4] += procedure;

        appString[5] = "Session Date: ";
        appString[5] += this->session.getDateString();

        appString[6] = "Session Time: ";
        appString[6] += session.getTimeString();

        return appString;
    }

    string toLINEARString() {
        vector<string> lineMe = toString();
        string returnMe = "";
        for (string thing : lineMe) {
            returnMe += thing + " | ";
        }

        return returnMe;
    }

    // vou nem testar nmrl
    void printAppointment() {
        vector<string> printMe = toString();
        for (int i = 0; i < printMe.size(); i++) {
            cout << printMe[i] << endl;
        }
    }

    /* esse ficou
    void printAppointment() {
        cout << "Appointment ID: " << id << endl;
        cout << "Status: " << status << endl;
        cout << "Patient ID: " << patientID << endl;
        cout << "Doctor ID: " << doctorID << endl;
        cout << "Procedure: " << procedure << endl;
        cout << "Session Date: " << this->session.getDateString() << endl;
        cout << "Session Time: " << session.getTimeString() << endl;
    }  */
};

// Funções auxiliares
bool isOneAvaiableStatus(string checkMe);

#endif // !APPOINTMENT_H
