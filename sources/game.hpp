#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "Card.hpp"
#include "player.hpp"

class Game
{
private:
	ariel::Player player1;
	ariel::Player player2;
	std::vector<Card> pot;
	std::vector<std::string> log;
	bool gameOver;

public:
	Game();
    Game(ariel::Player p1, ariel::Player p2);
	void shuffleDeck(std::vector<Card>& deck);
	void dealCards(std::vector<Card>& deck);
	void playTurn();
	void playAll(); //playes the game untill the end
	void printLastTurn();// print the last turn stats. For example:
						// Alice played Queen of Hearts Bob played 5 of Spades. Alice wins.
	void printWiner();// prints the name of the winning player
	void printLog();// prints all the turns played one line per turn (same format as game.printLastTurn())
	void printStats();// for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )
};