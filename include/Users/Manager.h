#ifndef MANAGER_H
#define MANAGER_H

#include "Doctor.h"
#include "User.h"

class Manager : public User {
  private:
  public:
    Manager(string name, string password);
    Manager(int id, string name, string password);

    void createManager(Manager);
    void deleteManager(int);

    void createDoctor(Doctor);
    void deleteDoctor(int);

    void createAttendant(User);
    void deleteAttendant(int);

    void createPatient(User);
    void deletePatient(int);
};

#endif // !MANAGER_H
