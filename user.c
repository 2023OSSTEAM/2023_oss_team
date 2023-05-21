#include "user.h"

int insertUser(User * u)
{
    printf("이름은?") ;
    scanf("%s", u->name) ;
    printf("학번은?") ;
    scanf("%s", u->number) ;
    printf("=>사용자가 추가되었습니다!\n") ;
    
    return 1 ;
}

void listUser(User * u[], int count)
{
	printf("\n No Number Name Penalty \n") ;
	printf("========================== \n") ;
	for (int i = 0 ; i < count ; i++)
    {
        if(u[i] == NULL)
            continue ;

        printf("%d %s %s %s \n", i + 1, u[i]->number, u[i]->name, u[i]->penalty) ;
	}
	printf("\n") ;
}

int updateUser(User * u)
{
    printf("변경 후  이름은?\n") ;
    scanf("%s", u->name) ;
    printf("변경 후 학번은?\n") ;
    scanf("%s", u->number) ;
    return 1 ;
}

int selectUserMenu()
{
    int menu ;
    printf("\n ***************** \n") ;
    printf("1. User  조회 \n") ;
    printf("2. User 추가 \n") ;
    printf("3. User정보 수정 \n") ;
    printf("4. User 삭제  \n") ;
    printf(" 이용할 메뉴입력 >>") ;
    scanf("%d", &menu) ;

    return menu ;    
}

int selectUserDataNo(User * user[], int count)
{
    int num ;
    listUser(user, count) ;
    printf("번호는? (취소 :0)") ;
    scanf("%d", &num) ;
    return num ;
}

int user(User * users[], int cnt)
{
	int count = cnt ;
	int result = 0 ;
	int index = 0 ;
	int menu = 0 ;

    while(1)
    {
        menu = selectUserMenu() ;
        if (menu == 0) 
            break ;
        if (menu == 1 || menu ==3 || menu == 4)
        {
            if (count == 0) 
            {
                printf("No user stored, need to add user\n") ;
                continue ;
            }
        }
            
        if (menu == 1)
        {
            //데이터 조회 (리스트로)
            if (count > 0)
                listUser(user, index) ;
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
            user[index] = (User *)malloc(sizeof(User)) ;
            count += insertUser(user[index++]) ;
        }
        else if (menu == 3)
        {
            int no = selectUserDataNo(user, index) ;
            if (no == 0)
            {
                printf("=> 취소됨!\n") ;
                continue ;
            }
            updateUser(user[no - 1]) ;
        }
        else if (menu == 4)
        {
            int no = selectUserDataNo(user, index) ;
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
                if(user[no - 1])
                    free(user[no - 1]) ;
                user[no - 1] = NULL ;
                count-- ;
            }
        }
    }
    printf("User 설정 종료됨!\n") ;

    return count ;
}
