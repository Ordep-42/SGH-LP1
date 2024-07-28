#ifndef WORKSCHEDULE_H
#define WORKSCHEDULE_H

#include "WorkSession.h"

using namespace std;

class WorkSchedule : public Session {
  private:
    vector<WorkSession> schedule;

  public:
    // Construtores*
    WorkSchedule(
        /*vector<WorkSession> newSchedule, int newId, int newDoctor_id*/);
    WorkSchedule(
        vector<WorkSession> newSchedule /*, int newId, int newDoctor_id*/);
    // Getters para os novos atributos

    // int getID(); // Daria pra ser const
    // int getDoctorID();
    vector<WorkSession> getWorkSchedule(); // Esse nome fica estranho...

    // getHoraInicio() =  getSession().getTime();
    // getHoraFinal() = getSession().getTime().sum(Time time(0,0,definido));
    bool testSession(Session testSession);

    // Fazer overload pra facilitar chamados igual na ScheduledAppointments

    // TIME:
    WorkSchedule searchByTime(Time thatTime);
    WorkSchedule searchByTimeAfter(Time thatTime);
    WorkSchedule searchByTimeBefore(Time thatTime);
    WorkSchedule searchByTimeBetween(Time time1, Time time2);

    // DATE:
    WorkSchedule searchByDate(Date thatDate);
    WorkSchedule searchByDateAfter(Date thatDate);
    WorkSchedule searchByDateBefore(Date thatDate);
    WorkSchedule searchByDateBetween(Date date1, Date date2);

    // ANOTHER STUFF:
    WorkSchedule searchByID(int id);
    WorkSchedule removeWS(WorkSession removeMe);
    WorkSchedule removeSession(Session removeMe);
    WorkSession lastSession();     // pelo vetor
    WorkSession nextWorkSection(); // pela data X time
    void safeAdd(WorkSession addMe);
    void safeAdd(vector<WorkSession> addMe);
    // WorkSchedule searchByStatus();
    // Appointment nextAppointment();
    // Pra marcar uma consulta:
    // Section nextAvaiableSection();
    /// Sorts:
};

#endif // WORKSCHEDULE_H
