/*
 * Function tested: fullDeckCount
 * Full function description: int fullDeckCount(int player, int card, struct gameState*state)
 * Returns number of cards in player's deck
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
	int i,j,n;
	int seed = 1000;
	int numPlayers=2;

	//default card set
	int k[10] = {adventurer, council_room, feast, gardens, mine 
	            , remodel, smithy, village, baron, great_hall};
 
	struct gameState *G;
	G = newGame();
	printf("%i\n", initializeGame(numPlayers, k, seed, G));

	printf("\n\n*****Testing function: fullDeckCount() : *****\n\n");
	
	//testing correct deck count after buying
	//printf("Testing correct count after buying: \n");
	for (i=0; i<numPlayers;i++)
	{
		printf("Testing for player %i:\n", i+1);
		for (j=0; j<5; j++) //test for j card 
		{
			int currentDeckCount = fullDeckCount(i, j, G);
			printf("Testing correct count after buying: \n");
			for (n=0; n<3; n++) //test three buys each
			{
				int currentDeckCount = fullDeckCount(i, j, G);
				buyCard(j, G);
				int newDeckCount = fullDeckCount(i, j, G);
				if (newDeckCount == currentDeckCount+1)
					printf("Pass\n");
				else
					printf("Fail\n");
				//set up for next test
				G->numBuys++;
				G->coins+=10;

			}

		}

		
		endTurn(G);
	}

	return 0;

}
