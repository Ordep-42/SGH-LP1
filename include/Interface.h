#ifndef INTERFACE_H
#define INTERFACE_H

#include "User.h"
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

  void loggedUserInterface();
};

// Funções auxiliares
int choiceMaker(vector<string>);
void titleMaker(string);
void hr();

#endif // !INTERFACE_H
