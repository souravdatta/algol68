all : atyper.o
	$(CC) -o atyper -O2 atyper.o

atyper.o : atyper.c
	$(CC) -o atyper.o -c atyper.c

install : all
	install atyper /usr/local/bin


.PHONY:
clean :
	rm -fr *~ atyper *.o
