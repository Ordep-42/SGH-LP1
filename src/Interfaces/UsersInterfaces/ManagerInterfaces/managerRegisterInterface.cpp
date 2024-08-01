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
        if (!maybeDoctor.has_value()) { cout << "pressione enter /p continuar" << endl; getchar(); 
            HospitalInterface::managerInterface(); }
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
    cout << "pressione enter /p continuar" << endl; getchar();
    //opcao valida, then:
    Schedule doctorSchedule = HospitalDatabase::getScheduleByDoctorID(doctors[choice - 1]);
    WorkSchedule doctorWorkSessions = doctorSchedule.getWorkSchedule();
    if(doctorWorkSessions.getWorkSchedule().size() == 0){
        cout << "Agenda completamente disponivel! " << endl; 
        int choicce; 
        vector<string> choose; 
        choose.push_back("cadastro mensal");
        choose.push_back("cadastro manual");
        choicce = choiceMaker(choose);

        if(choicce == 1) { 
        system("clear");
        int mes, ano, dia; 
        cout << "digite um ano desejado  "; 
        cin >> ano; 
        cout << "digite um mes desejado  ";
        cin >> mes;
        cout << "digite um dia desejado  "; 
        cin >> dia; 

        HospitalInterface::managerRegisterInterface2(doctors[choice - 1], mes, ano, dia);

        }
        
        string date, time; 
        cout << "digite uma data desejada no formato dd/mm/yyyy ";
        getline(cin, date);
        //sem getchar karalho
        cout << "digite hora desejada no formato hh:mm:ss " ;
        getline(cin, time);
        // SEM GETCHAR CARALHo

        // talvez bugue porcausa dos "stringTo<...>", mas enfim...        
        Session scheduleMe(stringToTime(time), stringToDate(date));

         HospitalDatabase::createWSession(doctors[choice - 1], scheduleMe);
        cout << " Cadastro realizado com sucesso " << endl;
        cout << "pressione enter /p continuar" << endl; getchar();
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
        cin >> date;         
        
        // Limpa o buffer
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Digite a hora desejada no formato hh:mm:ss: ";
        cin >> time;

        // talvez bugue porcausa dos "stringTo<...>", mas enfim...        
        Session scheduleMe(stringToTime(time), stringToDate(date));
        // vamos ver se nao houve um conflito nos horarios...
        if(doctorWorkSessions.testSession(scheduleMe)){  
            cout << " Horario indisponivel, voltando ao menu. " << endl;
            cout << "pressione enter /p continuar" << endl; getchar();
            HospitalInterface::managerInterface();
        }
        else{

            HospitalDatabase::createWSession(2, scheduleMe);
            cout << " Cadastro realizado com sucesso " << endl;
            cout << "pressione enter /p continuar" << endl; getchar();
            HospitalInterface::managerInterface();

        }   

    }

}

void HospitalInterface::managerRegisterInterface2(int doctor_id, int month, int year, int day){
    //coloque um mes de 30 dias apenas
    for(int i = day; i <= 5; i++){
        Time time(7,0,0); Date date(i,month, year ); Time sumMe(1,0,0);
        Session secao(time, date); HospitalDatabase::createWSession(doctor_id, secao);
        time.sumTime(sumMe);
        Session secao2(time, date); HospitalDatabase::createWSession(doctor_id, secao2);
        time.sumTime(sumMe);
        Session secao3(time, date); HospitalDatabase::createWSession(doctor_id, secao3);
        time.sumTime(sumMe);
        Session secao4(time, date); HospitalDatabase::createWSession(doctor_id, secao4);
        time.sumTime(sumMe);
        Session secao5(time, date); HospitalDatabase::createWSession(doctor_id, secao5);
        time.sumTime(sumMe);
        Session secao6(time, date); HospitalDatabase::createWSession(doctor_id, secao6);        
        
    }
    cout << " Cadastro realizado com sucesso " << endl;
    cout << "pressione enter /p continuar" << endl; getchar();
    
}