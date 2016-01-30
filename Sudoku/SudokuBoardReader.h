#ifndef SUDOKUBOARDREADER_H
#define SUDOKUBOARDREADER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <sstream>

#include "SudokuFile.h"

using namespace std;

class SudokuBoardReader
{
private:
	void setSudokuFileParameters(SudokuFile * sf, string params[]);
	void parseLineOfSudokuBoard(SudokuFile * sf, string values[], int rowNumber);
	
public:
	SudokuFile * readFile(string filePath);
};


#endif