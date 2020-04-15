#include "Deck.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>

Deck::Deck()
{
	roundCounter = 0; 
	playerDone = false; 
	houseDone = false; 
	gameOver = false;
	playerInput = 0; 
	playerWins = false; 

	for (size_t i = 0; i < DECKSIZE; i++)
	{
		order.push_back(i);
	}

	for (size_t i = 0; i < DECKSIZE; i++)
	{
		Card* temp = new Card();
		deck.push_back(temp); 
		if (i <= 12)
		{
			deck[i]->setSuit(Suit::HEARTS);
			deck[i]->setNumber(i + 1); 
		}
		else if (i <= 25)
		{
			deck[i]->setSuit(Suit::CLUBS);
			deck[i]->setNumber(i - 12);
		}
		else if (i <= 38)
		{
			deck[i]->setSuit(Suit::SPADES);
			deck[i]->setNumber(i - 25);
		}
		else if (i <= 51)
		{
			deck[i]->setSuit(Suit::DIAMONDS);
			deck[i]->setNumber(i - 38);
		}

		//Horible switch statement cause I don't get i % 13
		switch (deck[i]->getNumber())
		{
		case 1:
			deck[i]->setValue(11);
			break;
		case 2:
			deck[i]->setValue(2);
			break;
		case 3:
			deck[i]->setValue(3);
			break;
		case 4:
			deck[i]->setValue(4);
			break;
		case 5:
			deck[i]->setValue(5);
			break;
		case 6:
			deck[i]->setValue(6);
			break;
		case 7:
			deck[i]->setValue(7);
			break;
		case 8:
			deck[i]->setValue(8);
			break;
		case 9:
			deck[i]->setValue(9);
			break;
		case 10:
			deck[i]->setValue(10);
			break;
		case 11:
			deck[i]->setValue(10);
			break;
		case 12:
			deck[i]->setValue(10);
			break;
		case 13:
			deck[i]->setValue(10);
			break;
			
		default:
			break;
		}
		
	}
}

Deck::~Deck()
{
	for (size_t i = 0; i < DECKSIZE; i++)
	{
		if (deck[i] != nullptr)
		{
			delete deck[i];
			deck[i] = nullptr;
		}
		if (discardPile[i] != nullptr)
		{
			delete discardPile[i];
			discardPile[i] = nullptr;
		}
		if (playersHand[i] != nullptr)
		{
			delete playersHand[i];
			playersHand[i] = nullptr;
		}
		if (houseHand[i] != nullptr)
		{
			delete houseHand[i];
			houseHand[i] = nullptr;
		}
	}
}

void Deck::showDeck()
{
	for (size_t i = 0; i < deck.size() - 1; i++)
	{
		//std::cout << deck[i]->getSuit() << " " << deck[i]->getNumber() << std::endl;
		switch (deck[i]->getSuit())
		{
		case HEARTS:
			std::cout << deck[i]->getNumber() << " of HEARTS" << std::endl; 
			break;
		case CLUBS:
			std::cout << deck[i]->getNumber() << " of CLUBS" << std::endl;
			break;
		case SPADES:
			std::cout << deck[i]->getNumber() << " of SPADES" << std::endl;
			break;
		case DIAMONDS:
			std::cout << deck[i]->getNumber() << " of DIAMONDS" << std::endl;
			break;
		default:
			break;
		}
	}

	std::cout << deck.size() << std::endl;
	std::cout << "------------------------------------------------------------------------------------------------\n";
}

void Deck::shuffle()
{
	for (size_t i = 0; i < DECKSIZE; i++)
	{
		int second = (rand() + time(0)) % DECKSIZE;
		Card* temp = deck[i];
		deck[i] = deck[second];
		deck[second] = temp; 
	}
}

void Deck::dealPlayer()
{
	if (playersHand.size() <= 5)
	{
		playersHand.push_back(deck[deck.size() - 1]);
		discardPile.push_back(deck[deck.size() - 1]);
		deck.pop_back(); 
	}
	else
	{
		std::cout << "Your hand is full" << std::endl;
		playerDone = true; 
	}
	if (getHandValue(playersHand) > 21)
	{
		for (size_t i = 0; i < playersHand.size(); i++)
		{
			if (playersHand[i]->getNumber() == 1)
				playersHand[i]->setValue(1); 
		}
	}

}

