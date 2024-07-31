#include "../../../include/HospitalDatabase/HospitalDatabase.h"
#include "../../../include/Interface.h"
#include "../../../include/Time/Appointment.h"
#include "../../../include/Time/Date.h"
#include "../../../include/Time/Session.h"
#include "../../../include/Time/Time.h"
#include "../../../include/Users/Patient.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <set>
#include <string>
#include <vector>

void HospitalInterface::patientInterface() {
    system("clear");
    titleMaker("CENTRAL DO PACIENTE");

    Patient *patient = dynamic_cast<Patient *>(this->getCurrentUser());

    setCurrentUser(patient);

    vector<string> choices;
    choices.push_back("Marcar consulta");
    choices.push_back("Listar consultas");
    choices.push_back("Cancelar consulta");
    choices.push_back("Listar dados");
    choices.push_back("Atualizar dados");
    choices.push_back("Voltar");
    int choice = choiceMaker(choices);

    switch (choice) {
    case 1:
        HospitalInterface::pacienteMarcarConsulta();
        break;
    case 2:
        HospitalInterface::pacienteListarConsultas();
        break;
    case 3:
        HospitalInterface::pacienteCancelarConsulta();
        break;
    case 4:
        HospitalInterface::pacienteListarDados();
        break;
    case 5:
        HospitalInterface::pacienteAtualizarDados();
        break;
    case 6:
        this->setCurrentUser(nullptr);
        HospitalInterface::entryProgramInterface();
        break;
    default:
        break;
    }
}

void HospitalInterface::pacienteMarcarConsulta() {
    int medId;

    system("clear");
    titleMaker("AGENDAMENTO DE CONSULTA");
    set<int> IdList = HospitalDatabase::listDoctors();
    hr();
    cout << "Digite o ID do médico que você quer se consultar." << endl;
    cout << "[0] para voltar.\n";

    cin >> medId;
    getchar();

    while (IdList.find(medId) == IdList.end() && medId != 0) {
        cout << "Digite um ID válido.\n";
        cin >> medId;
    }

    cout << "ID VALIDO DIGITADO!\n";

    if (medId == 0) {
        HospitalInterface::patientInterface();
        return;
    }
    /*
        Schedule medSchedule = getScheduleByDoctorIdFromBD(medId);

        // int  pickedSession =
        // choiceMaker(medSchedule.avaiableSessions().toStringVector();); // 0
        // volta?

        // implementar o toStringVector tbm
        vector<string> SessionsToChoice =
            medSchedule.avaiableSessions().toStringVector();
        int pickedSession = choiceMaker(SessionsToChoice);

        MarcarConsulta(medSchedule.avaiableSessions()[pickedSession]);
    */
    // system("clear");
    // titleMaker("AGENDAMENTO DE CONSULTA");
    // string data;
    // string hora;
    // cout << "Formato: DD/MM/YYYY\n";
    // cout << "Digite a DATA para realizar a consulta: ";
    // cin >> data;
    // getchar();
    // cout << "\n";
    // cout << "Formato: HH:MM\n";
    // cout << "Digite a HORA para realizar a consulta: ";
    // cin >> hora;
    // getchar();

    // Session appointmentSession =
    //     Session(stringToTime(hora), stringToDate(data));

    // system("clear");
    // titleMaker("AGENDAMENTO DE CONSULTA");
    // string consultType;
    // cout << "Qual o tipo de consulta?\n";
    // cin >> consultType;
    // getchar();

    /*int patientId = this->getCurrentUser()->getUserID();

    // Appointment novaConsulta = Appointment(appointmentSession, "Marcado",
    //                                        patientId, medId, consultType);

    // AGENDAR NO BANCO DE DADOS*/
    //cout << "Consulta marcada com sucesso para a data " << data << " às " << hora << "!" << endl;
    
    while (true) {
        cout << "Digite [0] para voltar." << endl;
        int choice;
        cin >> choice;
        if (choice == 0) {
            break;
        }
    }
    HospitalInterface::patientInterface();
}

void HospitalInterface::pacienteListarConsultas() {
    system("clear");
    titleMaker("LISTAGEM DE CONSULTAS");

    vector<Appointment> patientAppointments = HospitalDatabase::listAppointmentsByPatient(this->getCurrentUser()->getUserID());
    //printarVetorDeStrings(patientAppointments.toString);
    //system("pause");
    //HospitalDatabase::listAppointmentsByPatient(
    //this->getCurrentUser()->getUserID());
    hr();
    while (true) {
        cout << "Digite [0] para voltar." << endl;
        int choice;
        cin >> choice;
        if (choice == 0) {
            break;
        }
    }
    HospitalInterface::patientInterface();
}

void HospitalInterface::pacienteCancelarConsulta() {
    system("clear");
    titleMaker("CANCELAR CONSULTA");

    int appointmentId;
    cout << "Digite o ID da consulta que deseja cancelar: ";
    cin >> appointmentId;
    getchar();

    //HospitalDatabase::deleteAppointment(appointmentId);

    cout << "Consulta cancelada com sucesso!" << endl;
    while (true) {
        cout << "Digite [0] para voltar." << endl;
        int choice;
        cin >> choice;
        if (choice == 0) {
            break;
        }
    }
    HospitalInterface::patientInterface();
}

User user = User(1, "login", "password", "Pedro", "123.456.789-10", Date(200, 2024), Masculino, Solteiro, "Rua tal", "084 99999-9999", "email@domínio.com");
User *patient = &user;

