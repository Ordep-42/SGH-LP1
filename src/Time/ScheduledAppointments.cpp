#include "../../include/Time/ScheduledAppointments.h"
#include <optional>

using namespace std;

// --------------------------------------------------------------------------------------------
// CONSTRUCTOR'S:
// --------------------------------------------------------------------------------------------

ScheduledAppointments::ScheduledAppointments(
    /*int newID, int newDoctorID*/) // faltou garantir a integridade dos status
    : /*id(newID), doctor_id(newDoctorID), */ appointments() {}

ScheduledAppointments::ScheduledAppointments(
    /*int newID,*/ vector<Appointment> newAppointments /*, int newDoctorID*/)
    : /*id(newID), doctor_id(newDoctorID),*/ appointments() {
    safeAdd(newAppointments);
}
// --------------------------------------------------------------------------------------------
// GETTER'S:
// --------------------------------------------------------------------------------------------

// int ScheduledAppointments::getID() { return id; }
// int ScheduledAppointments::getDoctorID() { return doctor_id; }
vector<Appointment> ScheduledAppointments::getAppointments() {
    return appointments;
}

// --------------------------------------------------------------------------------------------
// ADD'S:
// --------------------------------------------------------------------------------------------

void ScheduledAppointments::safeAdd(Appointment addMe) {
    if (testSessionAvaiability(addMe.getSession())) {
        appointments.push_back(addMe);
    }
    return;
}

void ScheduledAppointments::safeAdd(vector<Appointment> addMe) {
    for (Appointment app : addMe) {
        safeAdd(app);
    }
    return;
}

// --------------------------------------------------------------------------------------------
// TEST'S:
// --------------------------------------------------------------------------------------------

// "check" teria sido um nome melhor??
bool ScheduledAppointments::testSessionPresence(Session testMe) {
    bool isIn = false;
    for (Appointment app : appointments) {
        if (app.getSession().isEqualTo(testMe)) {
            isIn = true;
        }
    }
    return isIn;
}

bool ScheduledAppointments::testSessionAvaiability(Session testMe) {
    bool isAvaiable = true;
    for (Appointment app : appointments) {
        if ((app.getSession().isEqualTo(testMe)) &&
            (not isOneAvaiableStatus(app.getStatus()))) {
            isAvaiable = false;
        }
    }
    return isAvaiable;
}

// nome alternativo e legal
bool ScheduledAppointments::isAppointed(Session test) {
    return testSessionAvaiability(test);
}

// --------------------------------------------------------------------------------------------
// SEARCH'S:
// --------------------------------------------------------------------------------------------

// TIME:
ScheduledAppointments ScheduledAppointments::searchByTime(Time thatTime) {
    ScheduledAppointments newSchedule;
    for (Appointment app : appointments) {
        if (app.getSession().getTime().isEqualTo(thatTime)) {
            newSchedule.getAppointments().push_back(app);
        }
    }

    return newSchedule;
}

ScheduledAppointments ScheduledAppointments::searchByTimeAfter(Time thatTime) {
    ScheduledAppointments newSchedule;
    for (Appointment app : appointments) {
        if (thatTime.isBeforeThan(app.getSession().getTime())) {
            newSchedule.getAppointments().push_back(app);
        }
    }

    return newSchedule;
}

ScheduledAppointments ScheduledAppointments::searchByTimeBefore(Time thatTime) {
    ScheduledAppointments newSchedule;
    for (Appointment app : appointments) {
        if (app.getSession().getTime().isBeforeThan(thatTime)) {
            newSchedule.getAppointments().push_back(app);
        }
    }

    return newSchedule;
}

ScheduledAppointments ScheduledAppointments::searchByTimeBetween(Time time1,
                                                                 Time time2) {
    ScheduledAppointments newSchedule;
    for (Appointment app : appointments) {
        if (app.getSession().getTime().isBetween(time1, time2)) {
            newSchedule.getAppointments().push_back(app);
        }
    }

    return newSchedule;
}

// DATE:
ScheduledAppointments ScheduledAppointments::searchByDate(Date thatDate) {
    ScheduledAppointments newSchedule;
    for (Appointment app : appointments) {
        if (app.getSession().getDate().isEqualTo(thatDate)) {
            newSchedule.getAppointments().push_back(app);
        }
    }

    return newSchedule;
}

ScheduledAppointments ScheduledAppointments::searchByDateAfter(Date thatDate) {
    ScheduledAppointments newSchedule;
    for (Appointment app : appointments) {
        if (thatDate.isBeforeThan(app.getSession().getDate())) {
            newSchedule.getAppointments().push_back(app);
        }
    }

    return newSchedule;
}

ScheduledAppointments ScheduledAppointments::searchByDateBefore(Date thatDate) {
    ScheduledAppointments newSchedule;
    for (Appointment app : appointments) {
        if (app.getSession().getDate().isBeforeThan(thatDate)) {
            newSchedule.getAppointments().push_back(app);
        }
    }

    return newSchedule;
}

ScheduledAppointments ScheduledAppointments::searchByDateBetween(Date date1,
                                                                 Date date2) {
    ScheduledAppointments newSchedule;
    for (Appointment app : appointments) {
        if (app.getSession().getDate().isBetween(date1, date2)) {
            newSchedule.getAppointments().push_back(app);
        }
    }

    return newSchedule;
}

