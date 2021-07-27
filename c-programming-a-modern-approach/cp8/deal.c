#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13

int main(void)
{
  bool cards_matrix[NUM_SUITS][NUM_RANKS] = { false };
  int num_cards, suit, rank;
  const char suit_code[NUM_SUITS] = {'c', 'd', 'h', 's'};
  const char  rank_code[NUM_RANKS] = {'2', '3', '4', '5', '6', '7', '8', '9', 't', 'j', 'q', 'k', 'a'};

  srand((unsigned) time(NULL));

  printf("Enter numnber of cards in hand:\n");
  scanf("%d", &num_cards);

  while (num_cards > 0) {
    suit = rand() % NUM_SUITS;
    rank = rand() % NUM_RANKS;
    if (!cards_matrix[suit][rank]) {
      cards_matrix[suit][rank] = true;
      num_cards--;
      printf("The card is %c => %c\n", suit_code[suit], rank_code[rank]);
    }
  }
  return 0;
}