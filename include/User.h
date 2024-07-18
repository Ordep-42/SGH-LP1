// User.h
#ifndef USER_H
#define USER_H
// #include <iostream>
#include "Date.h"
#include <string>
#include <vector>

using namespace std;

class User {
  protected:
    Date birthDate;
    string password;
    string name;
    string gender;
    string civicStatus;
    string address;
    string phoneNumber; // como tratar?
    string email;
    string role;

    // vector<payment> paymentResgistry;
    //  Plano de saúde (informações do seguro, se aplicável)
    //  Status atual (internado, alta, em espera, etc.)

  public:
    User(short newUserID, string newUserName, string newPassWord, string newName,
         Date newBirthDate, string newGender, string newCivicStatus,
         string newAddress, string newPhoneNumber, string newEmail);

    User(string name, string password, string role);

    short getUserID();
    string getUserName();
    string getPassword();
    string getName();
    Date getBirthDate();
    string getGender();
    string getCivicStatus();
    string getAddress();
    string getPhoneNumber();
    string getEmail();
    string getRole();
    Date getIngressDate();

    void setPassword(string newPassword);
    void setName(string newName);
    void setGender(string newGender);
    void setCivicStatus(string newCivicStatus);
    void setAddress(string newAddress);
    void setPhoneNumber(string newPhoneNumber);
    void setEmail(string newEmail);
    void setRole(string role);
};

// Funções auxiliares

#endif // USER_H
