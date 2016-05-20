all: slrk
CFLAGS=-Wall -g
slrk: slrk.c
        gcc -o slrk slrk.c -l X11
clean:
        rm -f slrk
