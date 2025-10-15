#include <iostream> 
#include <string> 
#include "../includes/main.h"
#include "../includes/checklist.h"
#include "../includes/commands.h"
#include <cstdlib> // for system
#include <cctype>
#include <array> 
#include <fstream>
#include <vector>


// struct Checklist_Values {
//     std::string name; 
//     std::vector<std::string> items = {}; 
// };

struct Checklist_Types{
    std::string created; 
    std::string existing; 
};


// Checklist_Values cl_values; 
Checklist_Commands cl_cmds; 
Checklist_Types cl_types; 

Checklist::Checklist(std::string checklist_name, std::vector<std::string> checklist_items){
    name = checklist_name; 
    items = checklist_items; 
}; 

void Checklist::create_checklist(){
    // create new checklist
    //prompt user for name
    std::cout << "\033[0;34m"; // dim blue
    std::cout << "[->] Enter checklist name: "; 
    std::cout << "\033[0m"; // reset color

    std::getline(std::cin, name); 

    created_checklist_ui(name, items); 
}
// Create checlist operation flow 

void Checklist::checklist_items(std::string type, std::string name){

    // creating a new checklist
    std::cout << type; 
    std::ifstream r("db/checklist.txt"); 
    int line_num = 0; 
    bool line_has_content = false; 
    std::string line; 

    // check if the file is EMPTY
    if(r.is_open()){
        while(std::getline(r, line)){
            line_num++; 
            if(!line.empty()){
                line_has_content = true;
            } 
        }
        r.close(); 
    }
    // prompt user to choose what they want to do 
    std::string cmd; 
    char id = '\0'; //  \0 = null character
    // Add new item
    while(id != cl_cmds.exit){
        std::getline(std::cin, cmd); 

        if(cmd.length() > 0){
            id = cmd[0]; 
        }
        if(id == cl_cmds.add){
            char last = cmd.back();  
            std::string n = cmd.substr(1, last); 
            items.push_back(n); 
            created_checklist_ui(name, items); 

        }
    }
    
    std::ofstream w("db/checklist.txt", std::ios::app);
    if(w.is_open() && line_has_content == false){
        w << name << ": "; 
        for(const auto& item: items){
            w << item << ", ";
        }
        w.flush() ; 
        w.close();  
    }
    else{
        w << "\n" << name << ": "; 
        for(const auto& item: items){w << item << ", ";}
        w.flush() ; 
        w.close();  
    }
    clear_console(); 
    main(); 
}


void Checklist::created_checklist_ui(std::string name, std::vector<std::string>){
    clear_console(); 
    // strings for dash marks 
    std::string r; std::string l; 
    int len = 25 - name.length(); // amount of dashes 
    if(len % 2 != 0){
        r.append(len/2 + 1, ' '); // append is for char; 
        l.append(len/2, ' '); 
    }
    else{
        r.append(len/2, ' '); 
        l.append(len/2, ' '); 
    }
    

    std::cout << "\033[1;34m"; // bright blue
    std::cout << "┌─────────────────────────┐\n";
    std::cout << "│"<<r << name << l <<   "│\n";  
    std::cout << "└─────────────────────────┘\n";
    // std::cout << r << " "<< name << " " << l <<"\n\n"; 
    if(items.size() > 0){        
        //for "|" placement
        int count = 0; 
        std::cout << "┌─────────────────────────┐\n";

        for(const auto& item: items){
            std::string l;  
            int len = 18 - item.length(); 
            l.append(len, ' ');
            std::cout << "│ [" << count++ << "] □ " << item << l <<  "│" << "\n";
        }
        std::cout << "└─────────────────────────┘\n";

    }
    
    // std::cout << "1.) Empty ✅\n\n"; // temp empty value (not real) 

    std::cout << "[->] Enter command: "; 

    std::cout << "\033[0m"; // reset color

    checklist_items(cl_types.created, name);     
}

// Create checkist


// Open checklist


// Edit checklist


// Delete checklist



