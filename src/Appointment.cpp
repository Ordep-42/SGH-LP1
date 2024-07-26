#include "Appointment.h"
#include <stdexcept>

using namespace std;

Appointment::Appointment(int newID, Session newSession, string newStatus, int newPatientID, int newDoctorID, string newProcedure)
    : id(newID), session(newSession), status(newStatus), patientID(newPatientID), doctorID(newDoctorID), procedure(newProcedure) {}

Appointment::Appointment(int newID, Session newSession, int newPatientID, int newDoctorID, string newProcedure)
    : id(newID), session(newSession), status("scheduled"), patientID(newPatientID), doctorID(newDoctorID), procedure(newProcedure) {}

// Getters
int Appointment::getId() { return id; }

Session Appointment::getSession() { return session; }

string Appointment::getStatus() { return status; }

int Appointment::getPatientID() { return patientID; }

int Appointment::getDoctorID() { return doctorID; }

string Appointment::getProcedure() { return procedure; }

// Setters
void Appointment::setStatus(string newStatus) {
    if (newStatus == "Marcada" || newStatus == "Confirmada" || newStatus == "Cancelada" || newStatus == "Finalizada") {
        status = newStatus;
    } else {
        throw invalid_argument("Status inválido!"); // isso aqui foi gpt, acho que basta colocar a propria string no status, mas oq eu sei, ne?
    }
}

// Métodos adicionais, se necessários, podem ser implementados aqui
