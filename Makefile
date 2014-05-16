CC=gcc
CFLAGS=-Wno-deprecated-declarations -O3
SRC=libbmpread/bmpread.c
all:
	rm -f snowman
	$(CC) -o snowman snowman.c $(SRC) $(CFLAGS) -framework GLUT -framework OpenGL

test:
	rm -f snowman
	$(CC) -o snowman snowman.c $(SRC) $(CFLAGS) -framework GLUT -framework OpenGL
	./snowman
	rm -f snowman

