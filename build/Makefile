# Fixed -------------------------------------------------------------------------
CC = g++
ARGS = -std=c++11 -O2 -Wall -pedantic
TARGET = ../football
DEPS = -lSDL2 -lm
SRC = ./../src
HDR = ./../include

# Dynamic -----------------------------------------------------------------------
MAIN =  main.o
OBJS = 	Application.o					\
	Status.o 

# Defines -----------------------------------------------------------------------
DFND = -DSDL_ASSERT_LEVEL=2

# Jobs --------------------------------------------------------------------------
debug: $(OBJS) $(MAIN)
	$(CC) -g $(ARGS) $(DFND) -o $(TARGET) $(OBJS) $(MAIN) $(DEPS)

release: $(OBJS) $(MAIN)
	$(CC) $(ARGS) $(DFND) -o $(TARGET) $(OBJS) $(MAIN) $(DEPS)

clean:
	rm $(OBJS) $(MAIN) $(TARGET)

# Objects -----------------------------------------------------------------------
main.o: $(OBJS)
	$(CC) $(ARGS) $(DFND) -c $(SRC)/main.cpp

Application.o: $(SRC)/Application.cpp $(HDR)/Application.h
	$(CC) $(ARGS) $(DFND) -c $(SRC)/Application.cpp

Status.o: $(SRC)/Status.cpp $(HDR)/Status.h
	$(CC) $(ARGS) $(DFND) -c $(SRC)/Status.cpp
