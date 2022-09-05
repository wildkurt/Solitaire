//
// Created by wendellbest on 8/31/22.
//

#include "searchParameters.h"

searchParameters::searchParameters() {
    limitedSearch = false;
    numberLimitedSearch = 0;
    useHashTable = false;
    useSafeMoves = false;
    useVerboseMode = false;
}

searchParameters::searchParameters(bool limitedSearch, long numberLimitedSearch, bool useHashTable, bool useSafeMoves, bool useVerboseMode) {
    this->limitedSearch = limitedSearch;
    this->numberLimitedSearch = numberLimitedSearch;
    this->useHashTable = useHashTable;
    this->useSafeMoves = useSafeMoves;
    this->useVerboseMode = useVerboseMode;
}

