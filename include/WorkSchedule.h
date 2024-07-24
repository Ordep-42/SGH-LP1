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

    // Outros métodos herdados da Session podem ser usados diretamente
};

#endif // WORKSCHEDULE_H