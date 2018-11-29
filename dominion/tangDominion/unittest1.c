/*
 * Function tested: initializeGame
 * Full function description: int initializeGame(int numPlayers, int kingdomCards[10], int randomSeed, struct gameState*state);
 * Return 0 on success
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

	//default card set
	int k[10] = {adventurer, council_room, feast, gardens, mine 
	            , remodel, smithy, village, baron, great_hall};

	//3 different sets of cards for testing
	int set1[10] = {adventurer, council_room, feast, gardens, mine //all are different
	            , remodel, smithy, village, baron, great_hall};

	int set2[10] = {adventurer,adventurer,adventurer,adventurer,adventurer,adventurer, //all are the same
	adventurer,adventurer,adventurer,adventurer};

	int set3[10] = {adventurer, adventurer, feast, gardens, mine //one pair of duplicates
	            , remodel, smithy, village, baron, great_hall};
 
	 struct gameState *G;


	printf("\n\n*****Testing function: initializeGame() : *****\n\n");


	/* test for correct number of players
	 * expected behavior: fail if numPlayers > MAX_PLAYERS or numPlayers < 2
	 * note: MAX_PLAYERS is defined as 4
	 */
	//printf("Testing for correct number of players:\n");

	for (i=-1; i<10; i++) 
	{
		printf("Testing for correct number of players:\n");
		printf("Test %i: number of players is currrently %i: ", i+2,i);
		
		if (i<2 || i>4) //not enough players
		{
			G=newGame();
			if ((initializeGame(i, k, seed, G) == -1) )
				printf("Pass\n");
			else
				printf("Failed\n");
		}
		else //number of players is within range
		{
			G=newGame();
			printf("%i\n",initializeGame(i, k, seed, G));
			if (G->numPlayers == i)
			{
				printf("Pass: number of players falls within correct range\n");
				printf("Testing for non-duplicate cards: \n");
				printf("Testing set 1: ");
					if ((initializeGame(i, set1, seed, G) == 0) )
						printf("Pass\n");
				printf("Testing set 2: ");
					if ((initializeGame(i, set2, seed, G) == -1) )
						printf("Pass\n");
				printf("Testing set 2: ");
					if ((initializeGame(i, set3, seed, G) == -1) )
						printf("Pass\n");
				
				printf("Testing for correct number of victory cards: ");
				if (i==2)
				{
					assert (G->supplyCount[estate] == 8);
					assert (G->supplyCount[estate] == 8);
					assert (G->supplyCount[estate] == 8);
					printf("Pass\n");
				}
				else if (i==3 || i==4)
				{
					assert (G->supplyCount[estate] == 12);
					assert (G->supplyCount[estate] == 12);
					assert (G->supplyCount[estate] == 12);
					printf("Pass\n");
				}

				printf("Testing for correct number of treasure cards: ");
				assert(G->supplyCount[copper] == 60-(7*i));
				assert(G->supplyCount[silver] ==40);
				assert(G->supplyCount[gold] ==30);
				printf("Pass\n");

			}
			else
				printf("Failed\n");
		}
	}

	return 0;

}
