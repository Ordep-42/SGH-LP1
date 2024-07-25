WorkSchedule WorkSchedule::searchByStatus(string testStatus){
    vector<WorkSession> vetorWS;  
    for(WorkSession wSession : schedule){
        if(wSession.getStatus() == testStatus){
            vetorWS.push_back(wSession);   
        }
    } 
    // Sem ser um vetor vamos ter mais dados, vai que, né... 
    WorkSchedule scheduleByPatient(vetorWS, id, doctor_id); 
    return scheduleByPatient;
}



// #include "../include/Schedule.h"
// #include <algorithm>
// #include <vector>

// //Schedule() = default;

//  vector<Appointment> Schedule::getSchldApptms() { return scheduledAppointments; }
//  vector<Section> Schedule::getWorkSchld() { return workSchedule; }

// // confira se é seguro chamar esse método antes de o chamar
// void Schedule::makeAppointment(Appointment newAppointment) { scheduledAppointments.push_back(newAppointment); }

// // depois mudamos como lidar com os Id's
// vector<Appointment> Schedule::searchByPatient(int byPatientID){
//   vector<Appointment> patientAppointments; 
//   for(Appointment appointment : patientAppointments){
//     if(appointment.patientID == byPatientID) { patientAppointments.push_back(appointment); }
//   }
  
//   return patientAppointments;
// }

// //Schedule searchByTime();

// vector<Appointment> Schedule::searchByDate(){
//   return scheduledAppointments;
// }

// vector<Appointment> Schedule::searchByStatus(){
//   return scheduledAppointments;
// }



// bool Schedule::isAppointed(Section test){ //nome meme, pse...
//    for(Appointment appointment : scheduledAppointments){
//     if(sectionEquals(appointment.section, test)) { return true; } //Falta verificar o status da consulta!!!
//   }

//   return false;
// } 

// Section Schedule::nextWorkSection(){ // o mais recente em tempo
//   Time timeC(-1,-1,-1); Date dataC(-1, -1); 
//   Section sectionC(timeC, dataC); // de Candidate
//   if(workSchedule.size() == 0) { return sectionC; }
  
//   sectionC.date = workSchedule[0].date; sectionC.time = workSchedule[0].time;   
//   for(Section section : workSchedule){
//     if(sectionIsBeforethan(section, sectionC)){ 
//       sectionC.date = section.date; sectionC.time = section.time; 
//     }
//   }

//   return sectionC;  
// }

// // Pro médico conferir, sei lá... Tbm vai servir pra uma outra função chamar.
// Appointment Schedule::nextAppointment(){
//   Time timeC(-1,-1,-1); Date dataC(-1, -1); 
//   Section sectionC(timeC, dataC); // de Candidate
//   Appointment appointmentC(sectionC, "erro", -1);
//   if(scheduledAppointments.size() == 0) { return appointmentC; }
  
//   appointmentC = scheduledAppointments[0];
//   for(Appointment appointment : scheduledAppointments){
//     if(sectionIsBeforethan(appointment.section, appointmentC.section)){ // FALTA VERIFICAR O STATUS!!!! 
//       appointmentC = appointment;
//     }
//   }
  
//   return appointmentC;
// }

// Section Schedule::nextAvaiableSection(){
//   Time timeC(-1,-1,-1); Date dateC(-1, -1); 
//   Section sectionC(timeC, dateC); // de Candidate 
//   if(workSchedule.size() == 0){ return sectionC; }

//   vector<Section> sectionsToTry; sectionsToTry.assign(workSchedule.begin(), workSchedule.end());
  
//   while(sectionsToTry.size() > 0){
//     sectionC = nextSection(sectionsToTry);
//     if(not isAppointed(sectionC)) { return sectionC; }
//     sectionsToTry = removeSection(sectionsToTry, sectionC);
//   }

//   sectionC.time = timeC; sectionC.date = dateC;
//   return sectionC; 
// }

// // sortByDate!!