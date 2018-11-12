/*
 * Card tested: Adventurer (card #7)
 * Expected behavior: Keep flipping deck until you have two treasure cards, then put those
 * two cards in your hand, and discard the exposed cards
 * Input: 
 * Dependencies: deckCount, discardCount
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

int main()
{
	    int i,j;
	    int seed;
	    int numPlayers;
	    int b = 1;
	    int *bonus=&b;
 	    int k[10] = {adventurer, council_room, feast, gardens, mine
                       , remodel, smithy, village, baron, great_hall};
            struct gameState *G = newGame();

	    for (i=0; i<10; i++)
	    	{
			printf("Test %i:\n", i+1);
			int pass=0;
	    		int fail=0;

			seed = rand()%1000; //random number between 1-1000
			numPlayers = rand()%4+1; //random number between 1-4
            		initializeGame(numPlayers,k,seed,G);
			
			for (j=0; j<100; j++)
				{
					int currentPlayer = whoseTurn(G);
					
					int randomDeckCount = rand()%10;
					if (randomDeckCount ==1)
						G->deckCount[currentPlayer]=0;
					else
					{
						randomDeckCount = rand()%MAX_DECK;
						G->deckCount[currentPlayer]=randomDeckCount;
					}
					/*
					int randomHandCount = rand()%MAX_HAND;
					G->handCount[currentPlayer] = randomHandCount;
					*/
					int randomDiscardCount = rand()%MAX_HAND;
					G->discardCount[currentPlayer] = randomDiscardCount;
					
					int result = cardEffect(7,1,1,1,G,1,bonus); //play card
					if (result==0) //success
						pass++;
					else //failed test
						fail++;

					endTurn(G);
				}
				
			printf("Passed tests: %i\n", pass);
			printf("Failed tests: %i\n", fail);
		}
	return 0;
}	
