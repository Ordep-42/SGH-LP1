
#include "../../../include/HospitalDatabase/HospitalDatabase.h"
#include "../../../include/Interface.h"
#include "../../../include/Users/Doctor.h"

void HospitalInterface::doctorInterface() {
    titleMaker("CENTRAL DO DOUTOR");
    Doctor *doctor = dynamic_cast<Doctor *>(this->getCurrentUser());
    int doctorID = doctor->getUserID();
    vector<string> choices;
    choices.push_back("Verificar Paciente");
    choices.push_back("Concluir consulta");
    choices.push_back("Voltar");

    int choice = choiceMaker(choices);
    do {
        switch (choice) {
        case 1:
            HospitalInterface::doctorCheckPatient(doctorID);
            break;
        case 2:
            HospitalInterface::doctorConcludeAppointment(doctorID);
            break;
        default:
            break;
        }
    } while (choice > 3 || choice < 0);
}

void HospitalInterface::doctorCheckPatient(int doctorID) {
    // Confira no src/HospitalDatabase/ScheduledMethods/getMethods.cpp
    vector<WorkSession> workSessions =
        HospitalDatabase::getWorkSessionsByDoctorID(doctorID);

    // possivelmente seria bom modificar o "toString" pra nao incluir TODOS os
    // campos.

    cout << "operacao realizada com sucesso" << endl;
    HospitalInterface::doctorInterface();
}

void HospitalInterface::doctorConcludeAppointment(int doctorID) {
    // Confira no src/HospitalDatabase/ScheduledMethods/getMethods.cpp
    Schedule doctorSchedule = HospitalDatabase::getScheduleByDoctorID(doctorID);
    ScheduledAppointments sAppointments =
        doctorSchedule.getScheduledAppointments().AppointmentsToHappen();

    system("clear");
    if (sAppointments.getAppointments().size() == 0) {
        cout << "Não há consultas marcadas" << endl;
        system("pause");

        return;
    }

    vector<string> appointments = sAppointments.toString();
    int choice = choiceMaker(appointments);
    Appointment myApp = sAppointments.getAppointments()[choice - 1];
    unsigned short deleteMe = static_cast<unsigned short>(myApp.getId());
    // HospitalDatabase::deleteAppointment(deleteMe);

    myApp.setStatus("conclude");
    HospitalDatabase::createAppointment(myApp);

    system("pause");
    cout << "operacao realizada com sucesso" << endl;
    HospitalInterface::doctorInterface();
}
