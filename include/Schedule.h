#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "User.h"
#include "Time.h"
#include <string>
#include <vector>

using namespace std;

struct Section {
  Time time;
  Date date; 

  Section(Time newTime, Date newDate) 
  : time(newTime), date(newDate) {}
};

struct Appointment {
    // preciso por "const" aqui??
    int id; // Essa necessidade vai aparecer??
    Section section;
    string status; // confirmado, cancelado ou "aguardando", livre com todos os codigos sendo -1 e coisas assim, por ex.
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

  Appointment(const Section &newSection, string newStatus, const int &newID)
      : section(newSection) {}
};



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

  void setWorkSchld(vector<Section> newWorkSchld);

  Schedule() = default;
  void makeAppointment(Appointment newAppointment);
  vector<Appointment> searchByPatient(int byPatientID);
  //Schedule searchByTime();
  //Schedule searchById();
  vector<Appointment> searchByDate();
  vector<Appointment> searchByStatus();
  
  bool checkAvailability(Date tryDate, Time tryTime); // tryDate to the CatchTime ;)
  bool isAppointed(Section test);

  Section nextWorkSection();
  Appointment nextAppointment();
  // Pra marcar uma consulta: 
  Section nextAvaiableSection();

};

// Funções auxiliares
Section lastSection(vector<Section> sections);

#endif // !SCHEDULE_H
