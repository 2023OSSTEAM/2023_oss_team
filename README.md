주제 : 사다리타기 벌칙정하기 게임<br/>
 CRUD 기능, <br/>
데이터 파일 저장/읽어오기, <br/>
검색 메뉴(종료메뉴 제외) <br/>
등 (총 메뉴 8개 이상)<br/>

## <메뉴>
약 12개
-이름등록/이름삭제/이름read/이름 편집

-벌칙등록/벌칙삭제/벌칙read/벌칙 편집

-게임 실행, 직전게임결과 보기

-데이터 파일 저장/읽어오기 (게임결과-이름형식의 result.txt)

-검색메뉴(결과를 검색할 수 있도록- 날짜로 검색해서/20230504)<br/>


typedef struct{ <br/>
char name[20]; <br/>
char result[30];<br/>
}Human ; <br/><br/>

typedef struct{ <br/>
char pnaltyName[20]; <br/>
char period[10];<br/>
}Penalty ; <br/><br/>


## 10개 이상 함수 정의 및 개발 <br/>
insertUser() <br/>
deleteUser() <br/>
readUser() <br/> 
updateUser() <br/>

insertPenalty() <br/>
deletePenalty() <br/>
readPenalty() <br/> 
updatePenalty()  <br/>

runGame() <br/>
resultGame() <br/>

saveResult() <br/>
loadResult() <br/>

searchResult() <br/>
