#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "User.h"
#include "Time.h"
#include <string>
#include <vector>

using namespace std;



class Schedule {
private:
 vector<Appointment> scheduledAppointments;
 vector<Section>     workSchedule; // doctorSchedule vai ser o nome bom do atributo na classe doctor :D
 //que surjam mais atributos :pray:
 //int doctorID; 
 /* Aqui é para uma atendente poder puxar a agenda de um 
    médico, por ex, pra informar que dias ele ainda 
    tem disponíveis.*/


public:

  vector<Appointment> getSchldApptms(); 
  vector<Section> getWorkSchld(); 

  //void setWorkSchld(vector<Section> newWorkSchld);

  Schedule() = default;
    
  //bool checkAvailability(Date tryDate, Time tryTime); // tryDate to the CatchTime ;)
  

  

};

// Funções auxiliares


#endif // !SCHEDULE_H