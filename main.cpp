#define NUM_OF_SIMS 1

#include <iostream>
#include <regex>
#include "Transformer_Main_Loop.h"


int main() 
{
    std::string input;
    std::regex pattern("[1-5]+"); // regex expression that will only accept numbers 1 through 5

    int choice = 0;

    std::cout << "\n===== Welcome to the Battle Simulator =====\n";
    if (NUM_OF_SIMS > 1)
    {
        std::cout << "===== Who will be fighting today? =====\n";
    }
    Transformer_Main_Loop loop;
    loop.Game_Loop();

    return 0;
}