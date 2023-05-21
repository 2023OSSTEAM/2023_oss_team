
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
 
#define RED 12
#define WHITE 15

void textcolor(int color_number) ; // 텍스트 칼라 출력
void gotoxy(int x, int y) ; // 좌표 이동
int baserand(int x, int y) ; // 랜덤 범위 지정
 
void VerticalSet(int MAP[20][MAX]) ;
void HorizonSet(int MAP[20][MAX]) ;
void PrintLine(int MAP[20][MAX]) ;
void LadderStart( int MAP[20][MAX] , int Select ) ;

void laddergame(int * participants, int penalty) ;