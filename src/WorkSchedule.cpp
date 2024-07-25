#include "../include/WorkSchedule.h"

using namespace std;

// ----------------------------------------------------------------------------------------------------
// CONSTRUCTOR'S: (Essa forma assegurará que seções iguais não serão adicionadas no vetor.)
// ----------------------------------------------------------------------------------------------------
WorkSchedule::WorkSchedule(/*vector<WorkSession> newSchedule,*/ int newId, int newDoctor_id)
    : schedule(), id(newId), doctor_id(newDoctor_id) {}

WorkSchedule::WorkSchedule(vector<WorkSession> newSchedule, int newId, int newDoctor_id)
    : schedule(), id(newId), doctor_id(newDoctor_id) {safeAdd(newSchedule);}

// ----------------------------------------------------------------------------------------------------
// GETTERS:
// ----------------------------------------------------------------------------------------------------
int WorkSchedule::getID() { return id; }
int WorkSchedule::getDoctorID() { return doctor_id; };
vector<WorkSession> WorkSchedule::getWorkSchedule() { return schedule; }

// ----------------------------------------------------------------------------------------------------
// SEARCHS:
// ----------------------------------------------------------------------------------------------------

// Session after, between e before não parecem ser tão relevantes.
// Não faz sentido ter duas seções iguais no msm vetor. Haverá tratamento!
bool WorkSchedule::testSession(Session testSession){  // por conta disso, esse será bool mesmo! Mas poderíamos manter o padrão pra coletar erros.
    for(WorkSession wSession : schedule){
        if(testSession.isEqualTo(wSession)){ return true; }
    }
    return false;
}

// ----------------------------------------------------------------------------------------------------
// TIMES:
// ----------------------------------------------------------------------------------------------------

WorkSchedule WorkSchedule::searchByTime(Time thatTime){ 
    vector<WorkSession> vetorWS; 
    for(WorkSession wSession : schedule){
        if(thatTime.isEqualTo(wSession.getTime()) ){ 
             vetorWS.push_back(wSession);
        }
    }
    WorkSchedule wScheduleByTime(vetorWS, id, doctor_id);
    return wScheduleByTime;   
}

WorkSchedule WorkSchedule::searchByTimeBetween(Time time1, Time time2){ // tratar pra ver se veio vazio ou se não. 
    vector<WorkSession> vetorWS; 
    for(WorkSession wSession : schedule){
        if(wSession.getTime().isBetween(time1, time2)){
            vetorWS.push_back(wSession); 
        }
    }
    WorkSchedule wScheduleBtwn(vetorWS, id, doctor_id);
    return wScheduleBtwn; 
}

WorkSchedule WorkSchedule::searchByTimeBefore(Time thatTime){ // tratar pra ver se veio vazio ou se não. 
    vector<WorkSession> vetorWS; 
    for(WorkSession wSession : schedule){
        if((wSession.getTime().isBeforeThan(thatTime))||thatTime.isEqualTo(wSession.getTime())){
            vetorWS.push_back(wSession); 
        }
    }
    WorkSchedule wScheduleBtwn(vetorWS, id, doctor_id);
    return wScheduleBtwn; 
}

WorkSchedule WorkSchedule::searchByTimeAfter(Time thatTime){ // tratar pra ver se veio vazio ou se não. 
    vector<WorkSession> vetorWS; 
    for(WorkSession wSession : schedule){
        if((thatTime.isBeforeThan(wSession.getTime()))||thatTime.isEqualTo(wSession.getTime())){
            vetorWS.push_back(wSession); 
        }
    }
    WorkSchedule wScheduleBtwn(vetorWS, id, doctor_id);
    return wScheduleBtwn; 
}

// ----------------------------------------------------------------------------------------------------
// DATES:
// ----------------------------------------------------------------------------------------------------

WorkSchedule WorkSchedule::searchByDate(Date thatDate){ 
    vector<WorkSession> vetorWS; 
    for(WorkSession wSession : schedule){
        if(thatDate.isEqualTo(wSession.getDate())){ 
             vetorWS.push_back(wSession);
        }
    }
    WorkSchedule wScheduleByTime(vetorWS, id, doctor_id);
    return wScheduleByTime;   
}

WorkSchedule WorkSchedule::searchByDateBetween(Date date1, Date date2){ // tratar pra ver se veio vazio ou se não. 
    vector<WorkSession> vetorWS; 
    for(WorkSession wSession : schedule){
        if(wSession.getDate().isBetween(date1, date2)){
            vetorWS.push_back(wSession); 
        }
    }
    WorkSchedule wScheduleBtwn(vetorWS, id, doctor_id);
    return wScheduleBtwn; 
}

WorkSchedule WorkSchedule::searchByDateBefore(Date thatDate){ // tratar pra ver se veio vazio ou se não. 
    vector<WorkSession> vetorWS; 
    for(WorkSession wSession : schedule){
        if((wSession.getDate().isBeforeThan(thatDate))||thatDate.isEqualTo(wSession.getDate())){
            vetorWS.push_back(wSession); 
        }
    }
    WorkSchedule wScheduleBtwn(vetorWS, id, doctor_id);
    return wScheduleBtwn; 
}

WorkSchedule WorkSchedule::searchByDateAfter(Date thatDate){ // tratar pra ver se veio vazio ou se não. 
    vector<WorkSession> vetorWS; 
    for(WorkSession wSession : schedule){
        if((thatDate.isBeforeThan(wSession.getDate()))||thatDate.isEqualTo(wSession.getDate())){
            vetorWS.push_back(wSession); 
        }
    }
    WorkSchedule wScheduleBtwn(vetorWS, id, doctor_id);
    return wScheduleBtwn; 
}

// ----------------------------------------------------------------------------------------------------
// ANOTHER STUFF:
// ----------------------------------------------------------------------------------------------------

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

// BRUTEFORCE REMOVEWS:
WorkSchedule WorkSchedule::removeWS(WorkSession removeMe){ //remve uma workSession do vetor
    vector<WorkSession> vetorWS; 
    for(WorkSession wSession : schedule){
        if(not removeMe.isEqualTo(wSession)) { vetorWS.push_back(wSession);}
    }    
    WorkSchedule newSchedule(vetorWS, id, doctor_id); 
    return newSchedule;
}


// "SAFE_ADD" OVERLOADING:
void WorkSchedule::safeAdd(WorkSession addMe){
    if(schedule.size() == 0) { schedule.push_back(addMe); }
    else{
        bool isIn = false; 
        for(WorkSession wSession : schedule){
            if(wSession.isEqualTo(addMe)) { isIn = true; }
        }
        if(not isIn) { schedule.push_back(addMe); }
    }   
}

void WorkSchedule::safeAdd(vector<WorkSession> addMe){
    if(addMe.size() == 0){ return ; } // Precisa msm?
   
    for(WorkSession wSession : addMe){
        safeAdd(wSession);
    }
}

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
