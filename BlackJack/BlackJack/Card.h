#pragma once

enum Suit
{
	HEARTS,
	CLUBS,
	SPADES,
	DIAMONDS
};

class Card
{
public:
	void setSuit(int a_suit) { suit = a_suit; }
	int getSuit() { return suit; }

	void setNumber(int a_number) { number = a_number; }
	int getNumber() { return number; }

	void setValue(int a_value) { value = a_value; }
	int getValue() { return value; }

private:
	int suit;
	int number;
	int value;

};
