#include <iostream>
#include <string>
#include <map> 
#include <functional>
#include <optional> 
#include <cstdlib> // for system

#include "../includes/commands.h"
#include "../includes/main.h"
#include "../includes/checklist.h"
#include "../includes/dopamine.h"


// input to output folow
// recieve command
// parse command
// 

struct Parsed_Cmd {
    std::string cmd; 
    std::string type;
}; 

Checklist cl; 

// create 'cr' function 
void create(std::string type){
    // std::cout << "Creating..." << type; // debug test

    // creation types
    // std::map<std::string, std::function<void()>> creation_types; 
    if(type == "checklist"){
        // std::cout << "\nCreating checklist..."; // debug
        cl.create_checklist(); 
    }
    if(type == "dopamine"){
        action_input(); 
    }       

}

Parsed_Cmd check_for_command(std::string c){
    std::string cmd; 
    std::string type; 
    // std::string cmds[] = {"cr", "op", "rm"}; 
    std::map<std::string, std::function<void(std::string)>> commands; 
    commands["cr"] = create; 
    
    int len = sizeof(commands); //sizeof gets the size in bytes (24, 8 bytes each)
    // find location of seperator '.' 
    std::size_t sep = c.find('.'); // pos1 is location of speerator 
    char last  = c.back(); 
    // if(sep != std::string::npos){std::cout << sep;}
    cmd = c.substr(0, sep); 
    type = c.substr(sep+1, last); 
    
    // std::cout << "Mem size: " << len<< "\nCommand is: " << cmd << "\nType is: "<< type << "\n"; //debug 

    // check if input is command 
    for (int i = 0; i < len; i++){
        if(commands.count(cmd) > 0){ // if the command is equal to something in the possible commadn types 
            // std::cout << "Found command type"; // debug

            Parsed_Cmd p_cmd = {cmd, type}; 

            std::function<void(std::string)> func = commands[cmd]; // auto is for any type of var based on initial val
            func(type); 
            return p_cmd; 
        }
    }
    
    std::cout << "Did not find command"; 
    
    Parsed_Cmd p_cmd = {"none", "none"}; 
    return p_cmd; 
}


void command(std::string c){
    // std::cout << "Received command: '" << c << "'\n"; // Debug
    //parse the string for the command and the type
    
    //parse the string and pass the command to checkForCommands()
    check_for_command(c); 
    

} 


