#include "../include/Session.h"

using namespace std;

// Construtor: 
Session::Session(Time newTime, Date newDate)
    : time(newTime), date(newDate) {}

Session::Session() {
  Time newTime(-1,-1,-1); Date newDate(-1,-1);
  time = newTime; date = newDate;
}

// Getters: 
Time Session::getTime() { return time; }

Date Session::getDate() { return date; }

void Session::fixSession() { time.fixTime(); date.fixDate(); }

bool Session::isEqualTo(Session thatSession){ //diferenciando do "this->"
    fixSession(); thatSession.fixSession(); //fixers
    if(date.isEqualTo(thatSession.getDate()) && time.isEqualTo(thatSession.getTime())){
      return true;
    }
    else{
      return false;
    }
}

bool Session::isBeforeThan(Session thatSession){
    fixSession(); thatSession.fixSession(); //fixers
    if(date.isBeforeThan(thatSession.getDate())) { return true; }
    if(date.isEqualTo(thatSession.getDate()) && time.isBeforeThan(thatSession.getTime())) { return true; }
    return false;
}

Session nextSessionFrom(vector<Session> sessions){ // o mais recente em tempo
  Time timeC(-1,-1,-1); Date dataC(-1, -1); // Falta conferir oq acontece nos construtores!!!
  Session sessionC(timeC, dataC); // de Candidate
  if(sessions.size() == 0) { return sessionC; } // Tratamento de erros

  //sessionC.getDate() = sessions[0].getDate(); sessionC.getTime() = sessions[0].getTime();   
  sessionC = sessions[0]; // Dá problema cm ponteiro?
  for(Session session : sessions){
    if(session.isBeforeThan(sessionC)){ 
      //sessionC.getDate() = session.getDate(); sessionC.getTime() = session.getTime( ); 
      sessionC = session;
    }
  }

  return sessionC;  
}

Session lastSessionFrom(vector<Session> sessions) { return sessions[sessions.size() - 1]; }

bool Session::isIn(vector<Session> sessions){
    for(Session sessionC : sessions){
        if(isEqualTo(sessionC)){
            return true; 
        }
    }
    return false;
}