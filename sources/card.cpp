#include "card.hpp"
#include <string>

// Constructor
Card::Card(int rank, int suit) {
	this->rank = rank;
	this->suit = suit;
}

// Return a string representation of the card
std::string Card::toString() 
{
	std::string rank_str;
	switch (rank) {
	case 1:
		rank_str = "Ace";
		break;
	case 11:
		rank_str = "Jack";
		break;
	case 12:
		rank_str = "Queen";
		break;
	case 13:
		rank_str = "King";
		break;
	default:
		rank_str = std::to_string(rank);
		break;
	}


	std::string suit_str;
	switch (suit) {
	case 0:
		suit_str = "Clubs";
		break;
	case 1:
		suit_str = "Diamonds";
		break;
	case 2:
		suit_str = "Hearts";
		break;
	case 3:
		suit_str = "Spades";
		break;
	}

	return rank_str + " of " + suit_str;


}

// Return the rank of the card
int Card::getRank() {
	return rank;
}

// Return the suit of the card
int Card::getSuit() {
	return suit;
}