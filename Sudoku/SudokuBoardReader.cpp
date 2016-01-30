#include "SudokuBoardReader.h"

void SudokuBoardReader::setSudokuFileParameters(SudokuFile * sf, vector<string> params)
{
	if (params.size() != 3)
	{
		cerr << "Params invalid in file\n";
		exit(1);
	}
	sf->setN(stoi(params[0]));
	sf->setP(stoi(params[1]));
	sf->setQ(stoi(params[2]));
}

void SudokuBoardReader::parseLineOfSudokuBoard(SudokuFile * sf, vector<string> values, int rowNumber)
{
	//writes values to the row set in param rowNumber
	if (sf->getBoard() == NULL)
	{
		sf->setBoard(SudokuFile::allocateBoard(sf->getN()));
	}
	int ** board = sf->getBoard();
	for (int i = 0; i < values.size(); i++)
	{
		board[rowNumber][i] = Odometer::odometerToInt(values[i]);
	}
}

SudokuFile * SudokuBoardReader::readFile(string filePath)
{
	//Get filePath. from path and filename. If path is null, 
	//it'll default to the current directory

	SudokuFile * sF = new SudokuFile();
	string line;
	int lineCounter = 0;
	ifstream myFile;
	try
	{
		myFile.open(filePath);
	}

	catch (ifstream::failure e)
	{
		cerr << "Could not open file: " << filePath << endl;
		exit(2);
	}

	while (getline(myFile, line))
	{
		
		vector<string> lineParts;
		istringstream iss(line);
		string word;
		while(iss >> word)
			lineParts.push_back(word);

		if (lineCounter == 0)
		{
			setSudokuFileParameters(sF, lineParts);//parameter line: contains p, q, N
		}

		else
		{
			parseLineOfSudokuBoard(sF, lineParts, lineCounter - 1);//obo due to parameters taking up first line
		}

		lineCounter++;
	}

	if (lineCounter == 0)
	{
		cerr << "Input file \"" + filePath + "\" was empty\n";
	}

	else if (lineCounter < sF->getN())
	{
		cerr << "Incomplete or Emtpy board for file " + filePath + ". Please be advised\n";
	}

	myFile.close();

	return sF;
}