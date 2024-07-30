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
        HospitalInterface::marcarConsultaNOBD();
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

    Schedule medSchedule = getScheduleByDoctorIdFromBD(medId); 

     //int  pickedSession = choiceMaker(medSchedule.avaiableSessions().toStringVector();); // 0 volta?

    // implementar o toStringVector tbm
    vector<string> SessionsToChoice = medSchedule.avaiableSessions().toStringVector();
    int pickedSession = choiceMaker(SessionsToChoice);

    MarcarConsulta(medSchedule.avaiableSessions()[pickedSession]);
    
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

    // int patientId = this->getCurrentUser()->getUserID();

    // Appointment novaConsulta = Appointment(appointmentSession, "Marcado",
    //                                        patientId, medId, consultType);

    // // AGENDAR NO BANCO DE DADOS
}

void HospitalInterface::listarConsultas() {
    system("clear");
    titleMaker("LISTAR CONSULTAS");

    HospitalDatabase::listAppointmentsByPatient(
        this->getCurrentUser()->getUserID());
    hr();
}

void HospitalInterface::ListarConsultas(){
    ScheduledAppointments patientAppointments = Banco.getConsultasByPatientId(<id do paciente>); 
    printarVetorDeStrings(patientAppointments.toString);
    System("pause");

    //volta pra algum lugar no codigo... 

}
void HospitalInterface::cancelarConsulta(){
    ScheduledAppointments consultasAgendadas = Banco.getAppointmentsByPatientId(<id do paciente>).searchByStatus("scheduled"); 
    if(patientAppointments.getAppointments().size() == 0) { cout << "\"Mas ninguém veio\""; }
    else{
        int choice = choiceMaker(consultasAgendadas.toString());

        TrocarStatusNoBanco(consultasAgendadas.getAppointments()[choice].getId(), "canceled");
        cout << " sábado animado "; 
    }
}


// void HospitalInterface::listarDados(){

// }
// //    choices.push_back("Atualizar dados");