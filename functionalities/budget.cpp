// Budget
// Budget features
    // Show spending amounts
        // Be able to change from weekly, to bi-weekly, to monthly 
    // Show current account balances
        // This should be a seperate feature meaning you can do something like c.balance = "see my balance" with horus


#include <iostream> 
#include <string>
#include <fstream> 

void accounts(){
    std::cout << "Debug: accounts()"; 
    int checkings; 
    int savings; 
    int money_market; 

    std::ifstream r("db/budget.txt");
    std::string line;  
    if(r.is_open()){ 
        while(std::getline(r, line)){
            std::cout << "\n" << line ;   
        }
    }


}