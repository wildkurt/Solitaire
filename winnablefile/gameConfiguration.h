//
// Created by wendellbest on 1/15/23.
//

#ifndef SOLITAIRE_GAMECONFIGURATION_H
#define SOLITAIRE_GAMECONFIGURATION_H


#include "tableau.h"
#include "rules.h"
#include "foundation.h"
#include "StockWaste.h"
#include "Moves.h"

class gameConfiguration{
private:
    Foundation foundation;
    Tableau tableau;
    StockWaste stockWaste;
    Moves moves;
public:
    Rules rules;
    gameConfiguration();
};


#endif //SOLITAIRE_GAMECONFIGURATION_H