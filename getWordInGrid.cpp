#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];

bool readInGrid(string filename, int& rows, int& cols);
string getWordInGrid(int startRow, int startCol, int dir, int len, int numRows, int numCols);

int main() {
    int rows, cols;
    bool result = readInGrid("5x8.grid.txt", rows, cols);
    if (!result) {
        cout << "Error reading in file!" << endl;
        return 1;
    }
    cout << endl;
    for (int i = 0; i < 8; i++) {
        cout << i << ": " << getWordInGrid(2, 2, i, 10, rows, cols) << endl;
    }
    //end of main
    return 0;
}

/** This function will read in a grid file into a global grid[][] array.  
 * It uses C++ file streams, and thus requires the the <fstream> #include header.
 * @return true or false, depending on whether the file was successfully opened.
 * @param filename The file name to read in
 * @param rows The number of rows as specified in the input file; as this is a reference, it is set by the function.
 * @param cols The number of columns as specified in the input file; as this is a reference, it is set by the function.
 */
bool readInGrid(string filename, int& rows, int& cols) {
    ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }
    file >> rows;
    cout << "There are " << rows << " rows." << endl;
    file >> cols;
    cout << "There are " << cols << " cols." << endl;
    string data;
    file >> data;
    file.close();
    int pos = 0;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            grid[r][c] = data[pos++];
            cout << grid[r][c];
        }
        cout << endl;
    }
    return true;
}

/** This function will retrieve a word in a grid of letters in a given
 * direction. If the end of the grid is encountered before the length
 * of the desired string is reached, then a shorter string will be
 * returned. The data is retrieved from a global char grid[][]
 * array, which is assumed to be defined (and in scope).  NOTE: The
 * return value is a static string variable (for efficiency
 * reasons), so a successive return value will overwrite a previous
 * return value.
 *
 * @return A STATIC string containing the letters in the provided direction.
 * @param startRow The starting (row,col) position to find the word.
 * @param startCol The starting (row,col) position to find the word.
 * @param dir The direction to move: 0 is north (upwards), 1 is northeast, and it rotates around clockwise until it reaches 7 for northwest.
 * @param len The desired length of the string to return (assuming
 *            the edge of the grid is not reached--if the edge of the
 *            grid is reached, it will return as many characters as
 *            possible up to the edge of the grid, so the returned
 *            string may not have the same length as this parameter
 *            indicates).
 * @param numRows The number of rows in the global char grid[][] array.
 * @param numCols The number of columns in the global char grid[][]array.
 */
string getWordInGrid (int startRow, int startCol, int dir, int len, int numRows, int numCols) {
    static string output;
    output.clear(); 
    output.reserve(256); 
    int r = startRow, c = startCol;
    for (int i = 0; i < len; i++) {
        if (c >= numCols || r >= numRows || r < 0 || c < 0) {
            break;
        }
        output += grid[r][c];
        switch (dir) {
            case 0:
                r--;
                break; //north
            case 1:
                r--;
                c++;
                break; //north-east
            case 2:
                c++;
                break; //east
            case 3:
                r++;
                c++;
                break; //south-east
            case 4:
                r++;
                break; //south
            case 5:
                r++;
                c--;
                break; //south-west
            case 6:
                c--;
                break; //west
            case 7:
                r--;
                c--;
                break; //north-west
        }
    }
    return output;
}