/*
 * Card tested: Adventurer (card #7)
 * Expected behavior: Keep flipping deck until you have two treasure cards, then put those
 * two cards in your hand
 * and discard the exposed cards
 * Input: set number of cards in hand, set number of cards in deck, empty discard pile
 * Output: two additional cards in hand, -n number of cards in deck, +n number of cards in discard pile
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
	
	//set up game
	int i;
	int numPlayers;
	int k[10] = {adventurer, council_room, feast, gardens, mine
	                    , remodel, smithy, village, baron, great_hall};
	//int b = 1;
	//int *bonus = &b;
	int pass=0;
	int fail=0;

	printf("\n\n*****Testing card: Adventurer*****\n\n");
	for (i=0; i<2; i++)
	{
		//game setup with random variables	
		int seed=rand()%1000;
		numPlayers=rand()%4+1;
 		struct gameState *G = newGame();
 		initializeGame(numPlayers,k,seed,G);

		int player = G->whoseTurn;

		int randomHand = rand()%1000;
		G->handCount[player]=randomHand;

		int randomDeck = rand()%1000;
		G->deckCount[player]=randomDeck;

		//int randomDiscard = rand()%1000;
		//G->discardCount[player]= randomDiscard;

		//cardEffect(7, 1, 1, 1, G, 1, bonus);
		
		
		//test 1: we should have 2 more cards in our hand than we started with
		
		if (randomHand+2 == G->handCount[player])
			pass++;
		else
			fail++;
		
		//test 2: the deck count added to the discard pile count should equal the original deck count
		if (randomDeck - G->deckCount[player] -2 == G->discardCount[player])
			pass++;
		else
			fail++;
		
		endTurn(G);

	}	

	printf("Here are your results: \n");
	printf("Pass: %i\n", pass);
	printf("Fail: %i\n", fail);

	return 0;
}
