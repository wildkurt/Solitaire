//
// Created by wende on 5/30/2022.
//

#ifndef SOLITAIRE_CHECK_H
#define SOLITAIRE_CHECK_H
typedef struct{
    int turnOver;
    int limit;
}Rules;

void countCards(int *covered, int *stock, int *waste);

#endif //SOLITAIRE_CHECK_H
