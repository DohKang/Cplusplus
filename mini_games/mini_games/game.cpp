#include "headers.h"

void intro()
{
	cout << "Welcome to Dohyun's mini games wrold.\n" << endl;
	cout << "Today you will play\n" << endl;
	cout << "<< Rock, Paper, Scissors >>" << endl;
	cout << "<< Hangman >> " << endl;
	cout << "<< Bank transaction >>" << endl;
	cout << "<< Tic Tac Toc >> \n" << endl;
	cout << " Thank you -DK-\n\n";
	system("pause");
}

void story()
{
	cout << "\n\nOnce upon a time, dragons were attacking the world" << endl;
	cout << "Player: Dear King, I will kill dragons. After all, give me your daughter." << endl;
	cout << "King: Of course. Please go ahead and slay dragons.\n" << endl;
	system("pause");

}


//RPS
RPS::RPS()
{
	player_win = 0;
	dragon_win = 0;
	option = { "ROCK", "PAPER", "SCISSORS" };
}
void RPS::beforeRPS()
{
	cout << "\nPlayer went to the kids island and meet the RPS dragon." << endl;
	cout << "Player: Hey, RPS. I challenge you." << endl;
	cout << "Dragon: Ha. I accept that challenge." << endl;
	cout << "Dragon: Whoever wins rock, paper, scissors two times first, win the game.\n" << endl;
	system("pause");

	cout << "**********************************************" << endl;
	cout << "**********************************************" << endl;
	cout << "**********************************************" << endl;
}
void RPS::rps_game_start()
{
	bool running = true;
	while (running)
	{
		int answer;
		do {
			player_pick();
			dragon_pick();
			judge_RPS_Winner();
		} while (dragon_win < 2 && player_win < 2);
		if (player_win == 2)
		{
			cout << "Congratulation. Player win against RPS dragon.\n" << endl;
			cout << "Player: Take my sword!" << endl;
			cout << "The player killed the RPS dragon.\n" << endl;
			system("pause");
			cout << "\n" << endl;
			running = false;
			break;
		}
		else
		{
			cout << "Dragon won the game.\n\n" << endl;
			cout << "Would you like to play again?\n" << endl;
			cout << "Press 1. continue 2. exit" << endl;
			cin >> answer;
			switch (answer)
			{
			case 1:
				player_win = 0;
				dragon_win = 0;
				break;
			case 2:
				running = false;
				exit(0);
				break;
			default:
				cout << "Not a valid option.\n" << endl;
			}
		}
	}
}
void RPS::judge_RPS_Winner()
{
	if (player_choice == dragon_choice)
	{
		cout << "It's a tie\n" << endl;
	}
	else if ((player_choice == "ROCK" && dragon_choice == "SCISSORS")
		|| (player_choice == "SCISSORS" && dragon_choice == "PAPER")
		|| (player_choice == "PAPER" && dragon_choice == "ROCK"))
	{
		cout << "Player wins! Player gets 1 point!" << endl;
		player_win++;
		cout << "Current player's point is :" << player_win << " points\n" << endl;
	}
	else
	{
		cout << "Player Lost! Dragon gets 1 point!" << endl;
		dragon_win++;
		cout << "Current dragon's point is :" << dragon_win << " points\n" << endl;
	}

}
void RPS::player_pick()
{
	while (true)
	{
		cout << "\nPlease pick your choice" << endl;
		cout << "<< ";
		for (int i = 0; i < option.size(); i++)
		{
			cout << option[i] << ", ";
		}
		cout << ">>" << endl;
		cout << "Player's choice: ";
		cin >> player_choice;
		transform(player_choice.begin(), player_choice.end(), player_choice.begin(), ::toupper);
		if (find(option.begin(), option.end(), player_choice) == option.end())
		{
			cout << "Please check your typo.\n" << endl;
			continue;

		}
		else
		{
			break;
		}

	}
}
void RPS::dragon_pick()
{
	srand((unsigned)time(NULL));
	dragon_choice = option[rand() % 3];
	cout << "Dragon picked: " << dragon_choice << "\n" << endl;
}


