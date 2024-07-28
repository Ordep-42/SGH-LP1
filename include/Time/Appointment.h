#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include "Session.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Appointment {
  private:
    int id ; 
    Session session;
    string status; // Marcada, confirmada, cancelada Xou finalizada
   
    int patientID;
    int doctorID;
    string procedure; //Exame Xou consulta, apenas. 

  public:
    Appointment(int newID, Session newSession, string newStatus, int newPatientID, int newDoctorID, string newProcedure); 
    Appointment(int newID, Session newSession, int newPatientID, int newDoctorID, string newProcedure);
    Appointment(int newID, Time newTime, Date newDate, int newPatientID, int newDoctorID, string newProcedure);
    Appointment() = default;

    //getters: 
    int getId(); 
    Session getSession();
    string getStatus();
    int getPatientID();
    int getDoctorID();
    string getProcedure();

    // setters:
    void setStatus(string newStatus); // precisa conferir se é um status válido

    // Métodos:
    void printAppointment() {
        cout << "Appointment ID: " << id << endl;
        cout << "Status: " << status << endl;
        cout << "Patient ID: " << patientID << endl;
        cout << "Doctor ID: " << doctorID << endl;
        cout << "Procedure: " << procedure << endl;
        cout << "Session Date: " << this->session.getDateString() << endl;
        cout << "Session Time: " << session.getTimeString() << endl;
    }
};

// Funções auxiliares
bool isOneAvaiableStatus(string checkMe);

#endif // !APPOINTMENT_H
