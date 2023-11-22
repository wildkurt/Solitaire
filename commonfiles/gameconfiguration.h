//
// Created by wendellbest on 11/22/23.
//

#ifndef SOLITAIRE_GAMECONFIGURATION_H
#define SOLITAIRE_GAMECONFIGURATION_H

#include "rules.h"
#include "foundations.h"
#include "tableau.h"
#include "stockwaste.h"

typedef struct GameConfiguration{
    Rules rules;
    Foundation foundation;
    Tableau tableau;
    StockWaste stockwaste;
    int found;
}GameConfiguration;

#endif //SOLITAIRE_GAMECONFIGURATION_H