CC = g++
CFLAGS = -ggdb -std=c++0x -I. 
OBJECTS = Odometer.o SudokuBoardGenerator.o SudokuBoardReader.o SudokuFile.o SudokuFileExample.o
PROGRAM = SudokuDisplayExample

default: $(OBJECTS) 
	$(CC) $(CFLAGS) -o $(PROGRAM) $(OBJECTS) 
	
Odometer.o : Odometer.cpp Odometer.h
	$(CC) $(CFLAGS) -c Odometer.cpp
	
SudokuBoardGenerator.o : SudokuBoardGenerator.cpp SudokuBoardGenerator.h SudokuFile.h
	$(CC) $(CFLAGS) -c SudokuBoardGenerator.cpp
	
SudokuBoardReader.o : SudokuBoardReader.cpp SudokuBoardReader.h SudokuFile.h
	$(CC) $(CFLAGS) -c SudokuBoardReader.cpp

SudokuFile.o : SudokuFile.cpp SudokuFile.h Odometer.h
	$(CC) $(CFLAGS) -c SudokuFile.cpp
	
SudokuFileExample.o : SudokuFileExample.cpp SudokuBoardGenerator.h SudokuBoardReader.h SudokuFile.h
	$(CC) $(CFLAGS) -c SudokuFileExample.cpp
	
clean:
	rm -f $(OBJECTS) $(PROGRAM) 