//Hangman
Hangman::Hangman()
{
	beforeHangman();
	life = 20;
	word = shuffle_word();
	for (int i = 0; i < word.length(); i++)
	{
		player_word += "_";
	}

	for (int i = 0; i < word.length(); i++)
	{
		if (!isalpha(word.at(i)))
		{
			player_word[i] = word.at(i);
		}
	}
	cout << "\n\nToday's word is " << player_word << " !\n" << endl;
}

void Hangman::beforeHangman()
{
	cout << "\nAfter RPS dragons death, the player went to the dead castle." << endl;
	cout << "Dragon: I heard that you killed the RPS dragon." << endl;
	cout << "Dragon: Now, you are dead!" << endl;
	cout << "Player: I challenge you." << endl;
	cout << "Dragon: Guess my word or I hang you.\n" << endl;
	system("pause");

	cout << "**********************************************" << endl;
	cout << "**********************************************" << endl;
	cout << "**********************************************" << endl;
}
void Hangman::start_Hangman()
{
	bool running = true;
	while (running)
	{
		correct_letter = false;
		check_used_letter = true;
		cout << "You have " << life << " chances left." << endl;
		cout << "\n\n" << player_word << "\n\n" << endl;
		cout << "Please guess a letter " << endl;
		cin >> player_guess;
		player_guess = toupper(player_guess);

		if (!isalpha(player_guess))
		{
			cout << "Please type a character\n" << endl;
			continue;
		}
		for (int i = 0; i < word.length(); i++)
		{
			if (player_guess == word[i])
			{
				player_word[i] = word[i];
				correct_letter = true;
			}

		}
		if (!correct_letter)
		{
			check_used_letter = false;
			if (find(used_letter.cbegin(), used_letter.cend(), player_guess) != used_letter.cend())
			{
				cout << "You already tried this letter\n" << endl;
				check_used_letter = true;
			}

		}
		if (!check_used_letter)
		{
			used_letter.push_back(player_guess);
			life--;
		}

		check_Hangman(&life);

		cout << "\n" << endl;
		cout << "Letters you tried: ";
		for (int i = 0; i < used_letter.size(); i++)
		{
			cout << used_letter[i] << ",";
		}
		cout << "\n" << endl;
		for (int i = 0; i < word.size(); i++)
		{
			if (player_word[i] == '_')
			{
				game_result = false;
				break;
			}
			else
			{
				game_result = true;
			}
		}
		if (game_result)
		{
			cout << "Congratulation. Player win the hangman game!\n" << endl;
			cout << "Player: Take my sword!" << endl;
			cout << "The player killed the Hangman dragon\n" << endl;
			system("pause");
			cout << "\n" << endl;
			running = false;
			break;
		}
		if (life < 1)
		{
			cout << "No more chacne, the word was " << word << "!\n" << endl;
			break;
		}
	}
}
string Hangman::shuffle_word()
{
	srand((unsigned)time(NULL));
	string word;
	word = wine[rand() % 13];
	transform(word.begin(), word.end(), word.begin(), ::toupper);
	return word;
}
void Hangman::check_Hangman(int* Available_times)
{
	if (*Available_times < 1)
	{

		cout << "_________" << endl;
		cout << "|	 |" << endl;
		cout << "|	 O" << endl;
		cout << "|       \\|/" << endl;
		cout << "|	 |" << endl;
		cout << "|	/ \\ " << endl;
		cout << "|________" << endl;
	}
	else if (*Available_times < 5)
	{
		cout << "_________" << endl;
		cout << "|	 |" << endl;
		cout << "|	 O" << endl;
		cout << "|       \\|/" << endl;
		cout << "|	 |" << endl;
		cout << "|	/ " << endl;
		cout << "|________" << endl;
	}
	else if (*Available_times < 10)
	{
		cout << "_________" << endl;
		cout << "|	 |" << endl;
		cout << "|	 O" << endl;
		cout << "|       \\|/" << endl;
		cout << "|	 |" << endl;
		cout << "|" << endl;
		cout << "|________" << endl;
	}
	else if (*Available_times < 13)
	{

		cout << "_________" << endl;
		cout << "|	 |" << endl;
		cout << "|	 O" << endl;
		cout << "|       \\|" << endl;
		cout << "|	 |" << endl;
		cout << "|" << endl;
		cout << "|________" << endl;
	}
	else if (*Available_times < 16)
	{
		cout << "_________" << endl;
		cout << "|	 |" << endl;
		cout << "|	 O" << endl;
		cout << "|	 |" << endl;
		cout << "|	 |" << endl;
		cout << "|" << endl;
		cout << "|________" << endl;
	}
	else if (*Available_times < 18)
	{
		cout << "_________" << endl;
		cout << "|	 |" << endl;
		cout << "|	 O" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|________" << endl;
	}
	else if (*Available_times < 21)
	{
		cout << "_________" << endl;
		cout << "|	 |" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|________" << endl;
	}

}


