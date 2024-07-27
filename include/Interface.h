#ifndef INTERFACE_H
#define INTERFACE_H

#include "./Users/User.h"
#include "Users/Patient.h"
#include <string>
#include <vector>

using namespace std;

class HospitalInterface {
  private:
    bool isLogged;
    int accessLevel;
    User *currentUser;

  public:
    HospitalInterface() = default;

    void entryProgramInterface();

    void createPatientInterface();

    void loginInterface();

    void createUserInterface();

    void patientInterface();

    void attendantInterface();

    void doctorInterface();

    void managerInterface();

    bool assertAccessLevel(int);

    bool getIsLogged();
    int getAccessLevel();
    User *getCurrentUser();

    void setIsLogged(bool);
    void setAccessLevel(int);
    void setCurrentUser(User *);
};

// Funções auxiliares
int choiceMaker(vector<string>);
void titleMaker(string);
void hr();

#endif // !INTERFACE_H
