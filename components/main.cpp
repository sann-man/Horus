#include <iostream> 
#include <string>
#include "../includes/commands.h"
#include "../includes/main.h"
#include "../includes/main.h"
#include "../includes/timer.h" 
#include <cstdlib> // for system

//Program intro

void clear_console(){system("clear");}

void intro() {
    std::cout << "\033[1;34m"; // bright blue
    std::cout << "┌─────────────────────────┐\n";
    std::cout << "│  [ CONSOLE.MAIN ]       │\n";
    std::cout << "└─────────────────────────┘\n\n";
    std::cout << "\033[1;36m"; // cyan
    std::cout << ">> Welcome back, Rahsaan...\n";
    std::cout << ">> System ready.\n\n";
    std::cout << "\033[0;34m"; // dim blue
    std::cout << "[->] Enter command: ";
    std::cout << "\033[0m"; // reset color
}

int main(){ 
    intro(); 
    std::string c; 
    std::getline(std::cin, c); 

    command(c); 
} 


