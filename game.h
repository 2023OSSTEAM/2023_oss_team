
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
 
#define RED 12
#define WHITE 15

void textcolor(int color_number) ; // 텍스트 칼라 출력
void gotoxy(int x, int y) ; // 좌표 이동
int baserand(int x, int y) ; // 랜덤 범위 지정
 
void VerticalSet(int * MAP[][], int num_of_users) ;
void HorizonSet(int * MAP[][], int num_of_users) ;
void PrintLine(int * MAP[][], int num_of_users) ;
void LadderStart( int * MAP[][], int select) ;
