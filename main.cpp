#include <iostream>
#include <regex>
//#include <string>
#include "Transformer_Repo.h"
#include "Battle_Simulator.h"

void Display_List(Transformer_Repository& repo)
{
    printf("%-10s%-25s%-20s%-10s%-10s%-10s\n", "Index", "Name", "Faction", "Strength", "Wins", "Losses");

    std::vector<Transformer> t = repo.getAll();
    int index = 1;
    for (auto& it : t)
    {
        printf("%-10d%-25s%-20s%-10d%-10d%-10d\n", index, 
                                                   it.getName().c_str(), 
                                                   it.getFaction().c_str(), 
                                                   it.getStrength(),
                                                   it.getWins(), 
                                                   it.getLosses());
        index++;
    }
}

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

    int a = repo.add(Transformer(name, faction, strength));
    if (a == 0)
    {
        std::cout << "Transformer added successfully!\n";
    }
    else
    {
        std::cout << "That Transformer has already been added.\n";
    }
}

void Remove_Transformer(Transformer_Repository& repo) 
{
    std::string input;
    std::regex pattern("[1-100]+"); // regex expression that will only accept numbers 1 through 100
    Display_List(repo);
    std::cout << "Select the Transformer you wish to delete\n";
    std::cin >> input;

    if (!std::regex_match(input, pattern))
    {
        std::cout << "Wrong\n";
        return;
    }
    repo.remove(atoi(input.c_str()) - 1);

    std::cout << "Transformer removed successfully!\n";
}

void Simulate_Battle(Transformer_Repository& repo, BattleSimulator& simulator)
{
    std::string input;
    std::regex pattern("[1-100]+"); // regex expression that will only accept numbers 1 through 100
    Display_List(repo);
    std::cout << "Select Combantant #1\n";
    std::cin >> input;

    if (!std::regex_match(input, pattern))
    {
        std::cout << "Wrong\n";
        return;
    }
    Transformer* t1 = repo.get(atoi(input.c_str()) - 1);

    std::cout << "Select Combantant #2\n";
    std::cin >> input;

    if (!std::regex_match(input, pattern))
    {
        std::cout << "Wrong\n";
        return;
    }
    Transformer* t2 = repo.get(atoi(input.c_str()) - 1);

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
    Display_List(repo);

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