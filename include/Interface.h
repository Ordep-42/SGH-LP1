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
    void marcarConsulta();
    void listarConsultas();

    void attendantInterface();

    void doctorInterface();

    // MANAGER INTERFACE
    void managerInterface();
    void managerCreateInterface();
    void managerCreatePatient();
    void managerCreateAttendant();
    void managerCreateDoctor();
    void managerCreateManager();

    void managerListInterface();
    void managerDeleteInterface();

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
