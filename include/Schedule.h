#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "User.h"
#include "Time.h"
#include <string>
#include <vector>

using namespace std;

struct Appointment {
    // preciso por "const" aqui??
    int id; // Essa necessidade vai aparecer
    Time time;
    Date date;  
    string status; // confirmado, cancelado ou "aguardando", por ex.
    int patientID;// alternativamente, poderia ser o cpf.
    /* O objetivo aqui é ter uma forma do médico puxar a ficha dum
    paciente só pela agenda. */

    // versão alternativa:
    //int doctorID 
    /* Aqui é para uma atendente poder puxar a agenda de um 
    médico, por ex, pra informar que dias ele ainda 
    tem disponíveis.*/

    //int room;
    //No nosso hospital, cada médico só atende numa única sala :)     

  Appointment(const Time &newTime, const Date &newDate, string newStatus, const int &newID)
      : time(newTime), date(newDate) {}
};

class Schedule {
private:
 vector<Appointment> schedule; 
 //int doctorID; 
 /* Aqui é para uma atendente poder puxar a agenda de um 
    médico, por ex, pra informar que dias ele ainda 
    tem disponíveis.*/


public:
  Schedule() = default;


};

// Funções auxiliares


#endif // !SCHEDULE_H