//bank
Bank_Atm::Bank_Atm()
{
	beforeBank_Atm();
	balance = 900;
	cash_in_hand = 123;
	possessed_crypto = 40;
	value_crypto = 0;
}
void Bank_Atm::beforeBank_Atm()
{
	cout << "Now, the player went to walmarc to meet the begging dragon." << endl;
	cout << "Dragon: Hey, I am a really good dragon, and I don't kill people." << endl;
	cout << "Dragon: Can you give me $1200 so that I can start my new life?" << endl;
	cout << "Player: Sure. wait here, I will stop by the dragon_atm machine over there.\n" << endl;
	system("pause");

}
void Bank_Atm::pin_checking()
{
	int user_pin;
	int pin = 1234;
	do
	{

		int remember = 0;
		cout << "Do you know your bank pin number?\n" << endl;
		cout << "1. Yes, 2. No\n";
		cin >> remember;
		cin.clear();
		switch (remember)
		{
		case 1:
			cout << "Great!\n" << endl;
			break;
		case 2:
			cout << "Your pin number is " << "1234\n" << endl;
			break;
		default:
			cout << "Invalid option\n";
		}
		cout << "Please press your pin number.\n" << endl;
		cin >> user_pin;
		cin.clear();


	} while (user_pin != pin);


}
void Bank_Atm::show_atm_option()
{
	int choice;
	bool enough_meney = false;
	do
	{
		atm_main_menu();
		cout << "-----------------------------------------" << endl;
		cout << "| 1.   Deposit       | 2.   Withdraw     |" << endl;
		cout << "------------------------------------------" << endl;
		cout << "| 3.   Balance       | 4.   Transfer     |" << endl;
		cout << "------------------------------------------" << endl;
		cout << "| 5.   Sell Crypto   | 6.   Log out      |" << endl;
		cout << "------------------------------------------" << endl;

		cout << "\n\n";
		cout << "Welcome back, mr..\n";
		cout << "Please enter a numumber for service :";
		cin >> choice;
		cin.clear();
		switch (choice)
		{
		case 1:
			deposit();
			break;
		case 2:
			withdraw();
			break;
		case 3:
			check_balance();
			break;
		case 4:
			transfer();
			break;
		case 5:
			sell_crypto();
			break;
		case 6:
			if (cash_in_hand > 1200)
			{
				enough_meney = true;
				cout << "Thank you for using our dragon bank atm machine\n\n" << endl;
				cout << "Player:Here is the money" << endl;
				cout << "Dragon: Thank you so much ^^." << endl;
				cout << "The begging dragon disappered.\n" << endl;
				system("pause");

			}
			else
			{
				cout << "You need to withdraw more money." << endl;
				cout << "Please withdraw more money or sell your dragon coins.\n" << endl;
			}
			break;
		default:
			cout << "Invalid option\n";
			break;
		}
	} while (!enough_meney);
}
void Bank_Atm::deposit()
{
	double input;
	cout << "How much do you want to deposit today?\n";
	cin >> input;
	if (input > cash_in_hand)
	{
		cout << "Sorry, you don't have enough cash" << endl;
	}
	else
	{
		cout << "Beep Beep Beep" << endl;
		balance += input;
		cash_in_hand -= input;
		cout << "Successfully deposited $" << input << "." << endl;
		cout << "Your remaining balance is $" << setprecision(2) << fixed << balance << "\n";


	}
}

