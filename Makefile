CXX = gcc -std=c99 -lm
CFLAGS = -Wall

all: tsp_main.o
		$(CXX) $(CFLAGS) -o tsp_main tsp_main.o
clean:
		rm -f *.o tsp_main
