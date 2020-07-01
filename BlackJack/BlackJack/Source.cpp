#include "Deck.h"
#include <crtdbg.h>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Deck* testDeck = new Deck();
	
	testDeck->gameLoop(); 

	




	return 0;
}
