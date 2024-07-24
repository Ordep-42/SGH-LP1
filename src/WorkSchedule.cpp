#include "../include/WorkSchedule.h"

using namespace std;

WorkSchedule::WorkSchedule(vector<WorkSession> newSchedule, int newId, int newDoctor_id)
    : schedule(newSchedule), id(newId), doctor_id(newDoctor_id) {}

// vector<Section> removeSection(vector<Section> sections, Section sectionToRemove) {
    
//     vector<Section> result;
//     for(Section section : sections){
//       if(not sectionEquals(section, sectionToRemove)){
//         result.push_back(section);
//       }
//     }

//     return result;
// }