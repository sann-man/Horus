// Horus uses Algos to find key words to work as AI. 

#include <iostream> 
#include <string> 
#include <functional> 
#include <map> 
#include <optional> 
#include "../includes/main.h"
#include "../includes/checklist.h"
#include "../includes/dopamine.h"

//horus
std::string functionalities[] = {"checklist", "dopamine"}; 

void horus_dopamine(std::string s){
    std::string show[] = {"show"}; 
    std::string action[] = {"action", "new"}; 

    // check if s contains any values from arrs
}   

void horus(std::string s){

    // FOR JUST DOPAMINE FOR NOW 
    //horus.dopaminee
    std::cout << "Debug: horus"; 
    std::string substr = "dopamine"; 

    // by calling function we are providing context 
    if(s.find(substr) != std::string::npos){
        horus_dopamine(s); 
    }
}



