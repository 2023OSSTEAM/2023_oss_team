#include <stdbool.h>
#include "user.h"
#include "penalty.h"
#include "game.h"

#define MAX 21

void playgame(User * users[], int num_of_users, Penalty * penalties[], int num_of_penalties) ;

int * setUser(User * users[], int num_of_users) ;
bool isNotExist(int * addr[], int num) ;
int * parser(char * indexes[]) ;
int setPenalty(Penalty * penalties[], int num_of_penalties) ;
int laddergame(int * participants, int penalty) ;
void loadHistory() ;

int selectMenu() ;