void Bank_Atm::withdraw()
{
	double input;
	std::cout << "How much do you want to withdraw today?\n";
	std::cin >> input;
	cin.clear();

	if (input - balance > 0)
	{
		cout << "Sorry, you don't have enough money in the account." << endl;

	}
	else if (balance - input >= 0)
	{
		balance -= input;
		cash_in_hand += input;
		cout << "After your withdaw of" << input << endl;
		cout << "Your remaining balance is $" << setprecision(2) << fixed << balance << "\n";
	}
	else
	{
		cout << "invalid option. Please check your balance.";
	}
}
void Bank_Atm::check_balance()
{
	cout << "Your remaining balance is $" << ::setprecision(2) << fixed << balance << "\n";
}

void Bank_Atm::transfer()
{
	cout << "Please use your zelle service with your dragon bank app";
}

void Bank_Atm::sell_crypto()
{
	int input;
	srand(unsigned(time(NULL)));
	value_crypto = (rand() % 10) + 24;
	cout << "Currently dragon coins are traded at $" << value_crypto << " per coin\n";
	cout << "You have " << possessed_crypto << " dragon coins" << endl;
	cout << "How many dragon coins would you like to sell?\n" << endl;
	cin >> input;
	cin.clear();
	if (input - possessed_crypto > 0)
	{
		cout << "Sorry, you don't have enough dragon coins." << endl;

	}
	else if (possessed_crypto - input >= 0)
	{
		possessed_crypto -= input;
		balance += input * value_crypto;
		cout << "Perfect! You sell " << input << " dragon coins" << endl;
		cout << "Your remaining dragon coin is " << possessed_crypto << " coins\n";
	}
	else
	{
		cout << "invalid option. Please check your coins.";
	}
}

void Bank_Atm::atm_main_menu()
{
	cout << "******************************************\n";
	cout << "\n *** main menu ***\n" << endl;
	cout << "!SELL YOUR DRAGON COIN!" << endl;
	cout << "Welcome to dragon bank" << "\n" << endl;
	cout << "You have $" << cash_in_hand << " in your pocket." << endl;
	cout << "You have $" << balance << " in your bank.\n" << endl;
}


