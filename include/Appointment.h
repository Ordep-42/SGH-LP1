#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <Session.h>
#include <string>
#include <vector>

using namespace std;

class Appointment {
private:
    int id; 
    Session session;
    string status; // Marcada, confirmada, cancelada Xou finalizada
    //short room;
    int patientId;
    int doctorId;
    string procedure; //Exame Xou consulta, apenas. 

public:
    Appointment() = default;
    // Métodos?? 

};

// Funções auxiliares


#endif // !APPOINTMENT_H
