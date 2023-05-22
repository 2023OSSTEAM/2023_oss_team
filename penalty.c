#include "penalty.h"

int createPenalty(Penalty * u)
{
    printf("Penalty Name? ") ;
    scanf("%s", u->penaltyName) ;
    printf("Period? ") ;
    scanf("%s", u->period) ;
    printf("=>Penalty Successfully Added!\n") ;
    return 1 ;
}

void listPenalty(Penalty * u[], int count) 
{
	printf("\nNo PenaltyName Period \n") ;
	printf("========================== \n") ;
	for (int i = 0 ; i < count ; i++) 
    {
        if (u[i] != NULL)
            printf("%-2d %-11s %-5s \n", i + 1, u[i]->penaltyName, u[i]->period) ;
	}
	printf("\n") ;
}

int updatePenalty(Penalty * u)
{
    printf("New Penalty name? \n") ;
    scanf("%s", u->penaltyName) ;
    printf("New Period? \n") ;
    scanf("%s", u->period) ;

    return 1 ;
}

int selectPenaltyMenu()
{
    int menu ;
    printf("\n ***************** \n") ;
    printf(" (2) Penalty Menu\n") ;
    printf("1. Penalty List \n") ;
    printf("2. Penalty Add \n") ;
    printf("3. Penalty Update \n") ;
    printf("4. Penalty Remove  \n") ;
    printf("5. Save Penalty List\n") ;
    printf("0. Go Back to Main Menu \n") ;
    printf(" Write the Number of Menu to Use >> ") ;
    scanf("%d", &menu) ;

    return menu ;
}

int selectPenaltyDataNo(Penalty * penalty[], int count)
{
    int num ;
    listPenalty(penalty, count) ;
    printf("Number? (cancel :0) ") ;
    scanf("%d", &num) ;

    return num ;
}


int savePenaltyList(Penalty * penalties[], int count)
{
    FILE * fp = fopen(penaltyfilename, "wt") ;
    for (int i = 0 ; i < count ; i++)
    {
        if (penalties[i] == NULL)
            continue ;
        fprintf(fp, "%d %s %s\n", i + 1, penalties[i]->penaltyName, penalties[i]->period) ;
    }
    fclose(fp) ;
    return 1 ;
}

int loadPenaltyList(Penalty * penalties[])
{
    int i = 0 ;
    FILE * fp = fopen(penaltyfilename, "r") ;
    if (fp == NULL)
    {
        printf("File Open Error ") ;
        return -1 ;
    }
    for ( ; ; )
    {
        if(feof(fp))
            break ;
        fscanf(fp, "%d %s %s\n", &i, penalties[i]->penaltyName, penalties[i]->period) ;
    }
    fclose(fp) ;
    return i ; 
}

int penalty(Penalty * penalties[])
{
	int result = 0 ;
	int index = 0 ;
	int menu = 0 ;  
    if (-1 < (index = loadPenaltyList(penalties)))
        printf("=> Loading Success!\n") ;
    else
        printf("=> No Such File\n") ;
	int count = index ;

    while (1){
        menu = selectPenaltyMenu() ;
        if (menu == 0)
            break ;
        if (menu == 1 || menu ==3 || menu == 4)
        {
            if (count == 0 && index == 0) 
            {
                printf("No penalty stored, need to add penalty.\n") ;
                continue ;
            }
        }
            
        if (menu == 1)
        { 
            if(count > 0)
                listPenalty(penalties, index) ;
            else
                printf("List is Empty.\n") ;
        }
        else if (menu == 2)
        { 
            if (count >= 100)
            {
                printf("Storage Full: could not add more\n") ;
                continue;
            }
            penalties[index] = (Penalty *)malloc(sizeof(Penalty)) ;
            count += createPenalty(penalties[index++]) ;
        }
        else if (menu == 3)
        {
            int no = selectPenaltyDataNo(penalties, index) ;
            if (no == 0) 
            {
                printf("=> canceled!\n") ;
                continue ;
            }
            updatePenalty(penalties[no - 1]) ;
        }
        else if (menu == 4)
        {
            int no = selectPenaltyDataNo(penalties, index) ;
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
                if(penalties[no - 1])
                    free(penalties[no - 1]) ;
                penalties[no - 1] = NULL ;
                count-- ;
            }
        }
        else if (menu == 5)
        {
            savePenaltyList(penalties, count) ;
        }
        else
        {
            printf("Write the number between 0 to 5\n") ;
        }
    }
    printf("Penalty Setting Complete!\n") ;
    
    return count ;
}
