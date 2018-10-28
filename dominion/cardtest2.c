/*
 * Card tested: Adventurer (card #7)
 * Expected behavior: Keep flipping deck until you have two treasure cards, then put those
 * two cards in your hand
 * and discard the exposed cards
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
	printf("\n\n*****Testing card: Adventurer*****\n\n");
	//set up game
	int i,j;
	int seed=1000;
	int numPlayers=4;
	int b = 1;
	int *bonus = &b;
int k[10] = {adventurer, council_room, feast, gardens, mine
	                    , remodel, smithy, village, baron, great_hall};
 	struct gameState *G = newGame();
 	initializeGame(numPlayers,k,seed,G);

	//testing for 4 players: each player plays adventure card for 3 rounds total
	for (int i=0; i<12; i++)
	{
		printf("Testing for player %i:\n", whoseTurn(G));
		//use Adventurer card
		cardEffect(7, 1, 1, 1, G, 1, bonus);
	
		int treasureCards=0;
		//check that two treasure cards have been found in the deck(#4,5,6)
		for (i=0; i<MAX_DECK; i++)
		{
			if (G->deck[0][i] == 4 || G->deck[0][i] == 5 || G->deck[0][i] == 6)
			treasureCards++;
		}
	
		int treasureHand=0;
		if (treasureCards >=2) //we have at least 2 treasure cards
		{
			//confirm that they are in player's hand
			for (i=0; i<MAX_DECK; i++)
			{
				if (G->hand[0][i] == 4 || G->hand[0][i] == 5 || G->hand[0][i] == 6) 
					treasureHand++;		
			}
			if (treasureHand >=2)
				printf("Testing at least 2 treasure cards in hand: Pass\n");
			else
				printf("Testing at least 2 treasure cards in hand: Fail\n");
		}

		//check that discard pile is empty
		if (G->discardCount[0] ==0)
			printf("Testing for empty discard pile: Pass\n");
		else
			printf("Testing for empty discard pile: Fail\n");

		endTurn(G);
	}

	return 0;
}
