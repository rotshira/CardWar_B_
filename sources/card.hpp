#pragma once
#ifndef CARD_H
#define CARD_H

#include <string>

// Define a class for a playing card
class Card {
private:
	int rank; // 1 (Ace) to 13 (King)
	int suit; // 0 (Clubs), 1 (Diamonds), 2 (Hearts), 3 (Spades)

public:
	Card(int rank, int suit); // Constructor
	std::string toString(); // Return a string representation of the card
	int getRank(); // Return the rank of the card
	int getSuit(); // Return the suit of the card
};

#endif