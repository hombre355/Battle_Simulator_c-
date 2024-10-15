#include <iostream>
#include <regex>
#include "ThunderCats_Main_Loop.h"


void ThunderCats_Main_Loop::Display_List(ThunderCats_Repository& repo)
{
    printf("%-10s%-25s%-20s%-20s%-10s%-10s%-10s\n", "Index", "Name", "Faction", "Weapon", "Strength", "Wins", "Losses");

    std::vector<ThunderCats> t = repo.getAll();
    int index = 1;
    for (auto& it : t)
    {
        printf("%-10d%-25s%-20s%-20s%-10d%-10d%-10d\n", index,
            it.getName().c_str(),
            it.getFaction().c_str(),
            it.getWeapon().c_str(),
            it.getStrength(),
            it.getWins(),
            it.getLosses());
        index++;
    }
}

void ThunderCats_Main_Loop::Display_Menu()
{
    std::cout << "\nEnter a number between 1 through 5 and then press Enter\n";
    std::cout << "1. Add ThunderCats\n";
    std::cout << "2. Remove ThunderCats\n";
    std::cout << "3. Simulate Battle\n";
    std::cout << "4. View ThunderCats Info\n";
    std::cout << "5. Exit\n";
}

void ThunderCats_Main_Loop::Add_ThunderCats(ThunderCats_Repository& repo)
{

    std::string name, faction, weapon;
    int strength;
    std::cout << "Enter ThunderCats name: ";
    std::getline(std::cin, name);
    std::cout << "Enter faction: ";
    std::getline(std::cin, faction);
    std::cout << "Enter weapon: ";
    std::getline(std::cin, weapon);
    std::cout << "Enter strength: ";
    std::cin >> strength;
    

    int ret = repo.add(ThunderCats(name, faction, strength, weapon));
    if (ret != 0)
    {
        std::cout << "That ThunderCat has already been added.\n";
        return;
    }
    std::cout << "ThunderCat added successfully!\n";
}

void ThunderCats_Main_Loop::Remove_ThunderCats(ThunderCats_Repository& repo)
{
    std::vector<ThunderCats> t = repo.getAll();
    int num_of_elements = t.size();
    if (num_of_elements == 0)
    {
        std::cout << "There are no ThunderCat to delete\n";
        std::cout << "Please add some and then try again\n\n";
        return;
    }
    std::string input;
    std::regex pattern("^(100|[1-9]?[0-9])$"); // regex expression that will only accept numbers 1 through 100
    ThunderCats_Main_Loop::Display_List(repo);

    std::cout << "Select the ThunderCat you wish to delete\n";
    std::cin >> input;

    if (std::regex_match(input, pattern) && (atoi(input.c_str())) > 0 && (atoi(input.c_str()) <= num_of_elements))
    {
        repo.remove(atoi(input.c_str()) - 1);
        std::cout << "ThunderCat removed successfully!\n";
        return;
    }
    std::cout << "Error while trying to remove ThunderCat\n";
    std::cout << "Please make sure you are choosing the correct index.\n\n";

}

void ThunderCats_Main_Loop::Simulate_Battle(ThunderCats_Repository& repo, ThunderCats_Battle_Sim& simulator)
{
    int com1 = -1;
    int com2 = -1;
    std::vector<ThunderCats> t = repo.getAll();
    int num_of_elements = t.size();
    if (num_of_elements <= 1)
    {
        std::cout << "There are not enough ThunderCat to Battle\n";
        std::cout << "Please add at least two and then try again\n\n";
        return;
    }
    std::string input;
    std::regex pattern("^(100|[1-9]?[0-9])$"); // regex expression that will only accept numbers 1 through 100
    Display_List(repo);
    std::cout << "Select Combantant #1\n";
    std::cin >> input;

    if (!std::regex_match(input, pattern) || (atoi(input.c_str())) <= 0 || (atoi(input.c_str()) > num_of_elements))
    {
        std::cout << "Input was not correct. Please try again.\n";
        return;
    }
    com1 = atoi(input.c_str()) - 1;
    ThunderCats* t1 = repo.get(com1);

    std::cout << "Select Combantant #2\n";
    std::cin >> input;

    if (!std::regex_match(input, pattern) || (atoi(input.c_str())) <= 0 || (atoi(input.c_str()) > num_of_elements))
    {
        std::cout << "Input was not correct. Please try again.\n";
        return;
    }
    com2 = atoi(input.c_str()) - 1;
    while (com2 == com1)
    {
        std::cout << "You choose the same combatant.\n";
        std::cout << "Please choose a different fighter.\n\n";

        std::cout << "Select Combantant #2\n";
        std::cin >> input;

        if (!std::regex_match(input, pattern) && (atoi(input.c_str())) > 0 && (atoi(input.c_str()) <= num_of_elements))
        {
            std::cout << "Input was not correct. Please try again.\n";
            return;
        }
        com2 = atoi(input.c_str()) - 1;

    }
    ThunderCats* t2 = repo.get(atoi(input.c_str()) - 1);

    if (t1 && t2)
    {
        std::cout << simulator.battle(*t1, *t2) << "\n";
        return;
    }
    std::cout << "One or both ThunderCat not found.\n";
}

void ThunderCats_Main_Loop::View_ThunderCats_Info(ThunderCats_Repository& repo)
{
    std::vector<ThunderCats> t = repo.getAll();
    int num_of_elements = t.size();
    if (num_of_elements == 0)
    {
        std::cout << "There are no ThunderCat to display\n";
        std::cout << "Please add some and then try again\n\n";
        return;
    }
    Display_List(repo);

}

int ThunderCats_Main_Loop::Game_Loop()
{
    ThunderCats_Repository repo;
    ThunderCats_Battle_Sim simulator;
    ThunderCats_Main_Loop loop;
    std::string input;
    std::regex pattern("[1-5]+"); // regex expression that will only accept numbers 1 through 5
    int choice = 0;

    while (true)
    {
        Display_Menu();
        std::cin >> input;
        std::cin.ignore(1, '\n');

        if (std::regex_match(input, pattern))
        {
            choice = atoi(input.c_str());
        }
        else
        {
            std::cout << "Please choose again!\n";
            continue;
        }

        switch (choice)
        {
        case 1:
            std::cout << "\n";
            Add_ThunderCats(repo);
            break;
        case 2:
            std::cout << "\n";
            Remove_ThunderCats(repo);
            break;
        case 3:
            std::cout << "\n";
            Simulate_Battle(repo, simulator);
            break;
        case 4:
            std::cout << "\n";
            View_ThunderCats_Info(repo);
            break;
        case 5:
            return 0;
        default:
            std::cout << "Invalid choice! Please choose a number from 1 to 5.\n";
        }
    }

    return 0;
}
