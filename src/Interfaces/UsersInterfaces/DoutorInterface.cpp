#include "../../../include/Interface.h"

void HospitalInterface::doctorInterface() {
    if (!this->assertAccessLevel(3))
        HospitalInterface::entryProgramInterface();

    titleMaker("CENTRAL DO DOUTOR");

    vector<string> choices;
    choices.push_back("Voltar");
    int choice = choiceMaker(choices);
    HospitalInterface::entryProgramInterface();
}
