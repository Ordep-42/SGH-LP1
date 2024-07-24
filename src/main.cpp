#include <iostream>
#include "../include/Time.h"
#include "../include/Date.h"
#include "../include/Session.h"
#include <vector>

using namespace std;

bool testTime(Time& time1, Time& time2, bool expectedIsEqual, bool expectedIsBefore) {
  cout << "Testing Time class..." << endl;

  cout << "  Time 1: " << time1.getHour() << ":" << time1.getMin() << ":" << time1.getSec() << endl;
  cout << "  Time 2: " << time2.getHour() << ":" << time2.getMin() << ":" << time2.getSec() << endl;

  // Testing isEqualTo
  bool isEqual = time1.isEqualTo(time2);
  cout << "  isEqualTo: " << (isEqual ? "PASSED" : "FAILED") << " (Expected: " << (expectedIsEqual ? "PASSED" : "FAILED") << ")" << endl;

  // Testing isBeforeThan
  bool isBefore = time1.isBeforeThan(time2);
  cout << "  isBeforeThan: " << (isBefore ? "PASSED" : "FAILED") << " (Expected: " << (expectedIsBefore ? "PASSED" : "FAILED") << ")" << endl;

  cout << endl;
  return (isEqual == expectedIsEqual) && (isBefore == expectedIsBefore);
}

// Example of how to test the Date class
bool testDate(Date& date1, Date& date2, bool expectedIsEqual, bool expectedIsBefore) {
  cout << "Testing Date class..." << endl;

  cout << "  Date 1: " << date1.getDay() << "/" << date1.getMonth() << "/" << date1.getYear() << endl;
  cout << "  Date 2: " << date2.getDay() << "/" << date2.getMonth() << "/" << date2.getYear() << endl;

  // Testing isEqualTo
  bool isEqual = date1.isEqualTo(date2);
  cout << "  isEqualTo: " << (isEqual ? "PASSED" : "FAILED") << " (Expected: " << (expectedIsEqual ? "PASSED" : "FAILED") << ")" << endl;

  // Testing isBeforeThan
  bool isBefore = date1.isBeforeThan(date2);
  cout << "  isBeforeThan: " << (isBefore ? "PASSED" : "FAILED") << " (Expected: " << (expectedIsBefore ? "PASSED" : "FAILED") << ")" << endl;

  cout << endl;
  return (isEqual == expectedIsEqual) && (isBefore == expectedIsBefore);
}

// Example of how to test the Session class
bool testSession(Session& session1, Session& session2, bool expectedIsEqual, bool expectedIsBefore) {
  cout << "Testing Session class..." << endl;

  cout << "  Session 1: " << session1.getTime().getHour() << ":" << session1.getTime().getMin() << ":" << session1.getTime().getSec() << " - "
    << session1.getDate().getDay() << "/" << session1.getDate().getMonth() << "/" << session1.getDate().getYear() << endl;
  cout << "  Session 2: " << session2.getTime().getHour() << ":" << session2.getTime().getMin() << ":" << session2.getTime().getSec() << " - "
    << session2.getDate().getDay() << "/" << session2.getDate().getMonth() << "/" << session2.getDate().getYear() << endl;

  // Testing isEqualTo
  bool isEqual = session1.isEqualTo(session2);
  cout << "  isEqualTo: " << (isEqual ? "PASSED" : "FAILED") << " (Expected: " << (expectedIsEqual ? "PASSED" : "FAILED") << ")" << endl;

  // Testing isBeforeThan
  bool isBefore = session1.isBeforeThan(session2);
  cout << "  isBeforeThan: " << (isBefore ? "PASSED" : "FAILED") << " (Expected: " << (expectedIsBefore ? "PASSED" : "FAILED") << ")" << endl;

  cout << endl;
  return (isEqual == expectedIsEqual) && (isBefore == expectedIsBefore);
}

int main() {
  // Test cases for Time class
  Time time1(12, 30, 45);
  Time time2(10, 15, 30);
  Time time3(12, 30, 45);

  testTime(time1, time2, false, true);
  testTime(time1, time3, true, false);

  // Test cases for Date class
  Date date1(dateToDaysBF(1, 1, 2024), 2024);
  Date date2(dateToDaysBF(31, 12, 2023), 2023);
  Date date3(dateToDaysBF(1, 1, 2024), 2024);

  testDate(date1, date2, false, true);
  testDate(date1, date3, true, false);

  // Test cases for Session class
  Session session1(time1, date1);
  Session session2(time2, date2);
  Session session3(time1, date1);

  testSession(session1, session2, false, true);
  testSession(session1, session3, true, false);

  // Additional tests for Session class
  cout << "Testing Session class: nextSessionFrom..." << endl;
  vector<Session> sessions = {session2, session1};
  Session nextSession = nextSessionFrom(sessions);
  cout << "  Next session: " << nextSession.getTime().getHour() << ":" << nextSession.getTime().getMin() << ":" << nextSession.getTime().getSec() << " - "
    << nextSession.getDate().getDay() << "/" << nextSession.getDate().getMonth() << "/" << nextSession.getDate().getYear() << endl;

  if (nextSession.isEqualTo(session1)) {
    cout << "  nextSessionFrom: PASSED" << endl;
  } else {
    cout << "  nextSessionFrom: FAILED" << endl;
  }
  cout << endl;

  cout << "Testing Session class: lastSessionFrom..." << endl;
  Session lastSession = lastSessionFrom(sessions);
  cout << "  Last session: " << lastSession.getTime().getHour() << ":" << lastSession.getTime().getMin() << ":" << lastSession.getTime().getSec() << " - "
    << lastSession.getDate().getDay() << "/" << lastSession.getDate().getMonth() << "/" << lastSession.getDate().getYear() << endl;

  if (lastSession.isEqualTo(session2)) {
    cout << "  lastSessionFrom: PASSED" << endl;
  } else {
    cout << "  lastSessionFrom: FAILED" << endl;
  }
  cout << endl;

  cout << "Testing Session class: isIn..." << endl;
  if (session1.isIn(sessions)) {
    cout << "  isIn: PASSED" << endl;
  } else {
    cout << "  isIn: FAILED" << endl;
  }
  cout << endl;

  return 0;
}