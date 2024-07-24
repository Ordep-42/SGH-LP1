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

    Time getTime();
    Date getDate();

    void fixSession();

    bool isEqualTo(Session thatSession);
    bool isBeforeThan(Session thatSession);

    bool isIn(vector<Session> sessions);

};

// Funções auxiliares
Session nextSessionFrom(vector<Session> sessions); // Seção mais recente em data
Session lastSessionFrom(vector<Session> sections); // Última sessão feita

#endif // !SESSION_H
