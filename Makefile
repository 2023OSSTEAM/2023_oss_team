# user : user.h user.c
# 	gcc -o user user.c

# penalty : penalty.c penalty.h
# 	gcc -0 penalty penalty.c

# ladder : laddergame.c laddergame.h
# 	gcc -o ladder laddergame.c

all: main.c laddergame.c user.c penalty.c game.c
	gcc -o main mian.c laddergame.c user.c penalty.c game.c

clean:
	rm -rf main