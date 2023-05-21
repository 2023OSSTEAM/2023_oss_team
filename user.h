#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20] ;
    char number[8] ;
    char penalty[30] ;
} User;

int insertUser(User * u ) ;
void listUser(User * u[], int count) ;
int updateUser(User * u ) ;
int selectMenu() ;
int selectDataNo(User * user[],int count) ;
