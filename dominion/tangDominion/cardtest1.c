/*
 * Card tested: Smithy (card 13)
 * Expected behavior: Draw three more cards from deck to add to hand, then discard Smithy card
 * Cumulative +2 cards
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
		
	printf("\n\n*****Testing card: Smithy*****\n\n");

	//*********testing**************
	//each player out of the 4 players will play Smithy 5 times
	for (i=0; i<20; i++)
	{
		printf("Testing player %i's turn: ", whoseTurn(G));
			
		int currentNumHand = numHandCards(G);
		//play smithy card
		printf("Test in cardEffect: ");
		cardEffect(13,1,2,3,G,1,bonus);

		if (currentNumHand + 2 == numHandCards(G) )
			printf("Pass\n");
		else
			printf("Fail\n");
		endTurn(G);

	}
	
	//end note: after a certain number of iterations, tests will fail because there are not enough cards to draw from
	
	return 0;
}
