#include <stdio.h>
#include <stdlib.h>

struct _Penalty {
    char penaltyName[20] ;
    char period[8] ;
} ;

typedef struct _Penalty Penalty ;

int createPenalty(Penalty * u) ;
void listPenalty(Penalty * u[], int count) ;
int updatePenalty(Penalty * u) ;
int selectPenaltyMenu() ;
int selectPenaltyDataNo(Penalty * penalty[], int count) ;

int penalty(Penalty * penalties[], int cnt) ;
