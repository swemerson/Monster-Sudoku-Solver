#include "SudokuBoardGenerator.h"
#include "SudokuBoardReader.h"
#include "SudokuFile.h"

int main() 
{
	int N = 16;
	int p = 4;
	int q = 4;
	int m = 25;

	SudokuFile * generatedSudokuFile = SudokuBoardGenerator::generateBoard(N, p, q, m);

	cout << "*****************************************" << endl;
	cout << "below is a randomly generated SudokuFile:" << endl;
	cout << "*****************************************" << endl;
	generatedSudokuFile->toString();
/*
	SudokuFile * SudokuFileFromFile = SudokuBoardReader::readFile("ExampleSudokuFiles/PH5.txt");

	cout << "*****************************************" << endl;
	cout << "below is a SudokuFile generated from a file:" << endl;
	cout << "*****************************************" << endl;
	SudokuFileFromFile->toString();*/
}
