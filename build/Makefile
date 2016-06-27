# Fixed -------------------------------------------------------------------------
CC = g++
ARGS = -std=c++11 -O2 -Wall -pedantic
TARGET = ../football
DEPS = -lSDL2 -lm -pthread
SRC = ./../src
HDR = ./../include

# Dynamic -----------------------------------------------------------------------
MAIN =  main.o
OBJS = 	Application.o					\
	Status.o


# Jobs --------------------------------------------------------------------------
debug: $(OBJS) $(MAIN)
	$(CC) -g $(ARGS) -o $(TARGET) $(OBJS) $(MAIN) $(DEPS)

release: $(OBJS) $(MAIN)
	$(CC) $(ARGS) -o $(TARGET) $(OBJS) $(MAIN) $(DEPS)

clean:
	rm $(OBJS) $(MAIN) $(TARGET)

# Objects -----------------------------------------------------------------------
main.o: $(OBJS)
	$(CC) $(ARGS) -c $(SRC)/main.cpp

Application.o: $(SRC)/Application.cpp $(HDR)/Application.h
	$(CC) $(ARGS) -c $(SRC)/Application.cpp

Status.o: $(SRC)/Status.cpp $(HDR)/Status.h
	$(CC) $(ARGS) -c $(SRC)/Status.cpp
