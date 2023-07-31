FLAGS = -g -Wall -Werror

connectn.out: main.o connectn.o board.o win.o input_validation.o
	gcc $(FLAGS) main.o connectn.o board.o win.o input_validation.o -o connectn.out -fsanitize=address

main.o: main.c connectn.h
	gcc $(FLAGS) -c main.c

connectn.o: connectn.c connectn.h win.h input_validation.h
	gcc $(FLAGS) -c connectn.c

board.o: board.c board.h
	gcc $(FLAGS) -c board.c

win.o: win.c win.h input_validation.h board.h
	gcc $(FLAGS) -c win.c

input_validation.o: input_validation.c
	gcc $(FLAGS) -c input_validation.c

clean:
	rm -rf *.o *.out