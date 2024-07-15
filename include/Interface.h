#ifndef INTERFACE_H
#define INTERFACE_H

#include "User.h"
#include <string>
#include <vector>
class HospitalInterface {
private:
  bool isLogged;
  int accessLevel;
  User *currentUser;

public:
  HospitalInterface() = default;

  void entryProgramInterface();

  void loginInterface();

  void createPatientInterface();

  void createUserInterface();

  void loggedUserInterface();

  void hr();
  int choiceMaker(std::vector<std::string>);
  void titleMaker(std::string);
};

#endif // !INTERFACE_H