void HospitalInterface::pacienteListarDados() {
    system("clear");
    titleMaker("LISTAGEM DE DADOS");
    //Lista os dados
    //User* patient = this->getCurrentUser();

    titleMaker("Dados Pessoais");
    cout << "Nome: " << patient->getName() << endl;
    cout << "CPF: " << patient->getCpf() << endl;
    cout << "Data de Nascimento: " << patient->getBirthDate().toString() << endl;
    cout << "Gênero: " << genderToString(patient->getGender()) << endl;
    cout << "Estado Civil: " << civilStatusToString(patient->getCivilStatus()) << endl;

    titleMaker("Contato");
    cout << "Endereço: " << patient->getAddress() << endl;
    cout << "Telefone: " << patient->getPhoneNumber() << endl;
    cout << "Email: " << patient->getEmail() << endl;
    
    hr();

    while (true) {
        cout << "Digite [0] para voltar." << endl;
        int choice;
        cin >> choice;
        if( choice == 0 ) {
            break;
        }
    }
    HospitalInterface::patientInterface();
}

void HospitalInterface::pacienteAtualizarDados() {
    system("clear");
    titleMaker("ATUALIZAÇÃO DE DADOS");


    titleMaker("Dados Pessoais");
    cout << "Nome: " << patient->getName() << endl;
    cout << "CPF: " << patient->getCpf() << endl;
    cout << "Data de Nascimento: " << patient->getBirthDate().toString() << endl;
    cout << "Gênero: " << genderToString(patient->getGender()) << endl;
    cout << "Estado Civil: " << civilStatusToString(patient->getCivilStatus()) << endl;

    titleMaker("Contato");
    cout << "Endereço: " << patient->getAddress() << endl;
    cout << "Telefone: " << patient->getPhoneNumber() << endl;
    cout << "Email: " << patient->getEmail() << endl;
    
    titleMaker("Qual dado deseja atualizar?");

    vector<string> choices;
    choices.push_back("CPF");
    choices.push_back("Data de Nascimento");
    choices.push_back("Gênero");
    choices.push_back("Estado Civil");
    choices.push_back("Endereço");
    choices.push_back("Telefone");
    choices.push_back("Email");
    choices.push_back("Voltar");
    int choice = choiceMaker(choices);
    
    string entrada;
    vector<string> dataChoices;
    int dataChoice;
        

    switch (choice) {
    case 1:
        system("clear");
        titleMaker("ATUALIZAÇÃO DE DADOS");
        cout << "Digite o novo CPF: ";
        cin >> entrada;
        getchar();
        patient->setCpf(entrada);
        hr();
        cout << "CPF atualizado para " << patient->getCpf() << "!" << endl;
        break;
    case 2:
        system("clear");
        titleMaker("ATUALIZAÇÃO DE DADOS");
        cout << "Digite a nova Data de Nascimento (no formato DD/MM/AAAA): ";
        cin >> entrada;
        getchar();
        patient->setBirthDate(stringToDate(entrada));
        hr();
        Date data;
        data = patient->getBirthDate();
        cout << "Data de Nascimento atualizada para atualizado para " << data.getDay() << "/" << data.getMonth() << "/" << data.getYear() << "!" << endl;
        break;
    case 3:
        system("clear");
        titleMaker("ATUALIZAÇÃO DE DADOS");
        cout << "Digite a opção desejada: "<< endl;
        dataChoices = {"Masculino", "Feminino", "Outro"};
        dataChoice = choiceMaker(dataChoices);

        switch (dataChoice) {
        case 1:
            patient->setGender(Masculino);
            break;
        case 2:
            patient->setGender(Feminino);
            break;
        case 3:
            patient->setGender(Outro);
            break;
        }
        cout << "Gênero atualizado para " << genderToString(patient->getGender()) << "!" << endl;
        break;
    case 4:
    system("clear");
        titleMaker("ATUALIZAÇÃO DE DADOS");
        cout << "Digite a opção desejada: "<< endl;
        dataChoices = {"Solteiro(a)", "Casado(a)", "Divorciado(a)", "Viúvo(a)"};
        dataChoice = choiceMaker(dataChoices);

        switch (dataChoice) {
        case 1:
            patient->setCivilStatus(Solteiro);
            break;
        case 2:
            patient->setCivilStatus(Casado);
            break;
        case 3:
            patient->setCivilStatus(Divorciado);
            break;
        case 4:
            patient->setCivilStatus(Viuvo);
        }
        cout << "Estado civil atualizado para " << civilStatusToString(patient->getCivilStatus()) << "!" << endl;
        break;
    case 5:
        system("clear");
        titleMaker("ATUALIZAÇÃO DE DADOS");
        cout << "Digite o novo endereço: ";
        cin >> entrada;
        getchar();
        patient->setAddress(entrada);
        hr();
        cout << "Endereço atualizado para " << patient->getAddress() << "!" << endl;
        break;
    case 6:
        system("clear");
        titleMaker("ATUALIZAÇÃO DE DADOS");
        cout << "Digite o novo telefone: ";
        cin >> entrada;
        getchar();
        patient->setPhoneNumber(entrada);
        hr();
        cout << "Telefone atualizado para " << patient->getPhoneNumber() << "!" << endl;
        break;
    case 7:
        system("clear");
        titleMaker("ATUALIZAÇÃO DE DADOS");
        cout << "Digite o novo email: ";
        cin >> entrada;
        getchar();
        patient->setEmail(entrada);
        hr();
        cout << "Email atualizado para " << patient->getEmail() << "!" << endl;
        break;
    case 8:
        HospitalInterface::patientInterface();
        break;
    default:
        HospitalInterface::patientInterface();
        break;
    }

    while (true) {
        cout << "Digite [0] para voltar." << endl;
        int choice;
        cin >> choice;
        if (choice == 0) {
            break;
        }
    }
    HospitalInterface::patientInterface();
}