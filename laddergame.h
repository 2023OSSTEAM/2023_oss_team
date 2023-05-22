#include <stdbool.h>
#include "user.h"
#include "penalty.h"
#include "game.h"

#define MAX 21

void playgame(User * users[], int num_of_users, Penalty * penalties[], int num_of_penalties) ;

void setUser(User * users[], int num_of_users) ;
bool isNotExist(int * addr, int num) ;
void parser(char * indexes) ;
int setPenalty(Penalty * penalties[], int num_of_penalties) ;
int laddergame(int * participants) ;
void loadHistory() ;
void saveResult(User * users[], Penalty * penalties[], int penalty, int penalty_taker) ;
int selectMenu() ;
