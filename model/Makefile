
CC=g++

%.o: %.c
	${CC} -c $< -o $@

main: item.o book.o main.cpp
	${CC} item.o book.o main.cpp -o $@

prestito: item.o book.o main_p.cpp
	${CC} item.o book.o main_p.cpp -o $@

clear:
	rm *.o
