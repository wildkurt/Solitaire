//
// Created by wende on 5/30/2022.
//

#include "tableau.h"
#include <string.h>

Card *setPointer( int col){
    switch(col){
        case 7 : return t7;
        case 6 : return t6;
        case 5 : return t5;
        case 4 : return t4;
        case 3 : return t3;
        case 2 : return t2;
        case 1 : return t1;
        default: return 0;
    }
}

int isTableauCorrect(){
    Card *ptr;
    int column = 7;
    while(column != 0){
        ptr = setPointer(column);
        while(ptr->rank != '|'){
            ptr++;
        }
        ptr++;
        while(isRank((ptr + 1)->rank)){
            if(isRedOrBlack(ptr->suit) == isRedOrBlack((ptr + 1)->suit))
                return 0;
            if(rankValue(ptr->rank) <= rankValue((ptr + 1)->rank))
                return 0;
        }
        column--;
    }
    return 1;
}

int findTableau(char *buffer, FILE *input, int *line){
    Card *ptr;
    int tabCol = 7, index;
    char covered = 'T';

    do{
        line++;
        ptr = setPointer(tabCol);
        index = 0;
        covered = 'T';
        for(int i = 0; buffer[i] != '\n'; i++){
            if(buffer[i]=='#')
                break;
            if(strstr(buffer,"TABLEAU:")!=0){
                fgets(buffer, 50, input);
                i--;
                continue;
            }
            if(isRank(buffer[i]) && isSuit(buffer[i+1])){
                ptr[index].rank = buffer[i];
                ptr[index].suit = buffer[i+1];
                if(covered == 'T'){
                    ptr[index].covered = 'T';
                }
                else{
                    ptr[index].covered ='F';
                }
                index++;
            }
            else if(buffer[i] == '|'){
                ptr[index].rank = buffer[i];
                ptr[index].suit = 0;
                ptr[index].covered = 'F';
                covered = 'F';
                index++;
            }
        }
        if(strstr(buffer,"TABLEAU:")==0)
            tabCol--;
    }while(fgets(buffer, 50, input) != 0 && tabCol != 0);
    if(isTableauCorrect() && tabCol == 0){
        return 1;
    }
    else{
        return 0;
    }
}

void printTableau(){
    Card *ptr;
    for(int i = 7; i >= 1; i--){
        ptr = setPointer(i);
        while(isRank(ptr->rank) || ptr->rank == '|'){
            if(ptr->suit == 0)
                printf("%c ", ptr->rank);
            else
                printf("%c%c ",ptr->rank, ptr->suit);
            ptr++;
        }
        printf("\n");
    }
}

int countCoveredCards(){
    int coveredCount = 0, column = 7;
    Card *ptr;
    while(column != 0){
        ptr = setPointer(column);
        while(isRank(ptr->rank)){
            if(ptr->covered == 'T')
                coveredCount++;
            ptr++;
        }
        column--;
    }

    return coveredCount;
}