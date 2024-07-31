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
    void pacienteMarcarConsulta();
    void pacienteListarConsultas();
    void pacienteCancelarConsulta();
    void pacienteListarDados();
    void pacienteAtualizarDados();
    void pacienteAtualizarContatosEmergencia();

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
    void managerListPatient();
    void managerListAttendant();
    void managerListDoctor();
    void managerListManager();

    void managerDeleteInterface();
    void managerDeletePatient();
    void managerDeleteAttendant();
    void managerDeleteDoctor();
    void managerDeleteManager();

    bool assertAccessLevel(int);

    bool getIsLogged();
    int getAccessLevel();
    User *getCurrentUser();

    void setIsLogged(bool);
    void setAccessLevel(int);
    void setCurrentUser(User *);
    void doctorCheckPatient(int doctorID);
    void doctorConcludeAppointment(int doctorID);
};

// Funções auxiliares
int choiceMaker(vector<string>);
void titleMaker(string);
void hr();

#endif // !INTERFACE_H
