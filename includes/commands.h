#ifndef COMMANDS_H
#define COMMANDS_H
#include <string> 

void command(std::string c); 

struct Checklist_Commands { //name is subject to change if the symbols can be reused for other functionalities
    char add = '+'; 
    char remove = '-'; 
    char edit = 'e'; 
    char exit = 'x'; 
}; 


#endif

