#include "../../include/Time/WorkSession.h"

using namespace std;

// Construtor
WorkSession::WorkSession(Time newTime, Date newDate, int newId, int newDoctorId) //alternativamente, daria pra pssr logo uma session
    : Session(newTime, newDate), id(newId), doctor_id(newDoctorId) {} // Falta conferir se o id não está ocupado, oq precisará ser feito por fora. 

// WorkSession::WorkSession(){
//     Time newTime(); Date newDate(); 
// }

// Getters
int WorkSession::getId() {
    return id;
}

int WorkSession::getDoctorId() {
    return doctor_id;
}