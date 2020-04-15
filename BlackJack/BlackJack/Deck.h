#pragma once
#include "Card.h"
#include <vector>

const int DECKSIZE = 52; 

class Deck
{
public:
	Deck();
	~Deck();
	void showDeck();

	void shuffle(); 

	void dealPlayer();
	void dealHouse(); 

	int getHandValue(std::vector<Card*> a_deck);

	void showHands(); 

	void checkPlayer();
	void checkHouse(); 

	void clearScreen(); 

	void gameLoop(); 



private:
	std::vector<Card*> deck; 
	std::vector<Card*> discardPile;
	std::vector<Card*> playersHand;
	std::vector<Card*> houseHand; 

	std::vector<int> order;

	bool playerDone;
	bool houseDone;
	bool gameOver; 
	bool playerWins; 

	char playerInput; 

	int roundCounter; 
};

