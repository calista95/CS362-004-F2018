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
	 int i;
	 int seed = 1000;
	 int numPlayer = 2;
	 int k[10] = {adventurer, council_room, feast, gardens, mine
	            , remodel, smithy, village, baron, great_hall};
	 struct gameState *G= newGame();
	 initializeGame(numPlayer, k, seed, G);


	printf("Testing buyCard() : \n");
		
	for (int i=0; i<27; i++) //for i'th card
		{
			int cost = getCost(i);
			int numBuys = G->numBuys;
			int currentMoney = G->coins;
			int supply = supplyCount(i, G); //supply count of specified card
			printf("cost: %i\n", cost);
			printf("current: %i\n", currentMoney);

			printf("Testing for sufficient amount of money: ");
			if (cost > currentMoney) //check that cost is enough
				{
					if (buyCard(i, G) == -1)
					{
						printf("Pass\n");
						printf("Testing for sufficient number of buys: ");
						if (numBuys <=0)
						{
							if (buyCard(i, G) == -1)
							printf("Pass\n");
							else
							printf("Fail\n");
						}
			else if (numBuys >=1)
			{
					if (buyCard(i, G) == 0)
						printf("Pass\n");
					else
						printf("Fail\n");
			}

					}	
					else
						printf("Fail\n");
				}
			else if (cost <= currentMoney)
				{
					if (buyCard(i, G) == 0)
						printf("Pass\n");
					else
						printf("Fail\n");

				}
			
			printf("Testing for sufficient number of buys: ");
			if (numBuys <=0)
			{
					if (buyCard(i, G) == -1)
						printf("Pass\n");
					else
						printf("Fail\n");
			}
			else if (numBuys >=1)
			{
					if (buyCard(i, G) == 0)
						printf("Pass\n");
					else
						printf("Fail\n");
			}

			printf("Testing for card supply: ");
			if (supply <=0)
			{
					if (buyCard(i, G) == -1)
						printf("Pass\n");
					else
						printf("Fail\n");
			}
			else if (supply >=1)
			{
					if (buyCard(i, G) == 0)
						printf("Pass\n");
					else
						printf("Fail\n");
			}
			
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
