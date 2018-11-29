/*
 * Card tested: Council Room (card 8)
 * Expected behavior: Draw four more cards from deck to add to hand, increment a buy, all other players draw a card, and discard the played card
 * Cumulative +3 cards, +1 buy, +1 cards for everyone else
 */
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

int main()
{
	
	//set up game
	int i;
	int seed=1000;
	int numPlayers=4;
	int b = 2;
	int *bonus=&b;
int k[10] = {adventurer, council_room, feast, gardens, mine
	                    , remodel, smithy, village, baron, great_hall};
 	struct gameState *G = newGame();
 	initializeGame(numPlayers,k,seed,G);
		
	printf("\n\n*****Testing card: Council Room*****\n\n");

	//*********testing**************
	//each player out of the 4 players will play Council Room 5 times
	for (i=0; i<5; i++)
	{
		printf("Testing player %i's turn: ", whoseTurn(G));
			
		int currentNumHand = numHandCards(G);
		int buys = G->numBuys;
		
		//play smithy card
		cardEffect(8,1,2,3,G,1,bonus);

		printf("Testing for net gain of 3 cards\n");
		if (currentNumHand + 3 == numHandCards(G) )
			printf("Pass\n");
		else
			printf("Fail\n");

		printf("Testing for net gain of 1 buy\n");
		if (buys+1 == G->numBuys)
			printf("Pass\n");
		else
			printf("Fail\n");
	
		endTurn(G);

	}
	
	return 0;
}
