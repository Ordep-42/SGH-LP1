// User.h
#ifndef USER_H
#define USER_H
//#include <iostream>
#include <string>
#include "Date.h"
#include <vector>

using namespace std;

class User {
private:    
    const Date ingressDate; 
    const Date birthDate;
    const short userID;
    const string userName;
      
    string passWord; 
    string name;         
    string gender;
    string civicStatus;
    string adress;
    string phoneNumber; //como tratar?
    string email;

    
    //vector<payment> paymentResgistry;
    // Plano de saúde (informações do seguro, se aplicável)
    // Status atual (internado, alta, em espera, etc.)
    
public:
    User(short newUserID, string newUserName, string newPassWord, string newName, Date newBirthDate, string newGender, string newCivicStatus, string newAdress, string newPhoneNumber, string newEmail, Date newIngressDate); 

    short getUserID();
    string getUserName();
    string getPassWord();
    string getName();
    Date getBirthDate();
    string getGender();
    string getCivicStatus();
    string getAdress();
    string getPhoneNumber();
    string getEmail();
    Date getIngressDate(); 

    void setPassWord(string newPassWord);
    void setName(string newName);    
    void setGender(string newGender);
    void setCivicStatus(string newCivicStatus);
    void setAdress(string newAdress);
    void setPhoneNumber(string newPhoneNumber);
    void setEmail(string newEmail); 

    

};

// Funções auxiliares



#endif // USER_H