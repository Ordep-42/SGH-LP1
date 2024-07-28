#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "WorkSchedule.h"
#include "ScheduledAppointments.h"
#include <string>
#include <vector>

using namespace std;



class Schedule {
private:
 ScheduledAppointments scheduledAppointments;
 WorkSchedule workSchedule; // doctorSchedule vai ser o nome bom do atributo na classe doctor :D
 //que surjam mais atributos :pray:
 //int doctorID; 
 /* Aqui é para uma atendente poder puxar a agenda de um 
    médico, por ex, pra informar que dias ele ainda 
    tem disponíveis.*/


public:

  // Constructor's:
  Schedule(/*int newDoctorID*/); 
  Schedule(ScheduledAppointments newScheduledAppointments);
  Schedule(WorkSchedule newWorkSchedule);
  Schedule(ScheduledAppointments newScheduledAppointments, WorkSchedule newWorkSchedule);

  // Getter's:
  ScheduledAppointments getScheduledAppointments(); 
  WorkSchedule getWorkSchedule(); 
  // Poderia ter um doctorID, mas sobraria ainda mais
    
  WorkSchedule avaiableSessions();
  bool checkAvaiability(Session checkMe); // tryDate to the CatchTime ;)
  void makeAppointment(Appointment addMe);
  Session nextAvaiableSession();
  

};

// Funções auxiliares


#endif // !SCHEDULE_H