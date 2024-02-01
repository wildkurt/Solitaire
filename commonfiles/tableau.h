//
// Created by wendellbest on 1/29/24.
//

#ifndef SOLITAIRE_TABLEAU_H
#define SOLITAIRE_TABLEAU_H

#include <stdio.h>
#include "Card.h"

#define MAX_BUFFER 200

typedef struct Tableau{
    Card tab1[22];
    Card tab2[22];
    Card tab3[22];
    Card tab4[22];
    Card tab5[22];
    Card tab6[22];
    Card tab7[22];
}Tableau;

int getTableau(Tableau *tableau, int *line, FILE *filelink, char *buffer);
Card *getPointerToColumn(int column, Tableau *tableau);

#endif //SOLITAIRE_TABLEAU_H