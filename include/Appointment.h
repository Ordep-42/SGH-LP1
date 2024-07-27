#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <Session.h>
#include <string>
#include <vector>

using namespace std;

class Appointment {
private:
    int id ; 
    Session session;
    string status; // Marcada, confirmada, cancelada Xou finalizada
    //const short room;
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

    //setters: 
    void setStatus(string newStatus); //precisa conferir se é um status válido!
    // Métodos?? 

};

// Funções auxiliares


#endif // !APPOINTMENT_H
