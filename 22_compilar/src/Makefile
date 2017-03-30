TARGET = hola
CC = g++
IDIR = ../include
DDIR = ../dist

CFLAGS = -g -I$(IDIR)

DEPS = $(wildcard *.h)
OBJS = $(patsubst %.cpp, %.o, $(wildcard *.cpp))

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(CFLAGS) $^

%.o: %.cpp $(DEPS)
		$(CC) -c $<

.PHONY: clean dist

clean:
		$(RM) *.o

dist: clean
		mv $(TARGET) $(DDIR)
