#include "SudokuFile.h"

SudokuFile::SudokuFile() {}
SudokuFile::SudokuFile(int N, int p, int q, int ** board)
{
	if (N != p * q || N < 1)
	{
		cout << "Board parameters invalid. Creating a 9x9 sudoku file instead.";
		setP(3);
		setQ(3);
		setN(9);
		setBoard(allocateBoard(9));
	}
	else
	{
		setP(p);
		setQ(q);
		setN(N);
		setBoard(board == NULL ? allocateBoard(9) : board);
	}
}

SudokuFile::SudokuFile(int N, int p, int q)
{
	SudokuFile(N, p, q, NULL);
}

SudokuFile::~SudokuFile()
{
	for (int i = 0; i < N; ++i)
		delete[] board[i];
	delete board;
}

int ** SudokuFile::allocateBoard(int N)
{
	int ** newBoard = new int*[N];
	for (int i = 0; i < 9; ++i)
		newBoard[i] = new int[N];
	return newBoard;
}

void SudokuFile::setP(int p)
{
	this->p = p;
}

void SudokuFile::setQ(int q)
{
	this->q = q;
}

void SudokuFile::setN(int N)
{
	this->N = N;
}

void SudokuFile::setBoard(int ** board)
{
	this->board = board;
}

int SudokuFile::getP() const
{
	return p;
}

int SudokuFile::getQ() const
{
	return q;
}

int SudokuFile::getN() const
{
	return N;
}

int** SudokuFile::getBoard() const
{
	return board;
}

string SudokuFile::toString() const
{
	string str = "N: "; // +N + "\tP: " + p + "\tQ: " + q + "\n";
	str += N;
	str += "\tP: ";
	str += p;
	str += "\tQ: ";
	str += q;
	str += "\n";

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			str += Odometer::intToOdometer(board[i][j]) + " ";
			if ((j + 1) % q == 0 && j != 0 && j != N - 1)
				str += "| ";
		}

		str += "\n";
		if ((i + 1) % p == 0 && i != 0 && i != N - 1)
		{
			for (int k = 0; k < N + p - 1; ++k)
				str += "- ";
			str += "\n";
		}
	}

	return str;
}