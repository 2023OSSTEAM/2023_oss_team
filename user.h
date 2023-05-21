#include <stdio.h>
#include <stdlib.h>

struct _User {
    char name[20] ;
    char number[8] ;
    char penalty[30] ;
} ;

typedef struct _User User ;

int insertUser(User * u ) ;
void listUser(User * u[], int count) ;
int updateUser(User * u ) ;
int selectUserMenu() ;
int selectUserDataNo(User * user[], int count) ;

int user(User * users[], int cnt) ;