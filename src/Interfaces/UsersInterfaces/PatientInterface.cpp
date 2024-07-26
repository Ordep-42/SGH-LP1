#include "../../../include/Interface.h"

void HospitalInterface::patientInterface() {
    if (!this->assertAccessLevel(1)) {
        HospitalInterface::entryProgramInterface();
    }

    titleMaker("CENTRAL DO PACIENTE");

    vector<string> choices;
    choices.push_back("Voltar");
    int choice = choiceMaker(choices);
    HospitalInterface::entryProgramInterface();
}
