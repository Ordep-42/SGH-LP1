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
    choices.push_back("Listas consultas");
    choices.push_back("Cancelar consulta");
    choices.push_back("Listar dados");
    choices.push_back("Atualizar dados");
    choices.push_back("Voltar");
    int choice = choiceMaker(choices);

    switch (choice) {
    case 1:
        HospitalInterface::marcarConsulta();
        break;
    case 6:
        this->setCurrentUser(nullptr);
        HospitalInterface::entryProgramInterface();
        break;
    default:

        break;
    }
}

void HospitalInterface::marcarConsulta() {
    int medId;

    system("clear");
    titleMaker("AGENDAMENTO DE CONSULTA");
    set<int> IdList = HospitalDatabase::listDoctors();
    hr();
    cout << "Digite o ID do médico que você quer se consultar." << endl;
    cout << "0 para voltar.\n";

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

    system("clear");
    titleMaker("AGENDAMENTO DE CONSULTA");
    string data;
    string hora;
    cout << "Formato: DD/MM/YYYY\n";
    cout << "Digite a DATA para realizar a consulta: ";
    cin >> data;
    getchar();
    cout << "\n";
    cout << "Formato: HH:MM\n";
    cout << "Digite a HORA para realizar a consulta: ";
    cin >> hora;
    getchar();

    Session appointmentSession =
        Session(stringToTime(hora), stringToDate(data));

    system("clear");
    titleMaker("AGENDAMENTEO DE CONSULTA");
    string consultType;
    cout << "Qual o tipo de consulta?\n";
    cin >> consultType;
    getchar();
    Appointment novoAgendamento("Marcada", 3, 3, appointmentSession);
}
