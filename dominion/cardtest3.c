/*
 * Card tested: Village (card #14)
 * Expected behavior: Draw one card, increment two actions, discard played card from hand
 * 
 */
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main()
{
	//set up game
	int i,j;
	int seed=1000;
	int numPlayers=4;
	int b = 1;
	int*bonus=&b;
int k[10] = {adventurer, council_room, feast, gardens, mine
	                    , remodel, smithy, village, baron, great_hall};
 	struct gameState *G = newGame();
 	initializeGame(numPlayers,k,seed,G);

	printf("\n\n*****Testing card: Village*****\n\n");

	//each player (4 players total) will play the village card 3 times
	for (int i=0; i<12; i++)
	{
		printf("Testing player %i's turn: \n", whoseTurn(G)+1);
		//check preconditions
		int cardsBefore = numHandCards(G); //save number of cards on hand before playing village
		int actionsBefore = G->numActions; //save number of actions before playing village
		cardEffect(14,1,2,3,G,1,bonus); //play village card
		//check if card card stays the same (plus 1 discard 1 gives a cumulative 0 change)
		printf("Testing for correct number of cards in hand: ");
		if (numHandCards(G) == cardsBefore)
			printf("Pass\n");
		else
			printf("Fail\n");

		//check if actions are incremented by 2
		printf("Testing for actions after effect: %i ", G->numActions);
		if (actionsBefore+2 == G->numActions)
			printf("Pass\n");
		else
			printf("Fail\n");
		endTurn(G);

	}
	
	return 0;
}
