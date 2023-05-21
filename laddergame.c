#include "laddergame.h"

void playgame(User * users, int num_of_users, Penalty * penalties, int num_of_penalties)
{
    int * participants[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} ;
    int penalty = 6 ;

    participants = setUser(users, num_of_users) ;
    penalty = setPenalty(penalties, num_of_penalties) ;
    laddergame(participants, penalty) ;
}

int * setUser(User * users, int num_of_users)
{
    char * indexs[25] ;
    int * participants[11] ;

    listUser(users, num_of_users) ;
    printf("\n>>> Choose the index numbers of user to use under 10(like 8,4-14) : ") ;
    scanf("%s", indexes) ;
    participants = parser(indexes) ;

    return participants ;
}

int * parser(char * indexes)
{
    int * participants[11] ;
    int length = sizeof(ledexes) ;
    int pre = 0 ;
    int cnt = 0 ;
    char del = '' ;
    for (int i = 0 ; i < length ; i++)
    {
        if (cnt >= 10)
            printf("Only 10 people could participate, %d is the last member", pre) ;

        if (indexes[i].isDigit())
        {
            if (del == '-')
                for (int j = pre ; j <= atoi(indexes[i]) ; j++)
                    if (isNotExist(participants, j) && cnt < 10)
                        articipants[cnt++] = j ;
            pre = atoi(indexes[i]) ;
            del = '' ;
        }
        else if (indexes[i] == '-')
        {
            del = '-' ;
        }
        else if (indexes[i] == ',')
        {
            del = ',' ;
            if (isNotExist(participants, pre) && cnt < 10)
                participants[cnt++] = pre ;
        }
    }

    return participants ;
}

bool isNotExist(int * addr, int num)
{
    for (int j = 0 ; j < sizeof(addr) ; j++)
        if (num == addr[j])
            return true ;
    return false ;
}

int setPenalty(Penalty * penalties, int num_of_penalties)
{
    int penalty = 0 ;
    listPenalty(users, num_of_penalties) ;
    printf("\n>>> Choose the index number of penalty to use : ") ;
    scanf("%d", &penalty) ;

    return penalty;
}

int selectMenu()
{
    int menu ;
    printf("\n ***************** \n") ;
    printf("1. User Setting\n") ;
    printf("2. Penalty Setting\n") ;
    printf("3. Run Game \n") ;
    printf("0. Exit \n") ;
    printf(" 이용할 메뉴입력 >>") ;
    scanf("%d", &menu) ;
    printf("\n ***************** \n") ;

    return menu ;    
}