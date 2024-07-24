#ifndef SCHEDULEDAPPOINTMENTS_H
#define SCHEDULEDAPPOINTMENTS_H

#include <Appointment.h>
#include <string>
#include <vector>

using namespace std;

class ScheduledAppointments {
private:
    vector<Appointment> appointments;
    int doctor_id; //??
    // se colocar doctor id, vai ter q fazer um vetor de scheduled appointments pra acessar o de todos os medicos, oq é bem viavel.

public:
    ScheduledAppointments() = default;

    ScheduledAppointments getAppointments();
    // Métodos
    void makeAppointment(Appointment newAppointment);
    vector<Appointment> searchByPatient(int byPatientID);
    //Schedule searchByTime();
    //Schedule searchById();
    vector<Appointment> searchByDate();
    vector<Appointment> searchByStatus();

    bool isAppointed(Session test);
    Section lastSection(vector<Section> sections);
    // next

    Section nextWorkSection();
    Appointment nextAppointment();
    // Pra marcar uma consulta: 
    Section nextAvaiableSection();
};

// Funções auxiliares


#endif // !APPOINTMENT_H
