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
	for (i=0; i<12; i++)
	{
		printf("Testing for player %i:\n", whoseTurn(G));
		//use Adventurer card
		if (i%2==0)
		{
			printf("Test in cardEffect: ");
			cardEffect(7, 1, 1, 1, G, 1, bonus);
		}
		else
		{
			printf("Test in adventurerFunction: ");
			adventurerFunction(G);
		}
		
		int treasureCards=0;
		//check that two treasure cards have been found in the deck(#4,5,6)
		for (j=0; j<MAX_DECK; j++)
		{
			if (G->deck[whoseTurn(G)][j] == 4 || G->deck[whoseTurn(G)][j] == 5 || G->deck[whoseTurn(G)][j] == 6)
			treasureCards++;
		}
		int treasureHand=0;
		if (treasureCards >=2) //we have at least 2 treasure cards
		{
			//confirm that they are in player's hand
			for (j=0; j<MAX_DECK; j++)
			{
				if (G->hand[whoseTurn(G)][j] == 4 || G->hand[whoseTurn(G)][j] == 5 || G->hand[whoseTurn(G)][j] == 6) 
					treasureHand++;		
			}
			if (treasureHand >=2)
				printf("Testing at least 2 treasure cards in hand: Pass\n");
			else
				printf("Testing at least 2 treasure cards in hand: Fail\n");
		}
		//check that discard pile is not empty
		if (G->discardCount[0] ==0)
			printf("Testing for empty discard pile: Fail\n");
		else
			printf("Testing for empty discard pile: Pass\n");

		endTurn(G);
	}
	return 0;
}
