#include "../include/Schedule.h"
#include <algorithm>
#include <vector>

//Schedule() = default;

 vector<Appointment> Schedule::getSchldApptms() { return scheduledAppointments; }
 vector<Section> Schedule::getWorkSchld() { return workSchedule; }

// confira se é seguro chamar esse método antes de o chamar
void Schedule::makeAppointment(Appointment newAppointment) { scheduledAppointments.push_back(newAppointment); }

// depois mudamos como lidar com os Id's
vector<Appointment> Schedule::searchByPatient(int byPatientID){
  vector<Appointment> patientAppointments; 
  for(Appointment appointment : patientAppointments){
    if(appointment.patientID == byPatientID) { patientAppointments.push_back(appointment); }
  }
  
  return patientAppointments;
}

//Schedule searchByTime();

vector<Appointment> Schedule::searchByDate(){
  return scheduledAppointments;
}

vector<Appointment> Schedule::searchByStatus(){
  return scheduledAppointments;
}

bool sectionEquals(Section section1, Section section2){
  if(section1.date.isEqualTo(section2.date) && section1.time.isEqualTo(section2.time)){
    return true;
  }
  else{
    return false;
  }
}

bool sectionIsBeforethan(Section section1, Section section2){
  if(section1.date.isBeforeThan(section2.date)) { return true; }
  if(section1.date.isEqualTo(section2.date) && section1.time.isBeforeThan(section2.time)) { return true; }
  return false;
}

bool Schedule::isAppointed(Section test){ //nome meme, pse...
   for(Appointment appointment : scheduledAppointments){
    if(sectionEquals(appointment.section, test)) { return true; } //Falta verificar o status da consulta!!!
  }

  return false;
} 

Section lastSection(vector<Section> sections) { return sections[sections.size() - 1]; }

Section Schedule::nextWorkSection(){ // o mais recente em tempo
  Time timeC(-1,-1,-1); Date dataC(-1, -1); 
  Section sectionC(timeC, dataC); // de Candidate
  if(workSchedule.size() == 0) { return sectionC; }
  
  sectionC.date = workSchedule[0].date; sectionC.time = workSchedule[0].time;   
  for(Section section : workSchedule){
    if(sectionIsBeforethan(section, sectionC)){ 
      sectionC.date = section.date; sectionC.time = section.time; 
    }
  }

  return sectionC;  
}

// Pro médico conferir, sei lá... Tbm vai servir pra uma outra função chamar.
Appointment Schedule::nextAppointment(){
  Time timeC(-1,-1,-1); Date dataC(-1, -1); 
  Section sectionC(timeC, dataC); // de Candidate
  Appointment appointmentC(sectionC, "erro", -1);
  if(scheduledAppointments.size() == 0) { return appointmentC; }
  
  appointmentC = scheduledAppointments[0];
  for(Appointment appointment : scheduledAppointments){
    if(sectionIsBeforethan(appointment.section, appointmentC.section)){ // FALTA VERIFICAR O STATUS!!!! 
      appointmentC = appointment;
    }
  }
  
  return appointmentC;
}

Section nextSection(vector<Section> sections){ // o mais recente em tempo
  Time timeC(-1,-1,-1); Date dataC(-1, -1); 
  Section sectionC(timeC, dataC); // de Candidate
  if(sections.size() == 0) { return sectionC; }
  
  sectionC.date = sections[0].date; sectionC.time = sections[0].time;   
  for(Section section : sections){
    if(sectionIsBeforethan(section, sectionC)){ 
      sectionC.date = section.date; sectionC.time = section.time; 
    }
  }

  return sectionC;  
}

vector<Section> removeSection(vector<Section> sections, Section sectionToRemove) {
    
    vector<Section> result;
    for(Section section : sections){
      if(not sectionEquals(section, sectionToRemove)){
        result.push_back(section);
      }
    }

    return result;
}

Section Schedule::nextAvaiableSection(){
  Time timeC(-1,-1,-1); Date dateC(-1, -1); 
  Section sectionC(timeC, dateC); // de Candidate 
  if(workSchedule.size() == 0){ return sectionC; }

  vector<Section> sectionsToTry; sectionsToTry.assign(workSchedule.begin(), workSchedule.end());
  
  while(sectionsToTry.size() > 0){
    sectionC = nextSection(sectionsToTry);
    if(not isAppointed(sectionC)) { return sectionC; }
    sectionsToTry = removeSection(sectionsToTry, sectionC);
  }

  sectionC.time = timeC; sectionC.date = dateC;
  return sectionC; 
}

// sortByDate!!