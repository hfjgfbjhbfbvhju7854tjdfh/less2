
all : main.c
	gcc main.c -o  serv

clean :
	rm -rf serv 
