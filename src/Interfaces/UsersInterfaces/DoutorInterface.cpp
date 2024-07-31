
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
    // choices.push_back("Solicitar equipamento médico");
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
    Schedule doctorSchedule = HospitalDatabase::getScheduleByDoctorID(doctorID);
    ScheduledAppointments appointments =
        doctorSchedule.getScheduledAppointments().AppointmentsToHappen();
    int choice = choiceMaker(
        appointments.toString()); // possivelmente seria bom modificar o
                                  // "toString" pra nao incluir TODOS os campos.

    cout << appointments.toString()[choice - 1];
    system("pause");
}

void HospitalInterface::doctorConcludeAppointment(int doctorID) {
    // Confira no src/HospitalDatabase/ScheduledMethods/getMethods.cpp
    Schedule doctorSchedule = HospitalDatabase::getScheduleByDoctorID(doctorID);
    ScheduledAppointments appointments =
        doctorSchedule.getScheduledAppointments().AppointmentsToHappen();
    if (appointments.getAppointments().size() == 0) {
        cout << "Não há consultas marcadas";
        system("pause");

        return;
    }
}
