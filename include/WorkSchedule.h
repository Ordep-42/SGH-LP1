#ifndef WORKSCHEDULE_H
#define WORKSCHEDULE_H

#include "WorkSession.h"

using namespace std;

class WorkSchedule : public Session {
private:
// Se sobrar: apaga.
    int id; 
    int doctor_id;
    vector<WorkSession> schedule; 

public:
    // Construtor
    WorkSchedule(vector<WorkSession> newSchedule, int newId, int newDoctor_id);
    // Getters para os novos atributos
    int getId(); // Daria pra ser const
    int getDoctorId();

    //getHoraInicio() =  getSession().getTime(); 
    //getHoraFinal() = getSession().getTime().sum(Time time(0,0,definido));

    WorkSchedule searchByPatient(int byPatientID);
    WorkSchedule searchByTime();
    WorkSchedule searchById();
    WorkSchedule searchByDate();
    WorkSchedule searchByStatus();

    Section lastSection(vector<Section> sections);
    // next
    Section nextWorkSection();
    Appointment nextAppointment();
    // Pra marcar uma consulta: 
    Section nextAvaiableSection();
};

#endif // WORKSCHEDULE_H