user : user.h user.c
	gcc -o user user.c

penalty : penalty.c penalty.h
	gcc -0 penalty penalty.c

ladder : laddergame.c laddergame.h
	gcc -o ladder laddergame.c

main: main.c laddergame.c user.c penalty.c
	gcc -o main mian.c laddergame.c user.c penalty.c




clean:
	rm -rf user penalty main