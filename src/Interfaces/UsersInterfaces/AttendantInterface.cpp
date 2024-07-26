#include "../../../include/Interface.h"

void HospitalInterface::attendantInterface() {
    if (!this->assertAccessLevel(2)) {
        HospitalInterface::entryProgramInterface();
    }

    titleMaker("CENTRAL DO ATENDENTE");

    vector<string> choices;
    choices.push_back("Voltar");
    int choice = choiceMaker(choices);
    HospitalInterface::entryProgramInterface();
}
