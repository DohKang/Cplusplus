#ifndef HEADERS_H
#define HEADERS_H

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <algorithm>
#include <stdlib.h>
#include <cctype>
#include <vector>
using namespace std;


void intro();
void story();
// Rock, Paper, Scissors

class RPS
{
private:
	int player_win;
	int dragon_win;
	string player_choice;
	string dragon_choice;
	vector<string> option;
public:
	RPS();
	void beforeRPS();
	void player_pick();
	void dragon_pick();
	void judge_RPS_Winner();
	void rps_game_start();
};

// Hangman
class Hangman
{
private:
	int life;
	string question_word;
	string player_word;
	vector<char> used_letter;
	string word;
	string wine[13] = { "Merlot", "Syrah", "Cabernet franc", "Bordeaux", "Burgundy", "Marlborough",
			"Zinfandel", "Tempranillo", "Garnacha", "Pinot Noir", "Gamay", "Pinotage", "Petit verdot" };
	char player_guess;
	bool game_result;
	bool check_used_letter;
	bool correct_letter;
public:
	Hangman();
	void beforeHangman();
	string shuffle_word();
	void check_Hangman(int* Available_times);
	void start_Hangman();



};

//Bank
class Bank_Atm
{
private:
	double balance;
	int possessed_crypto;
	int value_crypto;
	double cash_in_hand;

public:
	Bank_Atm();
	void beforeBank_Atm();
	void pin_checking();
	void show_atm_option();
	void deposit();
	void withdraw();
	void check_balance();
	void transfer();
	void sell_crypto();
	void atm_main_menu();


};

//Tic Tac Toc
class Tictactoc
{
private:
	const char player = 'P';
	const char dragon = 'D';
	char maps[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
public:
	Tictactoc();
	void beforeTictactic();
	void drawmaps(char* spaces);
	void playerMove(char* spaces, char player);
	void dragonMove(char* spaces, char dragon);
	bool checkWinner(char* spaces, char player, char dragon);
	bool checkTie(char* spaces);
	void start_game();

};


#endif