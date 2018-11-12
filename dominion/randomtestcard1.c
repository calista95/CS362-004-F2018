/*
 * Card randomly tested: Village
 * Expected behavior: Draw one card, increment two actions, discard played card from hand
 * Input: set number of cards and actions
 * Output: change number of actions by +2, number of cards should stay exactly the same because there is no net change 
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

int main()
{

	//set up game
	int i,j;
        int seed;
	int numPlayers;
	int b = 1;
	int*bonus=&b;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
	remodel, smithy, village, baron, great_hall};
	int pass=0;
	int fail=0;

	printf("\n\n*****Random Testing for Card: Village*****\n\n");
	for (i=0; i<100; i++) //test for 100 distinct games
		{
			//printf("Random test number %i\n", i);	

			//game setup with random variables	
			numPlayers = rand()%4; //random number between 1-4
			seed = rand()%5000;	
			struct gameState *G = newGame();
			initializeGame(numPlayers,k,seed,G);
		
			for (j=0; j<5000; j++) //5000 tests on each game
			{
				int randomActions = rand()%1000;
				G->numActions = randomActions; 

				int randomCards = rand()%1000;
				G->handCount[G->whoseTurn] = randomCards;

				cardEffect(14,1,1,1,G,1,bonus);

				//testing: we should expect to see number of actions incremented by 2 and cards on hand to stay the same (gain 1, discard 1)
				if (G->numActions == randomActions+2 || G->handCount[G->whoseTurn] == randomCards)
					pass++;
				else
					fail++;

				endTurn(G);
			}
							
		}
	printf("Here are your results: \n");
	printf("Pass: %i\n", pass);
	printf("Fail: %i\n", fail);
}
