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

  public:
    Session(Time newTime, Date newDate);
    Session();

    Time getTime();
    Date getDate();
    string getTimeString();
    string getDateString();
    string toString();

    void fixSession();

    bool isEqualTo(Session thatSession);
    bool isBeforeThan(Session thatSession);
    bool isBetween(Session session1, Session session2);

    bool isIn(vector<Session> sessions);
};

// Funções auxiliares
Session nextSessionFrom(vector<Session> sessions);
Session lastSessionFrom(vector<Session> sections);
Session firstSession(Session session1, Session session2);
Session lastSession(Session session1, Session session2);

Session stringToSession(string convertMe);
string getFirstPart(string firstSecond);
string getSecondPart(string firstSecond);

#endif // !SESSION_H
