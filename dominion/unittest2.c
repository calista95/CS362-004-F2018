/*
 * Function tested: buyCard()
 * Full function description: int buyCard(int supplyPos, struct gameState *state);
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
	 int i,j;
	 int seed = 1000;
	 int numPlayer = 2;
	 int k[10] = {adventurer, council_room, feast, gardens, mine
	            , remodel, smithy, village, baron, great_hall};
	 struct gameState *G= newGame();
	 initializeGame(numPlayer, k, seed, G);


	printf("Testing buyCard() : \n");
		
	for (i=0; i<27; i++) //for i'th card
		{
			int cost = getCost(i);
			int numBuys = G->numBuys;
			int currentMoney = G->coins;
			int supply = supplyCount(i, G); //supply count of specified card
			
			if (cost <= currentMoney && numBuys >=1 && supply >=0)
				{
					printf("Testing a successful buy: ");
					if (buyCard(i, G) ==0)
					{
						printf("Pass\n");
						printf("Testing if new card is successfully added to user stack: ");
						int found=0;
						for (j=0; j<MAX_DECK; j++)
							{
								if (i==G->discard[G->whoseTurn][j])
									{
										found=1;
										break;
									}

							}		
						if (found==0)
							printf("Fail\n");
						else if (found==1)
							printf("Pass\n");
					}
					else
						printf("Fail\n");

				}	
			else
				{
					printf("Testing an unsuccessful buy: ");
					if (buyCard(i,G) == -1)
						printf("Pass\n");
					else
						printf("Fail\n");
				}

			//set testing conditions for next round
			if (i%2==0) //if even round, increment number of buys
				G->numBuys++;
			if (i%3==0) //if round divisible by 3, increment number of coins
				G->coins+=2;
			if (i%4==0) //if round divisible by 4, switch player
				endTurn(G);
			//always increment actions so we can buy another card
			G->numActions++;
			
		}

	//test if new card is successfully added to user stack
	/*
	for (i=0; i<27;i++) //test for each card
	{
		for (j=0; j<10; j++) //10 iterations per card
		{
			printf("%i\n", getCost(i)); //cost of the card
		}
	}	
	*/
	
	return 0;

}
