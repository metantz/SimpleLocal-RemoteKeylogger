slrk: slrk.o devh.o 
	gcc -Wall -o slrk slrk.o devh.o -l X11
slrk.o: slrk.c main.h
	gcc -c slrk.c
devh.o: devh.c devh.h
	gcc -c devh.c
clean:
	rm -f slrk slrk.o devh.o



