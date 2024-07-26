#ifndef SCHEDULEDAPPOINTMENTS_H
#define SCHEDULEDAPPOINTMENTS_H

#include "Appointment.h"
#include <string>
#include <vector>

using namespace std;

class ScheduledAppointments {
  private:
    int id;
    vector<Appointment> appointments;
    int doctor_id; //??
    // se colocar doctor id, vai ter q fazer um vetor de scheduled appointments
    // pra acessar o de todos os medicos, oq é bem viavel.

  public:
    ScheduledAppointments(int id, vector<Appointment> appointments,
                          int doctor_id);
    ScheduledAppointments(int id, int doctor_id);
    ScheduledAppointments() = default;

    // GETTERS:
    int getId();
    ScheduledAppointments getAppointments();
    int getDoctorId();

    // SEARCH'S:
    bool checkSessionPresence(Session testMe);
    bool testSessionAvaiability(Session testMe);
    vector<Appointment> searchByPatient(int byPatientID);
    // Schedule searchByTime();
    // Schedule searchById();
    vector<Appointment> searchByDate();
    vector<Appointment> searchByStatus();

    // ANOTHER STUFF:
    void safeAdd(Appointment addMe);
    void safeAdd(vector<Appointment> addMe);
    bool isAppointed(Session test);
    Appointment nextAppointment();
    Appointment lastAppointment();

    // Pra marcar uma consulta:
    // Session nextAvaiableSection();
    // make appointment
};

// Funções auxiliares

#endif // !APPOINTMENT_H

/*

#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "Time.h"
#include "User.h"
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
    string status; // confirmado, cancelado ou "aguardando", livre com todos os
codigos sendo -1 e coisas assim, por ex. int patientID;// alternativamente,
poderia ser o cpf.
    /* O objetivo aqui é ter uma forma do médico puxar a ficha dum
    paciente só pela agenda. */

// versão alternativa:
// int doctorID
/* Aqui é para uma atendente poder puxar a agenda de um
médico, por ex, pra informar que dias ele ainda
tem disponíveis.*/

// int room;
// No nosso hospital, cada médico só atende numa única sala :)
/*
  Appointment(const Section& newSection, string newStatus, const int& newID)
      : section(newSection) {}
};



class Schedule {
private:
 vector<Appointment> scheduledAppointments;
 vector<Section>     workSchedule; // doctorSchedule vai ser o nome bom do
atributo na classe doctor :D
 //que surjam mais atributos :pray:
 //int doctorID;
 /* Aqui é para uma atendente poder puxar a agenda de um
    médico, por ex, pra informar que dias ele ainda
    tem disponíveis.*/
/*

public:

  vector<Appointment> getSchldApptms();
  vector<Section> getWorkSchld();

  //void setWorkSchld(vector<Section> newWorkSchld);

  Schedule() = default;

  //bool checkAvailability(Date tryDate, Time tryTime); // tryDate to the
CatchTime ;)




};

// Funções auxiliares


#endif // !SCHEDULE_H


   */
