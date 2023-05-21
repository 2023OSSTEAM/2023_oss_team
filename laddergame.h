#include "user.h"
#include "penalty.h"
#include "game.h"

#define max 21

void playgame(User * users[], int num_of_users, Penalty * penalties, int num_of_penalties) ;

int setUsers() ;
int setPenalty() ;
void laddergame(int * participants, int penalty) ;
void loadHistory() ;

int selectMenu() ;
