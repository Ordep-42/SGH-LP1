#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include "Session.h"
#include <string>
#include <vector>

using namespace std;

class Appointment {
  private:
    const int id;
    const Session session;
    string status; // Marcada, confirmada, cancelada Xou finalizada
    // const short room;
    const int patientID;
    const int doctorID;
    const string procedure; // Exame Xou consulta, apenas.

  public:
    Appointment() = default;

    // getters:
    int getId();
    Session getSession();
    string getStatus();
    int getPatientID();
    int getDoctorID();
    string getProcedure();

    // setters:
    void setStatus(string newStatus); // precisa conferir se é um status válido!
    // Métodos??
};

// Funções auxiliares

#endif // !APPOINTMENT_H
