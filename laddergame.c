#include "laddergame.h"

int participants[MAX] ;

void playgame(User * users[], int num_of_users, Penalty * penalties[], int num_of_penalties)
{
    int penalty = 6 ;
    int penalty_taker ;

    setUser(users, num_of_users) ;
    penalty = setPenalty(penalties, num_of_penalties) ;
    penalty_taker = laddergame(participants, penalty) ;
    saveResult(users, penalties, penalty, penalty_taker) ;
}

void setUser(User * users[], int num_of_users)
{
    char indexes[45] ;

    listUser(users, num_of_users) ;
    printf("\n>>> Choose the index numbers of user to use under 20 (like 2,4-7) : ") ;
    scanf("%s", indexes) ;
    parser(indexes) ;
}

void parser(char indexes[])
{
    int length = strlen(indexes) ;
    int pre = 0 ;
    int cnt = 0 ;
    char del = ' ' ;

    memset(participants, '\0', MAX) ;
    for (int i = 0 ; i < length ; i++)
    {
        if (cnt >= MAX - 1)
            printf("Only 10 people could participate, %d is the last member", pre) ;

        if (isdigit(indexes[i]))
        {
            if (del == '-')
                for (int j = pre ; j <= indexes[i] - 48 ; j++)
                    if (isNotExist(participants, j) && cnt < MAX - 1)
                        participants[cnt++] = j ;
            pre = indexes[i] - 48 ;
            del = ' ' ;
        }
        else if (indexes[i] == '-')
        {
            del = '-' ;
        }
        else if (indexes[i] == ',')
        {
            del = ',' ;
            if (isNotExist(participants, pre) && cnt < MAX - 1)
                participants[cnt++] = pre  ;
        }
    }
    printf("%s\n", indexes) ;
    for (int i = 0 ; i < cnt ; i++)
        printf("%d ", participants[i]) ;
    printf("\n");
}

bool isNotExist(int * addr, int num)
{
    for (int j = 0 ; j < MAX ; j++)
        if (num == addr[j])
            return false ;
    return true ;
}

int setPenalty(Penalty * penalties[], int num_of_penalties)
{
    int penalty = 0 ;
    listPenalty(penalties, num_of_penalties) ;
    printf("\n>>> Choose the index number of penalty to use : ") ;
    scanf("%d", &penalty) ;

    return penalty;
}

int laddergame(int * participants, int penalty)
{
    int penalty_taker ;
    int num_of_users = 0 ;
    for (int i = 0 ; i < MAX ; i++)
        if (participants[i] != '\0')
            num_of_users++ ;

    int ** MAP ;
    MAP = (int **) malloc (sizeof(int *) * 20) ;
    MAP[0] = (int *) malloc (sizeof(int) * 20 * num_of_users) ;
    for (int i = 1 ; i < 20 ; i++)
        MAP[i] = MAP[i - 1] + num_of_users ;

    int select = rand() % num_of_users ;

    system("pause") ;
    system("cls") ;  // should it be needed?
    /*
    for (int i = 0 ; i < num_of_users + 1 ; i++) 
    {
        char * write = "" ;
        if (i == select)
            write = "LOSE" ;
        printf("%-4s", write) ;
    }
    printf("\n") ;
    */
    VerticalSet(MAP, num_of_users) ;
    HorizonSet(MAP, num_of_users) ;
    PrintLine(MAP, num_of_users) ;     
    penalty_taker = LadderStart(MAP, select) ;

    free(MAP[0]) ;
    free(MAP) ;

    return penalty_taker ;
}

void saveResult(User * users[], Penalty * penalties[], int penalty, int penalty_taker)
{
    char save ;

    printf("Penalty Taker's Info :\n") ;
    printf("Name : %s\nNumber : %sPenalty : %sPeriod : %s\n\n", users[penalty_taker]->name, users[penalty_taker]->number, penalties[penalty]->penaltyName, penalties[penalty]->period) ;

    printf("Do you want to save the result? (y/n) : ") ;
    scanf("%c", &save) ;
    if (save == 'y')
    {   
        time_t now = time(NULL) ;
        struct tm * t = localtime(&now) ;
        char filename[7] ;
        sprintf(filename, "%2d%2d%2d", t->tm_year % 100, t->tm_mon + 1, t->tm_mday) ;

        FILE * fp = fopen(filename, "a") ;
        for (int i = 0 ; i < MAX ; i++)
        {
            if (participants[i] == penalty_taker)
                fprintf(fp, "%s %s %s %s", users[participants[i]]->name, users[participants[i]]->number, penalties[participants[i]]->penaltyName, penalties[participants[i]]->period) ;
            else
                fprintf(fp, "%s %s - -", users[participants[i]]->name, users[participants[i]]->number) ;
        }
        fclose(fp) ;
    }
}

void loadHistory()
{
    char filename[7] ;
    char temp[4][20] ;
    printf("Write the DateTime of game(YYMMDD):") ;
    scanf("%s", &filename) ;

    FILE * fp = fopen(filename, "r") ;
    if (fp == NULL)
    {
        printf("File Open Error\n") ;
        return ;
    }
    printf("%-20s %-8s %-20s %-8s\n", "Name", "Number", "Penalty Name", "Period") ;
    for (int i = 0 ; i < MAX ; i++)
    {
        if (feof(fp))
            break ;
        fscanf(fp, "%s %s %s %s\n", temp[1], temp[2], temp[3], temp[4]) ;
        printf("%-20s %-8s %-20s %-8s\n", temp[1], temp[2], temp[3], temp[4]) ;
    }
    fclose(fp) ;
}

int selectMenu()
{
    int menu ;
    printf("\n ***************** \n") ;
    printf("  Main Menu\n") ;
    printf("1. User Setting\n") ;
    printf("2. Penalty Setting\n") ;
    printf("3. Run Game\n") ;
    printf("4. Game History\n") ;
    printf("0. Exit \n") ;
    printf(" Write the Number of Menu to Use >> ") ;
    scanf("%d", &menu) ;

    return menu ;
}