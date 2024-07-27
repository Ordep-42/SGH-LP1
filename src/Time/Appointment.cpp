#include "../../include/Time/Appointment.h"
#include <stdexcept>

using namespace std;

Appointment::Appointment(string status, int patientID, int doctorID,
                         string procedure, Session session) {
    this->status = status;
    this->patientID = patientID;
    this->doctorID = doctorID;
    this->session = session;
    this->procedure = procedure;
}

// Getters
int Appointment::getId() { return id; }

Session Appointment::getSession() { return session; }

string Appointment::getStatus() { return status; }

int Appointment::getPatientID() { return patientID; }

int Appointment::getDoctorID() { return doctorID; }

string Appointment::getProcedure() { return procedure; }

// Setters
void Appointment::setStatus(string newStatus) {
    if (newStatus == "Marcada" || newStatus == "Confirmada" ||
        newStatus == "Cancelada" || newStatus == "Finalizada") {
        status = newStatus;
    } else {
        throw invalid_argument(
            "Status inválido!"); // isso aqui foi gpt, acho que basta colocar a
                                 // propria string no status, mas oq eu sei, ne?
    }
}

// Métodos adicionais, se necessários, podem ser implementados aqui
