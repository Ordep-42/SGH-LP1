#ifndef SESSION_H
#define SESSION_H

#include "Date.h"
#include "Time.h"
#include <string>
#include <vector>

using namespace std;

class Session {
private:
    Time time;
    Date date; 
    //short room;
    // int doctorId

public:
    Session(Time newTime, Date newDate);
    Session(); // isso resolveu sabe-se lá pq.

    Time getTime();
    Date getDate();
    string getTimeString();
    string getDateString();
    string toTDString();
    string toString(); // Ou toDTString

    void fixSession();

    bool isEqualTo(Session thatSession);
    bool isBeforeThan(Session thatSession);
    bool isBetween(Session session1, Session session2);

    bool isIn(vector<Session> sessions);

};

// Funções auxiliares
Session nextSessionFrom(vector<Session> sessions); // Seção mais recente em data
Session lastSessionFrom(vector<Session> sections); // Última sessão feita
Session firstSession(Session session1, Session session2);
Session lastSession(Session session1, Session session2);

Session tdStringToSession(string convertMe);
Session stringToSession(string convertMe);
string getFirstPart(string firstSecond);
string getSecondPart(string firstSecond);



#endif // !SESSION_H
