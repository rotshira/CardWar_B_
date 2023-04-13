#include "player.hpp"
using namespace std;


using namespace ariel;
Player::Player() {
    
	this->cards_taken = 0;
	this->win_count = 0;
	this->game_count = 0;
}

Player::Player(std::string name) {
	this->name = name;
	this->cards_taken = 0;
	this->win_count = 0;
	this->game_count = 0;
}

void Player::addCard(Card card) {
	this->cards.push_back(card);
}

void Player::addCards(std::vector<Card> new_cards) {
	for (Card card : new_cards) {
		this->cards.push_back(card);
	}
}

Card Player::drawCard() {
	Card top_card = this->cards.back();
	this->cards.pop_back();
	this->cards_taken++;
	return top_card;
}

std::string Player::getName() {
	return this->name;
}

int Player::stacksize() {
	return this->cards.size();
}

int Player::cardesTaken() {
	return this->cards_taken;
}

int Player::getWinCount() {
	return this->win_count;
}

int Player::getGameCount() {
	return this->game_count;
}

int Player::getCardCount() {
	int total_cards = this->cards_taken +this->stacksize();
	return total_cards;
}