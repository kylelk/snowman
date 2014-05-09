CC=gcc
CFLAGS=-Wno-deprecated-declarations -O3
all:
	rm -f snowman
	$(CC) -o snowman snowman.c $(CFLAGS) -framework GLUT -framework OpenGL

test:
	rm -f snowman
	$(CC) -o snowman snowman.c $(CFLAGS) -framework GLUT -framework OpenGL
	./snowman
	rm -f snowman

