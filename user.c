#include "user.h"

int insertUser(User * u)
{
    printf("Name? ") ;
    scanf("%s", u->name) ;
    printf("Student Number? ") ;
    scanf("%s", u->number) ;
    printf("=>User Successfully Added!\n") ;
    
    return 1 ;
}

void listUser(User * users[], int count)
{
	printf("\nNo Number Name Penalty \n") ;
	printf("========================== \n") ;
	for (int i = 0 ; i < count ; i++)
    {
        if(users[i] == NULL)
            continue ;

        printf("%d %s %s\n", i + 1, users[i]->number, users[i]->name) ;
	}
	printf("\n") ;
}

int updateUser(User * u)
{
    printf("New name? \n") ;
    scanf("%s", u->name) ;
    printf("New Student Number? \n") ;
    scanf("%s", u->number) ;
    return 1 ;
}

int selectUserMenu()
{
    int menu ;
    printf("\n ***************** \n") ;
    printf(" (1) User Menu\n") ;
    printf("1. User List \n") ;
    printf("2. User Addition \n") ;
    printf("3. User Update \n") ;
    printf("4. User Remove  \n") ;
    printf("5. Save User List\n") ;
    printf("0. Go Back to Main Menu\n") ;
    printf(" Write the Number to Use >> ") ;
    scanf("%d", &menu) ;

    return menu ;    
}

int selectUserDataNo(User * users[], int count)
{
    int num ;
    listUser(users, count) ;
    printf("Number? (cancel :0) ") ;
    scanf("%d", &num) ;
    return num ;
}

int saveUserList(User * users[], int count)
{
    FILE * fp = fopen(userfilename, "wt") ;
    for (int i = 0 ; i < count ; i++)
    {
        if (users[i] == NULL)
            continue ;
        fprintf(fp, "%d %s %s\n", i + 1, users[i]->name, users[i]->number) ;
    }
    fclose(fp) ;
    return 1 ;
}

int loadUserList(User * users[])
{
    int i = 0 ;
    FILE * fp = fopen(userfilename, "r") ;
    if (fp == NULL)
    {
        printf("File Open Error ") ;
        return -1 ;
    }
    for ( ; ; )
    {
        if(feof(fp))
            break ;
        fscanf(fp, "%d %s %s\n", &i, users[i]->name, users[i]->number) ;
    }
    fclose(fp) ;
    return i ; 
}

int user(User * users[])
{
	int index = 0 ;
	int menu = 0 ;
    if (-1 < (index = loadUserList(users)))
        printf("=> Loading Success!\n") ;
    else
        printf("=> No Such File\n") ;
	int count = index ;

    while(1)
    {
        menu = selectUserMenu() ;
        if (menu == 0) 
            break ;
        if (menu == 1 || menu == 3 || menu == 4)
        {
            if (count == 0 && index == 0) 
            {
                printf("No user stored, need to add user.\n") ;
                continue ;
            }
        }
            
        if (menu == 1)
        {
            //데이터 조회 (리스트로)
            if (count > 0)
                listUser(users, index) ; // count? index?
            else
                printf("List is Empty.\n") ;
        }
        else if (menu == 2)
        {   //데이터 추가
            if (count >= 100)
            {
                printf("Storage Full: could not add more\n") ;
                continue;
            }
            users[index] = (User *)malloc(sizeof(User)) ;
            count += insertUser(users[index++]) ;
        }
        else if (menu == 3)
        {
            int no = selectUserDataNo(users, index) ;
            if (no == 0)
            {
                printf("=> canceled!\n") ;
                continue ;
            }
            updateUser(users[no - 1]) ;
        }
        else if (menu == 4)
        {
            int no = selectUserDataNo(users, index) ;
            if (no == 0)
            {
                printf("=> canceled!\n") ;
                continue ;
            }
            int deleteok ;
            printf("Are you sure to remove it? (yes :1) ") ;
            scanf("%d", &deleteok) ;
            if (deleteok == 1)
            {
                if(users[no - 1])
                    free(users[no - 1]) ;
                users[no - 1] = NULL ;
                count-- ;
            }
        }
        else if (menu == 5)
        {
            saveUserList(users, count) ;
            printf("Successfully Loaded\n") ;
        }
        else
            printf("Write the Number between 0 to 5\n") ;
    }
    printf("User Setting Complete!\n") ;

    return count ;
}
