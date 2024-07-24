#include "../include/WorkSchedule.h"

using namespace std;

// Construtor: 
WorkSchedule::WorkSchedule(vector<WorkSession> newSchedule, int newId, int newDoctor_id)
    : schedule(newSchedule), id(newId), doctor_id(newDoctor_id) {}

// Getters: 
int WorkSchedule::getID() { return id; }
int WorkSchedule::getDoctorID() { return doctor_id; };
vector<WorkSession> WorkSchedule::getWorkSchedule() { return schedule; }

// Search's by Time: 

// test date
// Time between 
// Time before 
// Time after
WorkSchedule WorkSchedule::searchByTime(){

}

WorkSchedule WorkSchedule::searchByDate(){

}

WorkSchedule WorkSchedule::searchByID(int testID){ // Caso o retorno tenha size 0, o id era invalido, caso tenha tamanho 1, era valido, caso tenha >1, erro!
   vector<WorkSession> vetorWS;  
    for(WorkSession wSession : schedule){
        if(wSession.getId() == testID){
            vetorWS.push_back(wSession);   
        }
    } 
    // Sem ser um vetor vamos ter mais dados, vai que, né... 
    WorkSchedule scheduleByPatient(vetorWS, id, doctor_id); 
    return scheduleByPatient;
}


//WorkSession lastSession(vector<WorkSession> sections);
// next
WorkSession WorkSchedule:: lastSession(){ // Safe
    WorkSession goat; //pq não "goat()"? 
    if(schedule.size() == 0){ return goat; }
    return schedule[schedule.size() - 1];
}

WorkSession WorkSchedule::nextWorkSection(){
    WorkSession goat; //pq não "goat()"? 
    if(schedule.size() == 0){ return goat; }
    else{
        WorkSession wSessionC = schedule[0]; // Candidate
        for(WorkSession wSession : schedule){
            if(wSession.isBeforeThan(wSessionC))
                wSessionC = wSession;            
        }
        return wSessionC; 
    }
}

//Section nextAvaiableSection(); <-- ONDE VAI ISSO???


// vector<Section> removeSection(vector<Section> sections, Section sectionToRemove) {
    
//     vector<Section> result;
//     for(Section section : sections){
//       if(not sectionEquals(section, sectionToRemove)){
//         result.push_back(section);
//       }
//     }

//     return result;
// }