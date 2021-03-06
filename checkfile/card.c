//
// Created by wende on 5/30/2022.
//

#include "card.h"
int isRank(char c){
    switch(c){
        case 'A' : return 1;
        case '2' : return 1;
        case '3' : return 1;
        case '4' : return 1;
        case '5' : return 1;
        case '6' : return 1;
        case '7' : return 1;
        case '8' : return 1;
        case '9' : return 1;
        case 'T' : return 1;
        case 'J' : return 1;
        case 'Q' : return 1;
        case 'K' : return 1;
        default: return 0;
    }
}

int isSuit(char c){
    switch(c){
        case 'c' : return 1;
        case 'd' : return 1;
        case 'h' : return 1;
        case 's' : return 1;
        default: return 0;
    }
}

char isRedOrBlack(char c){
    switch(c){
        case 'c' : return 'b';
        case 'd' : return 'r';
        case 'h' : return 'r';
        case 's' : return 'b';
    }
}

int rankValue(char c){
    switch(c){
        case 'A' : return 0;
        case '2' : return 1;
        case '3' : return 2;
        case '4' : return 3;
        case '5' : return 4;
        case '6' : return 5;
        case '7' : return 6;
        case '8' : return 7;
        case '9' : return 8;
        case 'T' : return 9;
        case 'J' : return 10;
        case 'Q' : return 11;
        case 'K' : return 12;
        default: return 0;
    }
}

char valueRank(int c){
    switch(c){
        case 0 : return 'A';
        case 1 : return '2';
        case 2 : return '3';
        case 3 : return '4';
        case 4 : return '5';
        case 5 : return '6';
        case 6 : return '7';
        case 7 : return '8';
        case 8 : return '9';
        case 9 : return 'T';
        case 10 : return 'J';
        case 11 : return 'Q';
        case 12 : return 'K';
        default: return '\0';
    }
}