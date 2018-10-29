/*
 * Function tested: supplyCount
 * Full function description: int supplyCount(int card, struct gameState*state)
 * Returns number of cards left of the specified card type
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
	int i,j;
	int seed = 1000;
	int numPlayers=2;

	//default card set
	int k[10] = {adventurer, council_room, feast, gardens, mine 
	            , remodel, smithy, village, baron, great_hall};
 
	struct gameState *G;
	G = newGame();
	initializeGame(numPlayers, k, seed, G);

	printf("\n\n*****Testing function: supplyCount() : *****\n\n");
	
	for (i=0; i<15; i++)
	{
		int maxSupply = supplyCount(i, G); //store the maximum supply available	
		//int currentSupply = supplyCount(i, G);	//start out with the maximum number of units we have for a card
		for (j=1; j<maxSupply+2; j++)
		{
			printf("Buying card %i: ", i);
			buyCard(i, G); //buy a card	
			maxSupply--; //decrement supply because we bought a card from the source
			if (maxSupply == supplyCount(i, G))
				printf("Pass\n");
			else
				printf("Failed\n");
			
			//make sure that preconditions are satisfied for next testing round
			G->numBuys++;
			G->coins = G->coins + 10;

		}
	}
	return 0;

}
