#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "hashTable.h"
#include "timer.h"
using namespace std;

//Let grid = a 2-D array of characters with a maximum capacity of 500x500
char grid[500][500];

//Reads the gridFile into the grid[][] array; returns true if the gridFile is opened successfully, and false if otherwise.
bool readInGrid(string gridFile, int& rows, int& columns) 
{
    //Let gridStream = the gridFile's corresponding input stream
    ifstream gridStream(gridFile);

    //If the gridFile is not open (in the case of an error)
    if (gridStream.is_open() == false) 
    {
    	//Return false
        return false;
    }

    //Read the number of rows and columns in the gridFile
    gridStream >> rows;
    gridStream >> columns;

    //Let data = the gridFile's string of characters
    string data;

    //Read the gridFile's data
    gridStream >> data;

    //Close the gridStream
    gridStream.close();

    //Let position = the current position within the data
    int position = 0;

    //For each row of the grid
    for (int i = 0; i < rows; i++) 
    {
    	//For each column of the grid
        for (int j = 0; j < columns; j++) 
        {
        	//Let the entry in the i'th row and j'th column of the grid = the next position within the data
            grid[i][j] = data[position++];
        }
    }

    //Return true
    return true;
}

//Retrieves a word in a given direction from the grid. If the end of the grid is encountered before the length of the desired string is reached, then a shorter string will be returned.
string getWordInGrid(int startRow, int startColumn, int direction, int length, int numRows, int numColumns) 
{
    //Let word = the string to be returned that contains the word in the provided direction
    static string word;

    //Clear the word
    word.clear();

    //Set the capacity of the word = 256
    word.reserve(256);

    //Let i and j = the current row and column of the output array, respectively
    int i = startRow, j = startColumn;

    //For each character of the desired output
    for (int l = 0; l < length; l++) 
    {
        //If the current row or column is out of bounds
        if (j >= numColumns || i >= numRows || j < 0 || i < 0) 
        {
        	//Break the for loop
            break;
        }

        //Set the next character in the output array to the next letter in the grid
        word += grid[i][j];

        //Move in the direction specified by the parameter (assuming grid[0][0] is in the upper-left)
        switch (direction) 
        { 
            case 0:
                i--;
                break; //North
            case 1:
                i--;
                j++;
                break; //North-east
            case 2:
                j++;
                break; //East
            case 3:
                i++;
                j++;
                break; //South-east
            case 4:
                i++;
                break; //South
            case 5:
                i++;
                j--;
                break; //South-west
            case 6:
                j--;
                break; //West
            case 7:
                i--;
                j--;
                break; //North-west
        }
    }

    //Return the output
    return word;
}

//Reads the dictionaryFile and stores it's words in a hashTable to be returned.
hashTable readDictionary(string dictionaryFile)
{
	//Let dictionaryStream = the dictionaryFile's corresponding input stream
	ifstream dictionaryStream(dictionaryFile);

	//Let dictionarySize = the number of words in the dictionaryFile
	int dictionarySize = 0;

	//If the dictionaryFile has been opened without error
	if(dictionaryStream.fail() == false)
	{
		//Let dummy = the current string extracted from the dictionaryFile
		string dummy;

		//While the end of the dictionaryFile has not been reached
		while(getline(dictionaryStream, dummy))
		{
			//Increment the dictionarySize by 1
			dictionarySize++;
		}

		//Close the dictionaryStream
		dictionaryStream.close();
	}
	else
	{
		//Print an error message
		cout << "Error: file does not exist" << endl;

		//Close the dictionaryStream
		dictionaryStream.close();

		//Exit the program
		exit(-1);
	}

	//Let table = the hashTable to be returned
	hashTable table(dictionarySize);

	//Open the dictionaryStream
	dictionaryStream.open(dictionaryFile);

	//Let line = the current string extracted from the dictionaryFile
	string line;

	//While the end of the dictionaryFile has not been reached
	while(getline(dictionaryStream, line))
	{
		//If the line has a length of 3 or more characters
		if(line.length() >= 3)
		{
			//Insert the line into the table
			table.insert(line);
		}
	}

	//Return the table 
	return table;
}

//Driver
int main(int argc, char* argv[])
{
	//Let dictionaryFile = the first command line parameter
	string dictionaryFile = argv[1];

	//Let table = the dictionary's corresponding hashTable
	hashTable table = readDictionary(dictionaryFile);

	//Let gridFile = the second command line parameter
	string gridFile = argv[2];

	//Let rows and columns = the number of rows and columns in the grid, respectively
	int rows, columns;

	//If the gridFile has been opened without error
	if(readInGrid(gridFile, rows, columns) == true)
	{
		//Let wordsFound = the number of words found in the grid
		int wordsFound = 0; 

		//Let direction = the direction of a word in the grid
		string direction; 

		//Create and start a timer
		timer puzzleTimer; 
		puzzleTimer.start();

		//For each row of the grid
		for(int i = 0; i < rows; i++)
		{
			//For each column of the grid
			for(int j = 0; j < columns; j++)
			{
				//For each possible direction
				for(int d = 0; d < 8; d++)
				{
					//For each possible word length
					for(int l = 3; l < 23; l++)
					{
						//Let word = a word in the grid with direction d
						string word = getWordInGrid(i, j, d, l, rows, columns);

						//If the word has length l
						if(word.length() == l)
						{
							//If the word is a key in the table
							if(table.search(word) == true)
							{
								//Increment wordsFound by 1
								wordsFound++;

								//If d = 0
								if(d == 0)
								{
									//Set the direction = N
									direction = "N ";
								}

								//Else if d = 1
								else if(d == 1)
								{
									//Set the direction = NE
									direction = "NE";
								}

								//Else if d = 2
								else if(d == 2)
								{
									//Set the direction = E
									direction = "E ";
								}

								//Else if d = 3
								else if(d == 3)
								{
									//Set the direction = SE
									direction = "SE";
								}

								//Else if d = 4
								else if(d == 4)
								{
									//Set the direction = S
									direction = "S ";
								}

								//Else if d = 5
								else if(d == 5)
								{
									//Set the direction = SW
									direction = "SW";
								}

								//Else if d = 6
								else if(d == 6)
								{
									//Set the direction = W
									direction = "W ";
								}

								//Else if d = 7
								else if(d == 7)
								{
									//Set the direction = NW
									direction = "NW";
								}

								cout << direction << "(" << i << "," << j << "): \t" << word << endl;
							}
						}
					}
				}
			}
		}
//j
		//Stop the puzzleTimer
		puzzleTimer.stop();

		//Let time = the time elapsed during the program's execution 
		//double time = puzzleTimer.getTime();

		//Print the number of words found
		cout << wordsFound << " words found" << endl;

		//Print the time elapsed during the program's execution 
		//cout << "Found " << wordsFound <<  " words in "<< time << " seconds" << endl;
		cout << 1000 * (int)puzzleTimer.getTime() << endl;
	}
	else
	{
		//Print an error message
		cout << "Error: the gridFile was not opened" << endl;

		//Return 1
		return 1;
	}

	//End of main
	return 0;
}