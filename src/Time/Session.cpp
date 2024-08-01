#include "../../include/Time/Session.h"

using namespace std;

// Construtor:
Session::Session(Time newTime, Date newDate) : time(newTime), date(newDate) {}

Session::Session() {
    Time newTime(-1, -1, -1);
    Date newDate(-1, -1);
    time = newTime;
    date = newDate;
}

// Getters:
Time Session::getTime() { return time; }

Date Session::getDate() { return date; }

string Session::getDateString() { return getFirstPart(toString()); }

string Session::getTimeString() { return getSecondPart(toString()); }

void Session::fixSession() {
    time.fixTime();
    date.fixDate();
}

bool Session::isEqualTo(Session thatSession) { // diferenciando do "this->"
    fixSession();
    thatSession.fixSession(); // fixers
    if (date.isEqualTo(thatSession.getDate()) &&
        time.isEqualTo(thatSession.getTime())) {
        return true;
    } else {
        return false;
    }
}

bool Session::isBeforeThan(Session thatSession) {
    fixSession();
    thatSession.fixSession(); // fixers
    if (date.isBeforeThan(thatSession.getDate())) {
        return true;
    }
    if (date.isEqualTo(thatSession.getDate()) &&
        time.isBeforeThan(thatSession.getTime())) {
        return true;
    }
    return false;
}

Session nextSessionFrom(vector<Session> sessions) { // o mais recente em tempo
    Time timeC(-1, -1, -1);
    Date dataC(-1, -1); // Falta conferir oq acontece nos construtores!!!
    Session sessionC(timeC, dataC); // de Candidate
    if (sessions.size() == 0) {
        return sessionC;
    } // Tratamento de erros

    // sessionC.getDate() = sessions[0].getDate(); sessionC.getTime() =
    // sessions[0].getTime();
    sessionC = sessions[0]; // Dá problema cm ponteiro?
    for (Session session : sessions) {
        if (session.isBeforeThan(sessionC)) {
            // sessionC.getDate() = session.getDate(); sessionC.getTime() =
            // session.getTime( );
            sessionC = session;
        }
    }

    return sessionC;
}

Session lastSessionFrom(vector<Session> sessions) {
    return sessions[sessions.size() - 1];
}

bool Session::isIn(vector<Session> sessions) {
    for (Session sessionC : sessions) {
        if (isEqualTo(sessionC)) {
            return true;
        }
    }
    return false;
}

Session firstSession(Session session1, Session session2) { // "min" binário
    if (session1.getDate().isBeforeThan(session2.getDate())) {
        return session1;
    } else if (session2.getDate().isBeforeThan(session1.getDate())) {
        return session2;
    }
    // As datas são iguais, então testemos os horários
    if (session1.getTime().isBeforeThan(session2.getTime())) {
        return session1;
    }
    return session2;
}

// em termos do first:
Session lastSession(Session session1, Session session2) { // "max" binário
    Session fSession = firstSession(session1, session2);

    if (session1.isEqualTo(fSession)) {
        return session2;
    }
    return session1;
}

bool Session::isBetween(
    Session session1,
    Session session2) { // Intervalo fechado (incluindo data 1 e data 2)
    Session first = firstSession(session1, session2);
    Session last = lastSession(session1, session2);
    if ((isBeforeThan(last) && first.isBeforeThan(*this)) || isEqualTo(first) ||
        isEqualTo(last)) { // talvez esse asterisco bugue muito no futuro...
                           // CUIDADO!!!
        return true;
    }
    return false;
}

string getFirstPart(string firstSecond) {
    int pos = firstSecond.find(" ");
    return firstSecond.substr(0, pos);
}
string getSecondPart(string firstSecond) {
    int pos = firstSecond.find(" ");
    return firstSecond.substr(pos + 1);
}

string Session::toString() {
    string sessionString = "";
    sessionString += getDate().toString(); 
    sessionString += " ";
    sessionString += getTime().toString(); 
    
    return sessionString;
}

// Eu só flippei os gets oq deixou BEM gambiarroso!!
Session stringToSession(string convertMe) {
    Session newSession(stringToTime(getSecondPart(convertMe)),
                       stringToDate(getFirstPart(convertMe)));

    return newSession;
}
