#include <iostream>
#include <regex>
//#include <string>
#include "Transformer_Repo.h"
#include "Battle_Simulator.h"

void Display_Menu() 
{
    std::cout << "\nEnter a number between 1 through 5 and then press Enter\n";
    std::cout << "1. Add Transformer\n";
    std::cout << "2. Remove Transformer\n";
    std::cout << "3. Simulate Battle\n";
    std::cout << "4. View Transformer Info\n";
    std::cout << "5. Exit\n";
}

void Add_Transformer(Transformer_Repository& repo) 
{
    std::string name, faction;
    int strength;
    std::cout << "Enter transformer name: ";
    std::cin >> name;
    std::cout << "Enter faction: ";
    std::cin >> faction;
    std::cout << "Enter strength: ";
    std::cin >> strength;

    repo.add(Transformer(name, faction, strength));
    std::cout << "Transformer added successfully!\n";
}

void Remove_Transformer(Transformer_Repository& repo) 
{
    std::string name;
    std::cout << "Enter transformer name to remove: ";
    std::cin >> name;
    repo.remove(name);
    std::cout << "Transformer removed successfully!\n";
}

void Simulate_Battle(Transformer_Repository& repo, BattleSimulator& simulator)
{
    std::string name1, name2;
    std::cout << "Enter name of the first transformer: ";
    std::cin >> name1;
    std::cout << "Enter name of the second transformer: ";
    std::cin >> name2;

    Transformer* t1 = repo.get(name1);
    Transformer* t2 = repo.get(name2);

    if (t1 && t2) 
    {
        std::cout << simulator.battle(*t1, *t2) << "\n";
    }
    else 
    {
        std::cout << "One or both transformers not found.\n";
    }
}

void View_Transformer_Info(Transformer_Repository& repo) 
{
    std::string name;
    std::cout << "Enter transformer name to view info: ";
    std::cin >> name;
    Transformer* t = repo.get(name);
    if (t) 
    {
        std::cout << "Name: " << t->getName() << "\n";
        std::cout << "Faction: " << t->getFaction() << "\n";
        std::cout << "Strength: " << t->getStrength() << "\n";
        std::cout << "Wins: " << t->getWins() << "\n";
        std::cout << "Losses: " << t->getLosses() << "\n";
    }
    else 
    {
        std::cout << "Transformer not found.\n";
    }
}

int main() 
{
    Transformer_Repository repo;
    BattleSimulator simulator;
    std::string input;
    std::regex pattern("[1-5]+"); // regex expression that will only accept numbers 1 through 5

    int choice = 0;

    std::cout << "\n===== Welcome to the Battle Simulator =====\n";
    //std::cout << "\n===== Who will be fighting today? =====\n";

    while (true) 
    {
        Display_Menu();
        std::cin >> input;

        if (std::regex_match(input, pattern)) 
        {
            choice = atoi(input.c_str());
        }

        switch (choice)
        {
            case 1: 
                Add_Transformer(repo); 
                break;
            case 2: 
                Remove_Transformer(repo); 
                break;
            case 3: 
                Simulate_Battle(repo, simulator); 
                break;
            case 4: 
                View_Transformer_Info(repo); 
                break;
            case 5: 
                return 0;
            default: 
                std::cout << "Invalid choice! Please choose a number from 1 to 5.\n";
        }
    }
    std::cout << "\n===== Thanks for playing Battle Simualtor. =====\n";
}