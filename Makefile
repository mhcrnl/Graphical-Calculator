try : cal.c
	gcc -Wall `pkg-config --cflags gtk+-3.0` -o try cal.c `pkg-config --libs gtk+-3.0` -lm
