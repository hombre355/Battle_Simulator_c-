#ifndef THUNDERCATS_MAIN_LOOP_H
#define THUNDERCATS_MAIN_LOOP_H

#include "ThunderCats_Repo.h"
#include "ThunderCats_Battle_Sim.h"

class ThunderCats_Main_Loop
{
private:
	void Display_List(ThunderCats_Repository& repo);
	void Display_Menu();
	void Add_ThunderCats(ThunderCats_Repository& repo);
	void Remove_ThunderCats(ThunderCats_Repository& repo);
	void Simulate_Battle(ThunderCats_Repository& repo, ThunderCats_Battle_Sim& simulator);
	void View_ThunderCats_Info(ThunderCats_Repository& repo);

public:
	ThunderCats_Main_Loop() {};
	int Game_Loop();
};

#endif //TRANSFORMER_MAIN_LOOP_H




