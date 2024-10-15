//#define NUM_OF_SIMS 1

#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <vector>
#include "Transformer_Main_Loop.h"


int main() 
{
    std::string text_from_file;
    std::vector<std::string> Combatant_Vector;
    std::string input;
    std::regex pattern("[1-5]+"); // regex expression that will only accept numbers 1 through 5
    int choice = 0;


    std::ifstream myfile("Combatants_List.txt");

    if (!myfile.is_open()) 
    { 
        std::cout << "\nCan not open Combatants_list.txt\n";
        return 0;
    }
    while (!myfile.eof()) 
    {
        std::getline(myfile, text_from_file);
        Combatant_Vector.push_back(text_from_file);
    }

    std::cout << "\n===== Welcome to the Battle Simulator =====\n";
    std::cout << "===== Who will be fighting today? =====\n";
    printf("%-10s%-25s\n", "Index", "Name");

    for(int i = 1; i < (Combatant_Vector.size() + 1); i++)
    {
        printf("%-10d%-25s\n", i, Combatant_Vector.at((i - 1)).c_str());
    }

    std::cin >> input;
    std::cin.ignore(1, '\n');

    if (std::regex_match(input, pattern))
    {
        choice = atoi(input.c_str());
    }
    else
    {
        std::cout << "Error\n";
        return 0;
    }

    switch (choice)
    {
    case 1:
    {
        std::cout << "\n";
        Transformer_Main_Loop loop;
        loop.Game_Loop();
        break;
    }
    case 2:
        std::cout << "2\n";
        //Remove_Transformer(repo);
        break;
    //case 3:

        //return 0;
    default:
        std::cout << "Invalid choice! Please choose a number from 1 to 3.\n";
    }

    std::cout << "\n===== Thanks for playing Battle Simualtor. =====\n";
    return 0;
}