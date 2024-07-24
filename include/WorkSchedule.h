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
    
    int getID(); // Daria pra ser const
    int getDoctorID();
    vector<WorkSession> getWorkSchedule(); // Esse nome fica estranho...

    //getHoraInicio() =  getSession().getTime(); 
    //getHoraFinal() = getSession().getTime().sum(Time time(0,0,definido));

    WorkSchedule searchByTime();
    WorkSchedule searchByID(int id);
    WorkSchedule searchByDate();
    WorkSchedule searchByStatus();

    WorkSession lastSession(); // pelo vetor
    WorkSession nextWorkSection(); //pela data X time
    //Appointment nextAppointment();
    // Pra marcar uma consulta: 
    //Section nextAvaiableSection();
};

#endif // WORKSCHEDULE_H