//Tic tac toc
Tictactoc::Tictactoc()
{
	beforeTictactic();
}
void Tictactoc::beforeTictactic()
{
	cout << "\nFinally, the player went to the toctoc island." << endl;
	cout << "Knock knock! " << endl;
	cout << "Dragon: Who dare to knock my island!" << endl;
	cout << "Player: I challenge you!" << endl;
	cout << "Dragon: Let's Tic Tac Toc!\n" << endl;
	system("pause");
}
void Tictactoc::start_game()
{
	drawmaps(maps);
	while (true)
	{
		playerMove(maps, player);
		drawmaps(maps);
		if (checkWinner(maps, player, dragon))
		{
			break;
		}
		else if (checkTie(maps))
		{
			break;
		}
		dragonMove(maps, dragon);
		drawmaps(maps);
		if (checkWinner(maps, player, dragon))
		{
			break;
		}
		else if (checkTie(maps))
		{
			break;
		}

	}
	cout << "\n\nAfter long fight between the dragon and the player..." << endl;
	cout << "Dragon and the player eventually become friends" << endl;
	cout << "The player and the dragon were happy forever.\n\n" << endl;
	cout << "The end\n\n" << endl;
	cout << "*************Thank you for playing  *************" << endl;
}
void Tictactoc::drawmaps(char* maps)
{
	std::cout << "\n";
	std::cout << "     |     |     "
		<< "\n";
	std::cout << "  " << maps[0] << "  |  " << maps[1] << "  |  " << maps[2] << "  "
		<< "\n";
	std::cout << "_____|_____|_____"
		<< "\n";
	std::cout << "     |     |     "
		<< "\n";
	std::cout << "  " << maps[3] << "  |  " << maps[4] << "  |  " << maps[5] << "  "
		<< "\n";
	std::cout << "_____|_____|_____"
		<< "\n";
	std::cout << "     |     |     "
		<< "\n";
	std::cout << "  " << maps[6] << "  |  " << maps[7] << "  |  " << maps[8] << "  "
		<< "\n";
	std::cout << "\n";
}
void Tictactoc::playerMove(char* maps, const char player)
{
	int player_choice;
	do
	{
		std::cout << "Enter a spot to place a marker(1-9): ";
		std::cin >> player_choice;
		player_choice--;
		if (maps[player_choice] == ' ')
		{
			maps[player_choice] = player;
			break;
		}

	} while (~player_choice > 0 || ~player_choice < 8);


}
void Tictactoc::dragonMove(char* maps, const char dragon)
{
	int number;
	srand((unsigned)time(NULL));
	while (true)
	{
		number = rand() % 9; // 0~8
		if (maps[number] == ' ')
		{
			maps[number] = dragon;
			break;
		}
	}
}
bool Tictactoc::checkWinner(char* maps, char player, char dragon)
{
	if ((maps[0] != ' ') && (maps[0] == maps[1]) && (maps[1] == maps[2]))
	{
		maps[0] == player ? std::cout << "Player win!\n" : std::cout << "Dragon win!\n";
	}
	else if ((maps[3] != ' ') && (maps[3] == maps[4]) && (maps[4] == maps[5]))
	{
		maps[3] == player ? std::cout << "Player win!\n" : std::cout << "Dragon win!\n";
	}
	else if ((maps[6] != ' ') && (maps[6] == maps[7]) && (maps[7] == maps[8]))
	{
		maps[6] == player ? std::cout << "Player win!\n" : std::cout << "Dragon win!\n";
	}
	else if ((maps[0] != ' ') && (maps[0] == maps[3]) && (maps[3] == maps[6]))
	{
		maps[0] == player ? std::cout << "Player win!\n" : std::cout << "Dragon win!\n";
	}
	else if ((maps[1] != ' ') && (maps[1] == maps[4]) && (maps[4] == maps[7]))
	{
		maps[1] == player ? std::cout << "Player win!\n" : std::cout << "Dragon win!\n";
	}
	else if ((maps[2] != ' ') && (maps[2] == maps[5]) && (maps[5] == maps[8]))
	{
		maps[2] == player ? std::cout << "Player win!\n" : std::cout << "Dragon win!\n";
	}
	else if ((maps[0] != ' ') && (maps[0] == maps[4]) && (maps[4] == maps[8]))
	{
		maps[0] == player ? std::cout << "Player win!\n" : std::cout << "Dragon win!\n";
	}
	else if ((maps[2] != ' ') && (maps[2] == maps[4]) && (maps[4] == maps[6]))
	{
		maps[2] == player ? std::cout << "Player win!\n" : std::cout << "Dragon win!\n";
	}
	else
	{
		return false;
	}

	return true;
}
bool Tictactoc::checkTie(char* maps)
{
	for (int i = 0; i < 9; i++)
	{
		if (maps[i] == ' ')
		{
			return false;
		}
	}
	std::cout << "It's a TIE!\n";
	return true;
}


