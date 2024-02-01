//
// Created by wendellbest on 1/29/24.
//

#ifndef SOLITAIRE_CARD_H
#define SOLITAIRE_CARD_H

typedef struct Card{
    char rank;
    char suit;
    char faceUp;
}Card;

int isRank(char c);

#endif //SOLITAIRE_CARD_H
