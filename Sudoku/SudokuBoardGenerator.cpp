#include "SudokuBoardGenerator.h"

bool SudokuBoardGenerator::checkConstraints(int row, int col, int value, SudokuFile * sf, int ** board)
{
	if (checkRow(row, value, sf->getN(), board)
			&& checkColumn(col, value, sf->getN(), board)
			&& checkBox(row, col, value, sf->getP(), sf->getQ(), board))
		return true;

	return false;
}

SudokuFile * SudokuBoardGenerator::generateBoard(int N, int p, int q, int numAssignments)
{
	return generateBoard(N, p, q, numAssignments, 5000);
}

SudokuFile * SudokuBoardGenerator::generateBoard(int N, int p, int q, int numAssignments, long timeout)
{
	//given a SudokuFile with N, P, Q, creates a board with the given params
	//and assigns it to the board of the SudokuFile.
	//timeout represents the time in ms allowed to created the SudokuFile
	SudokuFile * sf = new SudokuFile(N, p, q);
	int ** tempBoard = SudokuFile::allocateBoard(sf->getN());
	if (numAssignments > sf->getN()*sf->getN())
	{
		cerr << "Number of assignments exceeds available spaces in board. Returning SudokuFile with an empty board\n";
		return sf;
	}
	
	srand(time(NULL));
	
	time_t startTime = time(NULL);
	time_t currentTime;
	for (int i = 0; i < numAssignments; i++)
	{
		int randomRow = rand() % sf->getN(); //0 to N-1
		int randomColumn = rand() % sf->getN(); //0 to N-1
		int randomAssignment = rand() % sf->getN() + 1; //1 to N
		if (tempBoard[randomRow][randomColumn] == 0 && checkConstraints(randomRow, randomColumn, randomAssignment, sf, tempBoard))
		{
			tempBoard[randomRow][randomColumn] = randomAssignment;
		}
		else
		{
			i--;
			currentTime = time(NULL);
			if (difftime(currentTime, startTime > timeout / 1000))
			{
				cout << "Timeout at " << i << " elements";
				tempBoard = SudokuFile::allocateBoard(sf->getN());
				break;
			}
		}
	}
	sf->setBoard(tempBoard);
	return sf;
}

bool SudokuBoardGenerator::checkRow(int row, int value, int N, int ** board)
{
	for (int i = 0; i < N; i++)
	{
		if (board[row][i] == value)
		{
			return false;
		}
	}
	return true;
}

bool SudokuBoardGenerator::checkColumn(int column, int value, int N, int ** board)
{
	for (int i = 0; i < N; i++)
	{
		if (board[i][column] == value)
		{
			return false;
		}
	}

	return true;
}

bool SudokuBoardGenerator::checkBox(int row, int column, int value, int p, int q, int ** board)
{
	int rDiv = row / p;
	int cDiv = column / q;
	for (int i = rDiv * p; i < (rDiv + 1) * p; i++)
	{
		for (int j = cDiv * q; j < (cDiv + 1) * q; j++)
		{
			try {
				if (board[i][j] == value)
				{
					return false;
				}
			}
			catch (out_of_range)
			{
				cerr << p << " " << q << '\n';
			}
		}
	}
	return true;
}