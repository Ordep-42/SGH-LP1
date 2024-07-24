WorkSchedule WorkSchedule::searchByStatus(string testStatus){
    vector<WorkSession> vetorWS;  
    for(WorkSession wSession : schedule){
        if(wSession.getStatus() == testStatus){
            vetorWS.push_back(wSession);   
        }
    } 
    // Sem ser um vetor vamos ter mais dados, vai que, né... 
    WorkSchedule scheduleByPatient(vetorWS, id, doctor_id); 
    return scheduleByPatient;
}