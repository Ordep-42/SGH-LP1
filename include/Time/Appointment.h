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
                   // const short room;
    int patientID;
    int doctorID;
    string procedure; // Exame Xou consulta, apenas.

  public:
    Appointment(string, int, int, string, Session);

    // getters:
    int getId();
    Session getSession();
    string getStatus();
    int getPatientID();
    int getDoctorID();
    string getProcedure();

    // setters:
    void setStatus(string newStatus); // precisa conferir se é um status válido
    void printAppointment() {
        cout << "Appointment ID: " << id << endl;
        cout << "Status: " << status << endl;
        cout << "Patient ID: " << patientID << endl;
        cout << "Doctor ID: " << doctorID << endl;
        cout << "Procedure: " << procedure << endl;
        cout << "Session Date: " << this->session.getDateString() << endl;
        cout << "Session Time: " << session.getTimeString() << endl;
    }
    // Métodos??
};

// Funções auxiliares

#endif // !APPOINTMENT_H
