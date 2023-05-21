#include "penalty.h"

int createPenalty(Penalty * u)
{
    printf("페널티 항목은?") ;
    scanf("%s", u->penaltyName) ;
    printf("날짜?") ;
    scanf("%s", u->period) ;
    printf("=>Penalty 항목이 추가되었습니다!\n") ;
    return 1 ;
}

void listPenalty(Penalty * u[], int count) 
{
	printf("\n No Penalty Period \n") ;
	printf("========================== \n") ;
	for (int i = 0 ; i < count ; i++) 
    {
        if (u[i] != NULL)
            printf("%d %s %s \n", i + 1, u[i]->penaltyName, u[i]->period) ;
	}
	printf("\n") ;
}

int updatePenalty(Penalty * u)
{
    printf("변경 후  페널티 이름은?\n") ;
    scanf("%s", u->penaltyName) ;
    printf("변경 후 날짜는?\n") ;
    scanf("%s", u->period) ;

    return 1 ;
}

int selectPenaltyMenu()
{
    int menu ;
    printf("\n ***************** \n") ;
    printf("1. Penalty  조회 \n") ;
    printf("2. Penalty 추가 \n") ;
    printf("3. Penalty정보 수정 \n") ;
    printf("4. Penalty 삭제  \n") ;
    printf(" 이용할 메뉴입력 >>") ;
    scanf("%d", &menu) ;

    return menu ;
}

int selectDataNo(Penalty * penalty[], int count)
{
    int num ;
    listPenalty(penalty, count) ;
    printf("번호는? (취소 :0)") ;
    scanf("%d", &num) ;

    return num ;
}

int penalty(Penalty * penalties[], int cnt)
{
	int count = cnt ;
	int result = 0 ;
	Penalty * penalty[100] ;
	int index = 0 ;
	int menu = 0 ;

    while (1){
        menu = selectPenaltyMenu() ;
        if (menu == 0)
            break ;
        if (menu == 1 || menu ==3 || menu == 4)
        {
            if (count == 0) 
            {
                printf("No penalty stored, need to add penalty\n") ;
                continue ;
            }
        }
            
        if (menu == 1)
        { //데이터 조회 (리스트로)
            if(count>0)
                listPenalty(penalty, index) ;
            else
                printf("데이터가 없습니다.\n") ;
        }
        else if (menu == 2)
        {   //데이터 추가
            if (count >= 100)
            {
                printf("Storage Full: could not add more\n") ;
                continue;
            }
            penalty[index] = (Penalty *)malloc(sizeof(Penalty)) ;
            count += insertPenalty(penalty[index++]) ;
        }
        else if (menu == 3)
        {
            int no = selectDataNo(penalty, index) ;
            if (no == 0) 
            {
                printf("=> 취소됨!\n") ;
                continue ;
            }
            updatePenalty(penalty[no - 1]) ;
        }
        else if (menu == 4)
        {
            int no = selectDataNo(penalty, index) ;
            if (no == 0) 
            {
                printf("=> 취소됨!\n") ;
                continue ;
            }
            int deleteok ;
            printf("정말로 삭제하시겠습니까?(삭제 :1)") ;
            scanf("%d", &deleteok) ;
            if (deleteok == 1) 
            {
                if(penalty[no - 1])
                    free(penalty[no - 1]) ;
                penalty[no - 1] = NULL ;
                count-- ;
            }
        }
    }
    printf("Penalty 설정 종료됨!\n") ;
    
    return count ;
}
