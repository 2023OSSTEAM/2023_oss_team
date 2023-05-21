#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char penaltyName[20] ;
    char period[8] ;
} Penalty ;


int createPenalty(Penalty * u) ;
void listPenalty(Penalty * u[], int count) ;
int updatePenalty(Penalty * u) ;
int selectMenu() ;
int selectDataNo(Penalty[] * penalty, int count) ;
