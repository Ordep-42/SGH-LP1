#ifndef MANAGER_H
#define MANAGER_H

#include "Doctor.h"
#include "User.h"

class Manager : public User {
  private:
  public:
    Manager(string name, string password);

    void createManager(Manager);
    void deleteManager(Manager);

    void createDoctor(Doctor);
    void deleteDoctor(Doctor);

    void createAttendant(User);
    void deleteAttendant(User);

    void createPatient(User);
    void deletePatient(User);
};

#endif // !MANAGER_H
