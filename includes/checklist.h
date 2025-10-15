#ifndef CHECKLIST_H
#define CHECKLIST_H
#include <string>
#include <vector>

class Checklist {
private:
    std::string name; 
    std::vector<std::string> items;

public:
    Checklist(std::string checklist_name = "", std::vector<std::string> items = {});
    void create_checklist(); 
    void checklist_items(std::string, std::string); 
    void created_checklist_ui(std::string, std::vector<std::string>); 
};


#endif


// use class like
// Checklist list1("My List");  // Uses default empty vector
// Checklist list2("My List", {"item1", "item2"});  // Provides items