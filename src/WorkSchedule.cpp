vector<Section> removeSection(vector<Section> sections, Section sectionToRemove) {
    
    vector<Section> result;
    for(Section section : sections){
      if(not sectionEquals(section, sectionToRemove)){
        result.push_back(section);
      }
    }

    return result;
}