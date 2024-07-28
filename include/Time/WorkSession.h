#ifndef WORKSESSION_H
#define WORKSESSION_H

#include "Session.h"

class WorkSession : public Session {
  private:
    int id;
    int doctor_id;

  public:
    // Construtor
    WorkSession(Time newTime, Date newDate, int newId, int newDoctorId);
    WorkSession() = default;

    // Getters para os novos atributos
    int getId();
    int getDoctorId();

    // getHoraInicio() =  getSession().getTime();
    // getHoraFinal() = getSession().getTime().sum(Time time(0,0,definido));

    // Outros métodos herdados da Session podem ser usados diretamente
    // IsEqual??
};

#endif // WORKSESSION_H
