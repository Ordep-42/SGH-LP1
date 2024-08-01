#include "../../../include/HospitalDatabase/HospitalDatabase.h"
#include "../../../include/Interface.h"
#include "../../../include/Time/Appointment.h"
#include <set>

using namespace std;

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
    if (medId == 0) {
        HospitalInterface::patientInterface();
        return;
    }
    system("clear");
    titleMaker("AGENDAMENTO DE CONSULTA");

    Schedule medSchedule = HospitalDatabase::getScheduleByDoctorID(medId);
    vector<WorkSession> wSessions =
        HospitalDatabase::getWorkSessionsByDoctorID(medId);
    WorkSchedule avaiableSessions = medSchedule.getWorkSchedule();
    if (wSessions.size() == 0) {
        cout << "Não há horarios disponíveis para marcar." << endl;
        while (true) {
            cout << "Digite [0] para voltar." << endl;
            int choice;
            cin >> choice;
            if (choice == 0) {
                HospitalInterface::patientInterface();
                break;
            }
        }
    } else {
        // Existem horários sim!
        cout << "[-1] Voltar " << endl;
        int pickedSession = choiceMaker(avaiableSessions.toString());
        if (pickedSession == -1) {
            HospitalInterface::patientInterface();
        }

        while (pickedSession < 0 ||
               pickedSession >
                   (avaiableSessions.getWorkSchedule().size() - 1)) {
            system("clear");
            cout << "Opção invalida, tente novamente... " << endl;
            cout << "[-1] Voltar " << endl;
            int pickedSession = choiceMaker(avaiableSessions.toString());
            if (pickedSession = -1) {
                HospitalInterface::patientInterface();
            }
        }

        // Agora já sabemos que a opc é válida, then:
        Session appointMe =
            avaiableSessions.getWorkSchedule()[pickedSession - 1];
        Appointment createMe(appointMe, "scheduled",
                             this->getCurrentUser()->getUserID(), medId,
                             "consulta"); // nome ok? LOL
        HospitalDatabase::createAppointment(createMe);
        cout << "Operação realizada com sucesso" << endl;
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

void HospitalInterface::pacienteListarConsultas() {
    system("clear");
    titleMaker("LISTAGEM DE CONSULTAS");

    int patientId = this->getCurrentUser()->getUserID();

    vector<Appointment> patientAppointments =
        HospitalDatabase::getAppointmentsByPatientID(patientId);
    if (patientAppointments.size() == 0) {
        cout << "Você não possui consultas marcadas." << endl;
    } else {
        cout << "Consultas marcadas:" << endl;
        for (int i = 0; i < patientAppointments.size(); i++) {
            cout << "ID: " << patientAppointments[i].getId() << endl;
            cout << "Data: "
                 << patientAppointments[i].getSession().getDate().toString()
                 << endl;
            cout << "Hora: "
                 << patientAppointments[i].getSession().getTime().toString()
                 << endl;
            cout << "Médico: "
                 << HospitalDatabase::getDoctorByID(
                        patientAppointments[i].getDoctorID())
                        ->getName()
                 << endl;
            cout << "Procedimento: " << patientAppointments[i].getProcedure()
                 << endl;
            cout << "Status: " << patientAppointments[i].getStatus() << endl;
            cout << endl;
        }
    }
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

    // HospitalDatabase::deleteAppointment(appointmentId);

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

void HospitalInterface::pacienteListarDados() {
    system("clear");
    titleMaker("LISTAGEM DE DADOS");
    User *patient = this->getCurrentUser();
    int patientId = patient->getUserID();

    titleMaker("Dados Pessoais");
    cout << "Nome: " << patient->getName() << endl;
    cout << "CPF: " << HospitalDatabase::getPatientData(patientId, "CPF")
         << endl;
    cout << "Data de Nascimento: "
         << HospitalDatabase::getPatientData(patientId, "BIRTHDATE") << endl;
    cout << "Gênero: " << HospitalDatabase::getPatientData(patientId, "GENDER")
         << endl;
    cout << "Estado Civil: "
         << HospitalDatabase::getPatientData(patientId, "CIVILSTATUS") << endl;

    titleMaker("Contato");
    cout << "Endereço: "
         << HospitalDatabase::getPatientData(patientId, "ADDRESS") << endl;
    cout << "Telefone: "
         << HospitalDatabase::getPatientData(patientId, "PHONENUMBER") << endl;
    cout << "Email: " << HospitalDatabase::getPatientData(patientId, "EMAIL")
         << endl;

    hr();

    while (true) {
        cout << "Digite [0] para voltar." << endl;
        int choice;
        cin >> choice;
        if (choice == 0) {
            break;
        } // ss, é isso mesmo, não tem break aqui, pq o break é no final do
          // while boa noite!
    }
    HospitalInterface::patientInterface();
}

void HospitalInterface::pacienteAtualizarDados() {
    system("clear");
    titleMaker("ATUALIZAÇÃO DE DADOS");
    User *patient = this->getCurrentUser();
    int patientId = patient->getUserID();
    titleMaker("Dados Pessoais");
    cout << "Nome: " << HospitalDatabase::getPatientData(patientId, "NAME")
         << endl;
    cout << "CPF: " << HospitalDatabase::getPatientData(patientId, "CPF")
         << endl;
    cout << "Data de Nascimento: "
         << HospitalDatabase::getPatientData(patientId, "BIRTHDATE") << endl;
    cout << "Gênero: " << HospitalDatabase::getPatientData(patientId, "GENDER")
         << endl;
    cout << "Estado Civil: "
         << HospitalDatabase::getPatientData(patientId, "CIVILSTATUS") << endl;

    titleMaker("Contato");
    cout << "Endereço: "
         << HospitalDatabase::getPatientData(patientId, "ADDRESS") << endl;
    cout << "Telefone: "
         << HospitalDatabase::getPatientData(patientId, "PHONENUMBER") << endl;
    cout << "Email: " << HospitalDatabase::getPatientData(patientId, "EMAIL")
         << endl;

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
        hr();
        HospitalDatabase::updatePatient(patientId, "CPF", entrada);
        cout << "CPF atualizado para "
             << HospitalDatabase::getPatientData(patientId, "CPF") << "!"
             << endl;
        break;
    case 2:
        system("clear");
        titleMaker("ATUALIZAÇÃO DE DADOS");
        cout << "Digite a nova Data de Nascimento (no formato DD/MM/AAAA): ";
        cin >> entrada;
        getchar();
        hr();
        HospitalDatabase::updatePatient(patientId, "BIRTHDATE", entrada);
        cout << "Data de Nascimento atualizada para atualizado para "
             << HospitalDatabase::getPatientData(patientId, "BIRTHDATE")
             << "!" << endl;
        break;
    case 3:
        system("clear");
        titleMaker("ATUALIZAÇÃO DE DADOS");
        cout << "Digite a opção desejada: " << endl;
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
        HospitalDatabase::updatePatient(patientId, "GENDER",
                                        dataChoices[dataChoice - 1]);
        cout << "Gênero atualizado para "
             << HospitalDatabase::getPatientData(patientId, "GENDER") << "!" << endl;
        break;
    case 4:
        system("clear");
        titleMaker("ATUALIZAÇÃO DE DADOS");
        cout << "Digite a opção desejada: " << endl;
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
        HospitalDatabase::updatePatient(patientId, "CIVILSTATUS",
                                        dataChoices[dataChoice - 1]);
        cout << "Estado civil atualizado para "
             << HospitalDatabase::getPatientData(patientId, "CIVILSTATUS") << "!" << endl;
        break;
    case 5:
        system("clear");
        titleMaker("ATUALIZAÇÃO DE DADOS");
        cout << "Digite o novo endereço: ";
        cin >> entrada;
        getchar();
        HospitalDatabase::updatePatient(patientId, "ADDRESS", entrada);
        hr();
        cout << "Endereço atualizado para " 
             << HospitalDatabase::getPatientData(patientId, "ADDRESS") << "!"
             << endl;
        break;
    case 6:
        system("clear");
        titleMaker("ATUALIZAÇÃO DE DADOS");
        cout << "Digite o novo telefone: ";
        cin >> entrada;
        getchar();
        hr();

        HospitalDatabase::updatePatient(patientId, "PHONENUMBER", entrada);
        cout << "Telefone atualizado para " << HospitalDatabase::getPatientData(patientId, "PHONENUMBER") << "!"
             << endl;
        break;
    case 7:
        system("clear");
        titleMaker("ATUALIZAÇÃO DE DADOS");
        cout << "Digite o novo email: ";
        cin >> entrada;
        getchar();
        hr();
        HospitalDatabase::updatePatient(patientId, "EMAIL", entrada);
        cout << "Email atualizado para " << HospitalDatabase::getPatientData(patientId, "EMAIL") << "!" << endl;
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

/* JURASSICO (pq guardei no fundo igual um fossil lol):
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

    if (medId == 0) {
        HospitalInterface::patientInterface();
        return;
    }

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
// cout << "Consulta marcada com sucesso para a data " << data << " às " <<
// hora << "!" << endl;
/*
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
*/
