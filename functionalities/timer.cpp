#include <iostream>
#include <string>
#include <map> 
#include <chrono>
#include <ctime>

int get_time(){
    std::time_t now = std::time(NULL); 
    std::tm *curr_time = localtime(&now); 
    int hour = curr_time -> tm_hour; 
    // std::cout << curr_time -> tm_hour;  
    return hour; 
} 