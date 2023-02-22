#include "headers.h"

int main()
{
	intro();
	story();
	int stage = 0;
	while (stage != 4)
	{
		if (stage == 0)
		{

			RPS rps = RPS();
			rps.beforeRPS();
			rps.rps_game_start();
			stage += 1;
		}
		else if (stage == 1)
		{
			Hangman hangman = Hangman();
			hangman.start_Hangman();
			stage += 1;
		}
		else if (stage == 2)
		{
			Bank_Atm bank = Bank_Atm();
			bank.pin_checking();
			bank.show_atm_option();
			stage += 1;
		}
		else if (stage == 3)
		{
			Tictactoc ttt = Tictactoc();
			ttt.start_game();
			stage += 1;
		}
	}
	system("pause");

}