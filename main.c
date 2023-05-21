#include "laddergame.h"
/*
  Menu
  1 user
  1-1234:crud
  -- 1-56:save/get
  2 penalty
  2-1234:crud
  -- 2-56:save/get
  3 game
  3-1 select user
  3-2 select penalty
  3-3 run (print result)
  3-4 save
  3-5 get history?
*/
void main()
{
  int menu ;
  User * users[100] ;
  Penalty * penalties[100] ;
  int num_of_users = 0 ;
  int num_of_penalties = 0 ;

  while(1)
  {
    menu = selectMenu() ;
    
    if (menu == 0)
      break ;
    else if (menu == 1)
      num_of_users = user(users, num_of_users) ;
    else if (menu == 2)
      num_of_penalties = penalty(penalties, num_of_penalties) ;
    else if (menu == 3)
      playgame(users, num_of_users, penalties, num_of_penalties) ;
    else if (menu == 4)
      loadHistory() ;
    else
      printf("Select between 0 to 3\n\n") ;  
  }

  return 0 ;
}
