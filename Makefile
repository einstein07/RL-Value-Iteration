CC=g++
CFLAGS=-std=c++11
SOURCES=main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=program

all:$(EXECUTABLE)
	@echo Make has finished.

$(EXECUTABLE):$(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) -c $*.cpp

clean:
	$(RM) *.o *~$(EXECUTABLE)