void Deck::dealHouse()
{
	if (houseHand.size() <= 5)
	{
		houseHand.push_back(deck[deck.size() - 1]);
		discardPile.push_back(deck[deck.size() - 1]);
		deck.pop_back();
	}
	else
		houseDone = true; 
	if (getHandValue(houseHand) > 21)
	{
		for (size_t i = 0; i < houseHand.size(); i++)
		{
			if (houseHand[i]->getNumber() == 1)
				houseHand[i]->setValue(1); 
		}
	}
}

int Deck::getHandValue(std::vector<Card*> a_deck)
{
	int totalValue = 0; 
	for (size_t i = 0; i < a_deck.size(); i++)
	{
		totalValue += a_deck[i]->getValue();
	}
	return totalValue; 
}

void Deck::showHands()
{
	std::cout << "Dealers hand total value = " << getHandValue(houseHand) << std::endl;
	for (size_t i = 0; i < houseHand.size(); i++)
	{
		switch (houseHand[i]->getSuit())
		{
		case HEARTS:
			std::cout << houseHand[i]->getNumber() << " of HEARTS" << std::endl;
			break;
		case CLUBS:
			std::cout << houseHand[i]->getNumber() << " of CLUBS" << std::endl;
			break;
		case SPADES:
			std::cout << houseHand[i]->getNumber() << " of SPADES" << std::endl;
			break;
		case DIAMONDS:
			std::cout << houseHand[i]->getNumber() << " of DIAMONDS" << std::endl;
			break;
		default:
			break;
		}
	}

	std::cout << "\nPlayers hand total value = " << getHandValue(playersHand) << std::endl;
	for (size_t i = 0; i < playersHand.size(); i++)
	{
		switch (playersHand[i]->getSuit())
		{
		case HEARTS:
			std::cout << playersHand[i]->getNumber() << " of HEARTS" << std::endl;
			break;
		case CLUBS:
			std::cout << playersHand[i]->getNumber() << " of CLUBS" << std::endl;
			break;
		case SPADES:
			std::cout << playersHand[i]->getNumber() << " of SPADES" << std::endl;
			break;
		case DIAMONDS:
			std::cout << playersHand[i]->getNumber() << " of DIAMONDS" << std::endl;
			break;
		default:
			break;
		}
	}
}

void Deck::checkPlayer()
{
	int value = getHandValue(playersHand);
	if (value > 21)
	{
		gameOver = true; 
		playerWins = false; 
		playerDone = true;
	} 
}

void Deck::checkHouse()
{
	int pValue = getHandValue(playersHand);

	if (getHandValue(houseHand) > 21)
	{
		gameOver = true;
		playerWins = true;
		houseDone = true;
	}
	while (getHandValue(houseHand) < 17)
		dealHouse(); 
	if (getHandValue(houseHand) < pValue && pValue <= 21)
	{
		gameOver = true;
		playerWins = true;
		houseDone = true; 
	}
	else if (getHandValue(houseHand) > pValue && pValue <= 21 && getHandValue(houseHand) <= 21)
	{
		gameOver = true;
		playerWins = false;
		houseDone = true; 
	}
	else if (getHandValue(houseHand) > 21)
	{
		gameOver = true;
		playerWins = true;
		houseDone = true;
	}
	clearScreen();
}

void Deck::clearScreen()
{
	system("CLS");
	std::cout << "\t" << "WELCOME TO BLACK JACK 5000" << std::endl;
	showHands();
}

void Deck::gameLoop()
{
	shuffle();
	dealHouse();
	dealHouse();
	dealPlayer();
	dealPlayer();

	clearScreen();
	checkPlayer(); 
	
	while (!playerDone)
	{
		clearScreen();
		std::cin.clear(); 
		std::cin.ignore(std::cin.rdbuf()->in_avail()); 
		std::cout << "Would you like to be hit? "; 
		std::cin >> playerInput;
		switch (playerInput)
		{
		case 'y':
			dealPlayer();
			clearScreen();
			checkPlayer();
			break;
		case 'n':
			playerDone = true;
			break;
		default:
			break;
		}
	}
	clearScreen();
	if (!gameOver)
		checkHouse();


	if (playerWins)
		std::cout << "CONGRATULATIONS YOU WON!" << std::endl;
	else if (!playerWins)
		std::cout << "WELL SHIT, try again?" << std::endl;

	gameOver = true; 

}