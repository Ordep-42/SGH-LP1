#include 

Schedule(); 
  Schedule(ScheduledAppointments newScheduledAppointments);
  Schedule(WorkSchedule newWorkSchedule);
  Schedule(ScheduledAppointments newScheduledAppointments, WorkSchedule newWorkSchedule);

  // Getter's:
  ScheduledAppointments getScheduledAppointments(); 
  WorkSchedule getWorkSchedule(); 
    
  bool checkAvailability(Session checkMe); // tryDate to the CatchTime ;)
  void makeAppointment(Appointment addMe);