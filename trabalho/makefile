all: compila
compila: main.o tad.o 
	gcc main.o tad.o -o prog
main.o: main.c
	gcc -c main.c
tad.o: tad.h
	gcc -c tad.c
clean:
	rm main.o tad.o prog
