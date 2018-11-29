/*
 * Function tested: whoseTurn
 * Full function description: int whoseTurn(struct gameState*state)
 * Returns current player index
 */
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main()
{
	//setup
	int i;
	int seed = 1000;
	int numPlayers=4;

	//default card set
	int k[10] = {adventurer, council_room, feast, gardens, mine 
	            , remodel, smithy, village, baron, great_hall};
 
	struct gameState *G;
	G = newGame();
	initializeGame(numPlayers, k, seed, G);

	printf("\n\n*****Testing function: whoseTurn() : *****\n\n");
	int who = 0;
	for (i=0; i<12; i++)
	{
		printf("Testing player %i's turn: ", who+1);
		if (who == whoseTurn(G))
			printf("Pass\n");
		else
			printf("Fail\n");
		endTurn(G);
		if (who == 3)
			who = 0;
		else
			who++;
	}
		

	return 0;

}