// APPOINTMENT ATRBTS:
ScheduledAppointments
ScheduledAppointments::searchByPatient(int thatPatientID) {
    ScheduledAppointments newSchedule;
    for (Appointment app : appointments) {
        if (app.getPatientID() == thatPatientID) {
            newSchedule.getAppointments().push_back(app);
        }
    }

    return newSchedule;
}
ScheduledAppointments
ScheduledAppointments::searchByAppointmentId(int thatAppointmentID) {
    ScheduledAppointments newSchedule;
    for (Appointment app : appointments) {
        if (app.getId() == thatAppointmentID) {
            newSchedule.getAppointments().push_back(app);
        }
    }

    return newSchedule;
}

ScheduledAppointments ScheduledAppointments::searchByStatus(string thatStatus) {
    ScheduledAppointments newSchedule;
    for (Appointment app : appointments) {
        if (app.getStatus() == thatStatus) {
            newSchedule.getAppointments().push_back(app);
        }
    }

    return newSchedule;
}

ScheduledAppointments
ScheduledAppointments::searchByProcedure(string thatProcedure) {
    ScheduledAppointments newSchedule;
    for (Appointment app : appointments) {
        if (app.getProcedure() == thatProcedure) {
            newSchedule.getAppointments().push_back(app);
        }
    }

    return newSchedule;
}

optional<Appointment> ScheduledAppointments::nextAppointment() {
    if (appointments.size() == 0) {
        return nullopt;
    }

    Appointment candidateAppointment = appointments[0];
    for (Appointment app : appointments) {
        if (app.getSession().isBeforeThan(candidateAppointment.getSession())) {
            candidateAppointment = app;
        }
    }

    return candidateAppointment;
}

Appointment ScheduledAppointments::lastAppointment() {
    return appointments[appointments.size() - 1];
}


ScheduledAppointments ScheduledAppointments::AppointmentsToHappen(){
    vector<Appointment> filterMe = getAppointments();
    vector<Appointment> newScheduledAppointments;
    for(Appointment app : filterMe){
        if(app.getStatus() != "conclude" && app.getStatus() != "canceled"){
            newScheduledAppointments.push_back(app);
        }
    }
    return newScheduledAppointments;
}
// WorkSchedule WorkSchedule::searchByStatus(string testStatus){
//     vector<WorkSession> vetorWS;
//     for(WorkSession wSession : schedule){
//         if(wSession.getStatus() == testStatus){
//             vetorWS.push_back(wSession);
//         }
//     }
//     // Sem ser um vetor vamos ter mais dados, vai que, né...
//     WorkSchedule scheduleByPatient(vetorWS, id, doctor_id);
//     return scheduleByPatient;
// }

// #include "../include/Schedule.h"
// #include <algorithm>
// #include <vector>

// //Schedule() = default;

//  vector<Appointment> Schedule::getSchldApptms() { return
//  scheduledAppointments; } vector<Section> Schedule::getWorkSchld() {
//  return workSchedule; }

// // confira se é seguro chamar esse método antes de o chamar
// void Schedule::makeAppointment(Appointment newAppointment) {
// scheduledAppointments.push_back(newAppointment); }

//   return false;
// }

// Section Schedule::nextWorkSection(){ // o mais recente em tempo
//   Time timeC(-1,-1,-1); Date dataC(-1, -1);
//   Section sectionC(timeC, dataC); // de Candidate
//   if(workSchedule.size() == 0) { return sectionC; }

//   sectionC.date = workSchedule[0].date; sectionC.time =
//   workSchedule[0].time; for(Section section : workSchedule){
//     if(sectionIsBeforethan(section, sectionC)){
//       sectionC.date = section.date; sectionC.time = section.time;
//     }
//   }

//   return sectionC;
// }

// // Pro médico conferir, sei lá... Tbm vai servir pra uma outra função
// chamar. Appointment Schedule::nextAppointment(){
//   Time timeC(-1,-1,-1); Date dataC(-1, -1);
//   Section sectionC(timeC, dataC); // de Candidate
//   Appointment appointmentC(sectionC, "erro", -1);
//   if(scheduledAppointments.size() == 0) { return appointmentC; }

//   appointmentC = scheduledAppointments[0];
//   for(Appointment appointment : scheduledAppointments){
//     if(sectionIsBeforethan(appointment.section, appointmentC.section)){
//     // FALTA VERIFICAR O STATUS!!!!
//       appointmentC = appointment;
//     }
//   }

//   return appointmentC;
// }

// Section Schedule::nextAvaiableSection(){
//   Time timeC(-1,-1,-1); Date dateC(-1, -1);
//   Section sectionC(timeC, dateC); // de Candidate
//   if(workSchedule.size() == 0){ return sectionC; }

//   vector<Section> sectionsToTry;
//   sectionsToTry.assign(workSchedule.begin(), workSchedule.end());

//   while(sectionsToTry.size() > 0){
//     sectionC = nextSection(sectionsToTry);
//     if(not isAppointed(sectionC)) { return sectionC; }
//     sectionsToTry = removeSection(sectionsToTry, sectionC);
//   }

//   sectionC.time = timeC; sectionC.date = dateC;
//   return sectionC;
// }

// // sortByDate!!
