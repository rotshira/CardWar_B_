#include <iostream>
#include <vector>
#include "Card.hpp"
#include <algorithm>
#include "Game.hpp"



Game::Game() {
    // initialize players
    player1 = ariel::Player("Alice");
    player2 = ariel::Player("Bob");
    gameOver = false;
}

Game::Game(ariel::Player p1, ariel::Player p2) {
    // initialize players
    player1 = p1;
    player2 = p2;
    gameOver = false;
}

void Game::shuffleDeck(std::vector<Card>& deck) {
    srand(time(NULL));
    std::random_shuffle(deck.begin(), deck.end());
}

void Game::dealCards(std::vector<Card>& deck) {
    // deal cards evenly to both players
    for (int i = 0; i < deck.size(); i++) {
        if (i % 2 == 0) {
            player1.addCard(deck.front());
            deck.erase(deck.begin());
        }
        else {
            player2.addCard(deck.front());
            deck.erase(deck.begin());
        }
    }
}

void Game::playTurn() {
    // check if game is over
    if (player1.stacksize() == 0 || player2.stacksize() == 0) {
        gameOver = true;
        return;
    }

    // each player plays a card
    Card card1 = player1.drawCard();
    Card card2 = player2.drawCard();

    // add cards to pot
    pot.push_back(card1);
    pot.push_back(card2);

    // print the cards played
    std::cout << player1.getName() << " played " << card1.toString() << ". " << player2.getName() << " played " << card2.toString() << "." << std::endl;

    // compare cards
    if (card1.getRank() > card2.getRank()) {
        // player 1 wins
        std::cout << player1.getName() << " wins." << std::endl;
        player1.addCards(pot);
        pot.clear();
    }
    else if (card2.getRank() > card1.getRank()) {
        // player 2 wins
        std::cout << player2.getName() << " wins." << std::endl;
        player2.addCards(pot);
        pot.clear();
    }
    else {
        // war!
        std::cout << "War!" << std::endl;
        // each player plays 3 cards face down and 1 card face up
        for (int i = 0; i < 3; i++) {
            pot.push_back(player1.drawCard());
            pot.push_back(player2.drawCard());
        }
        Card card1 = player1.drawCard();
        Card card2 = player2.drawCard();
        // add cards to pot
        pot.push_back(card1);
        pot.push_back(card2);
        // print the cards played
        std::cout << player1.getName() << " played " << card1.toString() << ". " << player2.getName() << " played " << card2.toString() << "." << std::endl;
        // compare cards again
        if (card1.getRank() > card2.getRank()) {
            // player 1 wins the war
            std::cout << player1.getName() << " wins." << std::endl;
            player1.addCards(pot);
            pot.clear();
        }
        else {
            // player 2 wins the war
            std::cout << player2.getName() << " wins." << std::endl;
            player2.addCards(pot);
            pot.clear();
        }
    }
}

void Game::playAll() {
    while (!gameOver) {
        playTurn();
    }
    printWiner();
}

void Game::printLastTurn() {
    // check if there is a last turn to print
    if (log.empty()) {
        std::cout << "No turns played yet." << std::endl;
        return;
    }

    // get the last turn played
    std::string lastTurn = log.back();
    std::cout << lastTurn << std::endl;
}

void Game::printWiner() {
    // check if game is over
    if (!gameOver) {
        std::cout << "Game is not over yet." << std::endl;
        return;
    }

    // get the player with the most cards
    if (player1.stacksize() > player2.stacksize()) {
        std::cout << player1.getName() << " wins!" << std::endl;
    }
    else if (player2.stacksize() > player1.stacksize()) {
        std::cout << player2.getName() << " wins!" << std::endl;
    }
    else {
        std::cout << "It's a draw!" << std::endl;
    }
}

void Game::printLog() {
    // check if there are turns played
    if (log.empty()) {
        std::cout << "No turns played yet." << std::endl;
        return;
    }

    // print each turn played
    for (std::string turn : log) {
        std::cout << turn << std::endl;
    }
}



void Game::printStats()
{
    // calculate win rate for each player
    float player1WinRate = (float)player1.getWinCount() / (float)player1.getGameCount();
    float player2WinRate = (float)player2.getWinCount() / (float)player2.getGameCount();

    // calculate draw rate and amount of draws
    int totalGames = player1.getGameCount() + player2.getGameCount();
    int totalDraws = totalGames - player1.getWinCount() - player2.getWinCount();
    float drawRate = (float)totalDraws / (float)totalGames;

    // print player 1 stats
    std::cout << player1.getName() << " stats:" << std::endl;
    std::cout << "Win rate: " << player1WinRate << std::endl;
    std::cout << "Cards won: " << player1.getCardCount() << std::endl;
    // <other stats you want to print>
    std::cout << std::endl;

    // print player 2 stats
    std::cout << player2.getName() << " stats:" << std::endl;
    std::cout << "Win rate: " << player2WinRate << std::endl;
    std::cout << "Cards won: " << player2.getCardCount() << std::endl;
    // <other stats you want to print>
    std::cout << std::endl;
}
   

    