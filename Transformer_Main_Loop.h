#ifndef TRANSFORMER_MAIN_LOOP_H
#define TRANSFORMER_MAIN_LOOP_H

#include "Transformer_Repo.h"
#include "Transformer_Battle_Sim.h"

class Transformer_Main_Loop
{
private:
	void Display_List(Transformer_Repository& repo);
	void Display_Menu();
	void Add_Transformer(Transformer_Repository& repo);
	void Remove_Transformer(Transformer_Repository& repo);
	void Simulate_Battle(Transformer_Repository& repo, Transformer_Battle_Sim& simulator);
	void View_Transformer_Info(Transformer_Repository& repo);

public:
	Transformer_Main_Loop() {};
	int Game_Loop();
};
#endif //TRANSFORMER_MAIN_LOOP_H

