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
	static void setSudokuFileParameters(SudokuFile * sf, vector<string> params);
	static void parseLineOfSudokuBoard(SudokuFile * sf, vector<string> values, int rowNumber);
	
public:
	static SudokuFile * readFile(string filePath);
};


#endif