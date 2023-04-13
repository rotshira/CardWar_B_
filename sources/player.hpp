#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include "Card.hpp"
using namespace std;

 namespace ariel
{
// Define a class for a player
class Player {
private:
	std::vector<Card> cards; // Vector of cards
	std::string name; // Player's name
	int cards_taken; // Number of cards taken by the player
	int win_count; // Number of games won by the player
	int game_count; // Number of games played by the player

public:
	Player(); // Default constructor
	Player(std::string name); // Constructor with name
	void addCard(Card card); // Add a card to the player's hand
	void addCards(std::vector<Card> new_cards); // Add multiple cards to the player's hand
	Card drawCard(); // Draw the top card from the player's hand
	std::string getName(); // Return the player's name
	int stacksize(); // Return the number of cards left in the player's hand
	int cardesTaken(); // Return the number of cards taken by the player
	int getWinCount(); // Return the number of games won by the player
	int getGameCount(); // Return the number of games played by the player
	int getCardCount(); // Return the number of cards won by the player
};
}
#endif