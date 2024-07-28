#include "../../include/Time/Schedule.h"


  // ----------------------------------------------------------------------------------------------
  // CONSTRUCTOR'S:
  // ----------------------------------------------------------------------------------------------  

  Schedule::Schedule(/*int newDoctorID*/)
    : scheduledAppointments(), workSchedule() {} 
    
  Schedule::Schedule(ScheduledAppointments newScheduledAppointments)
    : scheduledAppointments(newScheduledAppointments), workSchedule() {}

  Schedule::Schedule(WorkSchedule newWorkSchedule)
    : scheduledAppointments(), workSchedule(newWorkSchedule) {}

  Schedule::Schedule(ScheduledAppointments newScheduledAppointments, WorkSchedule newWorkSchedule)
    : scheduledAppointments(newScheduledAppointments), workSchedule(newWorkSchedule) {}

  // ----------------------------------------------------------------------------------------------
  // GETTER'S:
  // ----------------------------------------------------------------------------------------------

  ScheduledAppointments Schedule::getScheduledAppointments() { return scheduledAppointments; }

  WorkSchedule Schedule::getWorkSchedule() { return workSchedule; } 
  
  // ----------------------------------------------------------------------------------------------
  // ANOTHER STUFF:
  // ----------------------------------------------------------------------------------------------

  WorkSchedule Schedule::avaiableSessions(){
    WorkSchedule avaiableSessions = workSchedule; 
    for(Appointment app : scheduledAppointments.getAppointments()){
      if(not isOneAvaiableStatus(app.getStatus())){
        avaiableSessions.removeSession(app.getSession()); 
      }      
    }
    return avaiableSessions;
  }

  bool Schedule::checkAvaiability(Session checkMe){
    if(checkMe.isIn(avaiableSessions().getWorkSchedule())){
      return true;
    }
    return false;
  } 

  void Schedule::makeAppointment(Appointment addMe){
    if(checkAvaiability(addMe.getSession())){
      scheduledAppointments.safeAdd(addMe); 
      //Método certo pra conferir as coisas no BD!!!
    }
    else{
      // Deu erro!!!!
    }

  }
  
  Session Schedule::nextAvaiableSession(){
    Date date(-1, -1, -1); Time time(-1, -1, -1);
    Session candidate(time, date); 
    if(avaiableSessions().getWorkSchedule().size() == 0) { return candidate; }

    candidate = avaiableSessions().getWorkSchedule()[0];
    for(WorkSession wSession : avaiableSessions().getWorkSchedule()){
      if(wSession.isBeforeThan(candidate)){
        candidate = wSession;
      }
    }

    return candidate;    
  }

  // SORT'S ???