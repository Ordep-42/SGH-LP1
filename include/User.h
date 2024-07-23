// User.h
#ifndef USER_H
#define USER_H
// #include <iostream>
#include "Date.h"
#include <string>
#include <vector>

typedef enum roles {
    Admin,
    Gestor,
    Doutor,
    Atendente,
    Paciente
} Role;

typedef enum genders {
    Masculino,
    Feminino,
} Gender;

typedef enum civilStatus {
    Solteiro,
    Casado,
    Divorciado,
    Viuvo
} CivilStatus;

using namespace std;

class User {
  protected:
    unsigned short userID;
    string login;
    string password;
    string name;
    Date birthDate;
    string cpf;
    Gender gender;
    CivilStatus civilStatus;
    string address;
    string phoneNumber; // como tratar?
    string email;
    Role role;

  public:
    User(unsigned short newUserID, string newLogin, string newPassWord, string newName,
         Date newBirthDate, string newCpf, Gender newGender, CivilStatus newCivilStatus,
         string newAddress, string newPhoneNumber, string newEmail);

    User(string name, string password, Role role);

    User() {}

    unsigned short getUserID();
    string getLogin();
    string getPassword();
    string getName();
    Date getBirthDate();
    string getCpf();
    Gender getGender();
    CivilStatus getCivilStatus();
    string getAddress();
    string getPhoneNumber();
    string getEmail();
    Role getRole();
    Date getIngressDate();

    void setLogin(string newLogin);
    void setPassword(string newPassword);
    void setName(string newName);
    void setBirthDate(Date newBirthDate);
    void setCpf(string newCpf);
    void setGender(Gender newGender);
    void setCivilStatus(CivilStatus newCivilStatus);
    void setAddress(string newAddress);
    void setPhoneNumber(string newPhoneNumber);
    void setEmail(string newEmail);
    void setRole(Role role);
};

// Funções auxiliares

#endif // USER_H
