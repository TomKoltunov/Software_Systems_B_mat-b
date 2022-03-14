#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include "mat.hpp"
const int SMALL = 33;
const int BIG = 127;

using namespace std;

	/*
	The sub-function "isValidSize" receives an integer called "size" which represents the length of a row or a column of the matrix 
	in funtion "mat". The function returns 'false' only in case "size" is even or negative. Else the function returns 'true'.
	*/
	bool isValidSize(int size) {
		bool ans = true;
		if (size % 2 == 0 || size < 0) {
			ans = false;
		}
		return ans;
	}

	/*
	The sub-function "isValidSymbol" receives a character named 'c' which represents one of the symbols which assembles the matrix 
	in funtion "mat". The function returns 'false' only in case 'c' is the char ' ' or '\n' or '\t' or '\r' or the ascii number of 'c' is
	less than 33 or its bigger (or equals) 127.
	 Else the function returns 'true'.
	*/
	bool isValidSymbol(char c) {
		bool ans = true;
		if (c == ' ' || c == '\n' || c == '\t' || c == '\r' || c < SMALL || c >= BIG) {
			ans = false;
		} 
		return ans;
	}


namespace ariel {

	/*
	The function "mat" receives two integers called "columns" and "rows" which represents rug's sizes - "columns" is the width and "rows" is the length.
	It also receives two chars named 'a' and 'b' which represents the signs from which the rug will be "made of".
	"mat" creates a 'matrix' form of the rug and returns the 'string' form of it.
	"mat" uses the sub-functions called "isValidSize" and "isValidSymbol" which appear above it.
	*/
	string mat(int columns, int rows, char a, char b) {
		if (!isValidSize(columns)) {
			throw invalid_argument{"The parameter 'columns' is invalid"};
		}
		if (!isValidSize(rows)) {
			throw invalid_argument{"The parameter 'rows' is invalid"};
		}
		if (!isValidSymbol(a)) {
			throw invalid_argument{"The first sign parameter is invalid"};
		}
		if (!isValidSymbol(b)) {
			throw invalid_argument{"The second sign parameter is invalid"};
		}
    	vector<vector<char>> rug(rows, vector<char>(columns));
		int columnsUpperHalf = (columns / 2) + 1;
		int rowsUpperHalf = (rows / 2) + 1;
		int currentColumns = columns;
		int currentRows = rows;
		char currentRingChar = a;
		int index = 0;
		while (currentColumns > columnsUpperHalf && currentRows > rowsUpperHalf) { // This loop will run Iteratively as long as the matrix "rug" is able to contain another ring
			for (int i = index; i < currentColumns; i++) { // This loop fills the upper and lower lines in the current ring
				rug[index][i] = currentRingChar;
				rug[currentRows - 1][i] = currentRingChar;
			}
			for (int i = index + 1; i < currentRows - 1; i++) { // This loop fills the left and right lines in the current ring
				rug[i][index] = currentRingChar;	
				rug[i][currentColumns - 1] = currentRingChar;
			}
			if (currentRingChar == a) {
				currentRingChar = b; // switching ring characters from 'a' to 'b'
			}	 
			else {	// currentRing == b
				currentRingChar = a; // switching ring characters from 'b' to 'a'
			}	
			currentColumns--;
			currentRows--;
			index++;
		}
		if (columns >= rows) { // This condition takes care for the cases:
						   	   // 1) columns > rows: It means that the only thing that left to fill in the rug is the middle horizontal line
						       // 2) columns = rows: It means that the only thing that left to fill in the rug is the center point (center char)
			for (int i = index; i < currentColumns; i++) { 
				rug[index][i] = currentRingChar; 
			}
		}
		else { // columns < rows: It means that the only thing that left to fill in the rug is the middle vertical line
			for (int i = index; i < currentRows; i++) {
				rug[i][index] = currentRingChar;
			}
		}
		string answer;
		for (int i = 0; i < rows; i++) { // This loop transforms the matrix to 'string' form
			for (int j = 0; j < columns; j++) {
				answer += rug[i][j];
			}
			if (i != rows - 1) {
				answer += "\n";
			}
		}
		return answer;
    }
}
