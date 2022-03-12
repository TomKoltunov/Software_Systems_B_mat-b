#include <iostream>
#include <string>

using namespace std;

namespace ariel {
    std::string mat(int, int, char, char) {
        return " ";
    }

using namespace ariel;

CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces     ("@@@@@@@@@\n"
													 "@-------@\n"
													 "@-@@@@@-@\n"
													 "@-@---@-@\n"
													 "@-@@@@@-@\n"
													 "@-------@\n"
													 "@@@@@@@@@"));

CHECK(nospaces(mat(9, 9, '@', '-')) == nospaces     ("@@@@@@@@@\n"
												 	 "@-------@\n"
												 	 "@-@@@@@-@\n"
												 	 "@-@---@-@\n"
												 	 "@-@-@-@-@\n"
												 	 "@-@---@-@\n"
												 	 "@-@@@@@-@\n"
												 	 "@-------@\n"
												 	 "@@@@@@@@@"));

													 "$$$$$$$$$$$$$$$$$$$$$\n"				
													 "$-------------------$\n"				
													 "$-$$$$$$$$$$$$$$$$$-$\n"				
													 "$-$---------------$-$\n"			
													 "$-$-$$$$$$$$$$$$$-$-$\n"				
													 "$-$-$-----------$-$-$\n"				
													 "$-$-$$$$$$$$$$$$$-$-$\n"				
													 "$-$---------------$-$\n"				
													 "$-$$$$$$$$$$$$$$$$$-$\n"
													 "$-------------------$\n"
													 "$$$$$$$$$$$$$$$$$$$$$"

"$$$$$$$$$$$$$$$$$$$$$	$-------------------$	$-$$$$$$$$$$$$$$$$$-$	$-$---------------$-$	$-$-$$$$$$$$$$$$$-$-$	$-$-$-----------$-$-$"

/*
*/
string mat(int columns, int rows, char a, char b) {
    char rug[columns][rows];
	int columnsUpperHalf = (columns / 2) + 1;
	int rowsUpperHalf = (rows / 2) + 1;
	int currentColumns = columns; 
	int currentRows = rows;
	char currentRingChar = 'a';
	int index = 0;
	while (currentColumns > columnsUpperHalf && currentRows > rowsUpperHalf) { // This loop will run Iteratively as long as the matrix "rug" is able to contain another ring
		for (int i = index; i < currentColumns; i++) { // This loop fills the upper and lower lines in the current ring
			rug[index][i] = currentRingChar;
			rug[currentRows - 1][i] = currentRingChar;
		}
		for (i = index + 1; i < currentRows - 1; i++) { // This loop fills the left and right lines in the current ring
			rug[i][index] = currentRingChar;	
			rug[i][currentColumns - 1] = currentRingChar;
		}
		if (currentRingChar == 'a') {
			currentRingChar == 'b'; // switching ring characters from 'a' to 'b'
		} 
		else {	// currentRing == 'b'
			currentRingChar == 'a'; // switching ring characters from 'b' to 'a'
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
		for (i = index; i < currentRows; i++) {
			rug[i][index] = currentRingChar; 	
		}
	}
}

string fromMatrixToString(mat[columns][rows]) {
	string answer = "";
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			
		}
	}
}

}