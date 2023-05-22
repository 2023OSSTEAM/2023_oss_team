#include <stdio.h>
#include <stdlib.h>

#define userfilename "userList"

struct _User {
    char name[20] ;
    char number[8] ;
    char penalty[30] ;  // struct로 바꿀까, 없앨까?
} ;

typedef struct _User User ;

int insertUser(User * u ) ;
void listUser(User * users[], int count) ;
int updateUser(User * u ) ;
int selectUserMenu() ;
int selectUserDataNo(User * users[], int count) ;

int saveUserList(User * users[], int count) ;
int loadUserList(User * user) ;

int user(User * users[]) ;
