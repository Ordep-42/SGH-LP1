#include "../../../../include/HospitalDatabase/HospitalDatabase.h"
#include "../../../../include/Interface.h"
#include <cstdio>
#include <cstdlib>
#include <optional>
#include <cstdlib>
#include <iostream>
#include <map>
#include <unistd.h>

using namespace std;

void HospitalInterface::managerRegisterInterface(){
    system("clear");
    std::set<int> setsetset = HospitalDatabase::getAllDoctors(); 
    // Should i? But do i need to..?
    vector<int> doctors(setsetset.begin(), setsetset.end()); 
    if(doctors.size() == 0) { return; }
    vector<string> toChoice;
    for(int id : doctors){
        optional<Doctor> maybeDoctor = HospitalDatabase::getDoctorByID(id);  
        if (!maybeDoctor.has_value()) { system("pause"); HospitalInterface::managerInterface(); }
        Doctor doutor = maybeDoctor.value();            
        
        string line = ""; 
        line += doutor.getName();
        line += " - ";
        line += doutor.getEspecialidade();     
       
        toChoice.push_back(line);
    }

    int choice = choiceMaker(toChoice);

    while(choice < 0 || choice > (toChoice.size() - 1)){
        cout << "opcao invalida, tente novamente... " << endl; 
        int choice = choiceMaker(toChoice);
    }
    system("pause");
    //opcao valida, then:
    Schedule doctorSchedule = HospitalDatabase::getScheduleByDoctorID(doctors[choice - 1]);
    WorkSchedule doctorWorkSessions = doctorSchedule.getWorkSchedule();
    if(doctorWorkSessions.getWorkSchedule().size() == 0){
        cout << "Agenda completamente disponivel! " << endl; 
        
        string date, time; 
        cout << "digite uma data desejada no formato dd/mm/yyyy " << endl;
        getline(cin, date);
        getchar();
        cout << "digite hora desejada no formato hh:mm:ss " << endl;
        getline(cin, time);
        getchar();

        // talvez bugue porcausa dos "stringTo<...>", mas enfim...        
        Session scheduleMe(stringToTime(time), stringToDate(date));

         HospitalDatabase::createWSession(doctors[choice - 1], scheduleMe);
        cout << " Cadastro realizado com sucesso " << endl;
        system("pause");
        HospitalInterface::managerInterface();
    }
    else{
        //mostrar horarios já cadastrados
        cout << "Horários ocupados: " << endl; 
        for(WorkSession wSession : doctorWorkSessions.getWorkSchedule()){
            cout << wSession.toString() << endl; 
        }
        string date, time; 
        cout << "digite uma data desejada no formato dd/mm/yyyy " << endl;
        getline(cin, date);
        getchar();
        cout << "digite hora desejada no formato hh:mm:ss " << endl;
        getline(cin, time);
        getchar();

        // talvez bugue porcausa dos "stringTo<...>", mas enfim...        
        Session scheduleMe(stringToTime(time), stringToDate(date));
        // vamos ver se nao houve um conflito nos horarios...
        if(doctorWorkSessions.testSession(scheduleMe)){  
            cout << " Horario indisponivel, voltando ao menu. " << endl;
            system("pause");
            HospitalInterface::managerInterface();
        }
        else{
            HospitalDatabase::createWSession(doctors[choice - 1], scheduleMe);
            cout << " Cadastro realizado com sucesso " << endl;
            system("pause");
            HospitalInterface::managerInterface();

        }   

    }

}