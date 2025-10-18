// import, includes, etc
#include <iostream> 
#include "../includes/timer.h"
#include <map> 
#include <string> 
#include <fstream> 

std::map<std::string, int> dopaminergic_actions = {
    {"weed", 50}, {"scrolling", 25}, {"clash", 30} 
}; 

void render_visualizer(){
    std::cout << "Debug: render_visualizer()\n"; 
    std::ifstream r("db/dopamine_visualizer.txt");
    std::string line; 

    if(r.is_open()){
        // std::cout << "debug if"; 
        while(std::getline(r, line)){ 
            std::cout << line << "\n"; 
        }
        r.close(); 
    }
    else{ 
        std::cout << "File note open"; 
    }

}

void erase_content(){
    std::cout << "Debug: erase_content()\n"; 
    std::ofstream w("db/dopamine_visualizer.txt", std::ofstream::out | std::ofstream::trunc); 
    w.close(); 
}

void update_visualizer(int y){ 
    std::cout << "Debug: update_visualizer()\n"; 

    std::map<int, std::string> visualizer_map = {
        {0, "    DRV                                            \n"}, 
        {1, " 100 ╻                                             \n"}, 
        {2, "  90 ╻                                             \n"}, 
        {3, "  80 ╻                                             \n"}, 
        {4, "  70 ╻                                             \n"}, 
        {5, "  60 ╻                                             \n"}, 
        {6, "  50 ╻                                             \n"}, 
        {7, "  40 ╻                                             \n"}, 
        {8, "  30 ╻                                             \n"}, 
        {9, "  20 ╻                                             \n"}, 
        {10, "  10 ╻                                            \n"}, 
        {11, "      ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ Time \n"}, 
        {12, "      0 0 0 0 0 0 1 1 1 0 0 0 0 0 0 0 0 0 1 1 1 0 \n"}, 
        {13, "      4 5 6 7 8 9 0 1 2 1 2 3 4 5 6 7 8 9 0 1 2 1 \n"}, 
        {14, "      AM              PM                      AM  \n"}
    }; 
   
    //erase content to start
    erase_content(); 

    std::ofstream w("db/dopamine_visualizer.txt");

    // x = 1 - 10 

    // gettime for x coord
    // get y coord from map val assoc. with user value (key) 
        // Val given by action_input function 
    
    int x = get_time();  

    x = x * 2;  // conversion
    // convert x for coord 

    // convert using custom eq 
    int eq = ((100 - (1 * y)) / 10) + 1;
    // for loop to set each row under top most row 

    // 43 white spaces 

    // RENDER  
    std::cout << "\n"; // initial spacing; 

    for(int i = 0; i < visualizer_map.size(); i++){
        std::string l = visualizer_map[i];
        // std::cout << eq; 
        if( i >= eq && i <= 10){
            l[x] = '*'; 
            w << l; 
        }
        else{
            w << l; 
        }
    }

    w.close(); 
    render_visualizer(); 
}

int dopamine_level(int level){
    std::string file = "db/dopamine_level.txt"; 
    // read the file
        // check if the value is the same 
            // if not change value
    std::string line; 
    std::ifstream r(file); 
    if(r.is_open()){
        std::cout << "Debug: dopamine_level.txt is open"; 
        std::getline(r, line); 
        std:: cout << line; 
        if(std::stoi(line) != 0){
            level += std::stoi(line); 
        }

        if(level > 100){
            level = 100; 
        }
    }


    std::ofstream w(file); 
    if(w.is_open()){
        w << level; 
    }

    w.close(); 
    update_visualizer(level); 

    return 0; 
}

int action_input(){
    std::cout << "Debug: action_input()\n"; 

    int y; 
    std::string action; 
    std::cout << "\033[1;34m"; // bright blue 
    std::cout << "\n[->] Enter your dopaminergic action\n ~~  Or\n[->] Enter 'show' to see current levels\n[->] "; 
    std::cout << "\033[0m"; // reset color
    std::getline(std::cin, action); 

    if(action == "show"){
        render_visualizer(); 
    }
    else{ 
        auto f = dopaminergic_actions.find(action); 

        if(f != dopaminergic_actions.end()){
            // std::cout << "Action found"; 
            y = dopaminergic_actions[action]; 
            dopamine_level(y); 
            return y; 

        }  
    }
    // std::cout << "Action:" << action; 

    return 0; 
}




// void plot(int x, int y){
//     int plot[] = {}; 

//     //translate time to post
//     int x = get_time() * 2; 
//     int y;    

//     int eq = 100 - (1 * y);
//     if 

// }


// types of dopamine, Short form content, masturbation, weed, tobacco, food, Sex, etc...
// Track progress with visual chart


