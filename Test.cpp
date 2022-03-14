/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: Tom Koltunov
 * 
 * Date: 2021-03-08
 */

#include "doctest.h"
#include "mat.hpp"
using namespace ariel; // The declaration of this namespace appears in the header file "mat.hpp" which I have created

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good input") {

	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces ("@@@@@@@@@\n"
													 "@-------@\n"
													 "@-@@@@@-@\n"
													 "@-@---@-@\n"
													 "@-@@@@@-@\n"
													 "@-------@\n"
													 "@@@@@@@@@"));

	/* Add more test here */

	CHECK(nospaces(mat(9, 7, '-', '@')) == nospaces ("---------\n"
													 "-@@@@@@@-\n"
													 "-@-----@-\n"
													 "-@-@@@-@-\n"
													 "-@-----@-\n"
													 "-@@@@@@@-\n"
													 "---------"));
	
}

TEST_CASE("Good input - the number of rows and the number of columns are equal to 1") {

	CHECK(nospaces(mat(1, 1, '$', '$')) == nospaces ("$"));

	CHECK(nospaces(mat(1, 1, '!', '?')) == nospaces ("!"));

	CHECK(nospaces(mat(1, 1, '?', '!')) == nospaces ("?"));

}

TEST_CASE("Good input - the number of rows and the number of columns are equal and greater than 1") {

	CHECK(nospaces(mat(3, 3, '*', '*')) == nospaces("***\n"
									  				"***\n"
									 				"***"));

}

TEST_CASE("Good input - the number of columns is greater than the number of rows") {

	CHECK(nospaces(mat(7, 5, '(', '(')) == nospaces("(((((((\n"
								 				    "(((((((\n"
								  					"(((((((\n"
								  					"(((((((\n"
								  					"((((((("));	

}
	
TEST_CASE("Good input - the number of columns is smaller than the number of rows") {

	CHECK(nospaces(mat(3, 7, '&', '&')) == nospaces("&&&\n"
								 					"&&&\n"
								  					"&&&\n"
								  					"&&&\n"
								  					"&&&\n"
													"&&&\n"
													"&&&"));

}
	
TEST_CASE("Good input - the mat consists of 3 rings of the first sign and 2 rings of the second sign") {

	CHECK(nospaces(mat(9, 9, '@', '-')) == nospaces ("@@@@@@@@@\n"
												 	 "@-------@\n"
												 	 "@-@@@@@-@\n"
												 	 "@-@---@-@\n"
												 	 "@-@-@-@-@\n"
												 	 "@-@---@-@\n"
												 	 "@-@@@@@-@\n"
												 	 "@-------@\n"
												 	 "@@@@@@@@@"));

}

TEST_CASE("Good input - the mat consists of 4 rings of the first sign and 3 rings of the second sign") {

	CHECK(nospaces(mat(13, 13, '&', '+')) == nospaces ("&&&&&&&&&&&&&\n"
												   	   "&+++++++++++&\n"
												   	   "&+&&&&&&&&&+&\n"
												   	   "&+&+++++++&+&\n"
												   	   "&+&+&&&&&+&+&\n"
												   	   "&+&+&+++&+&+&\n"
												   	   "&+&+&+&+&+&+&\n"
												   	   "&+&+&+++&+&+&\n"
												   	   "&+&+&&&&&+&+&\n"
												   	   "&+&+++++++&+&\n"
												       "&+&&&&&&&&&+&\n"
													   "&+++++++++++&\n"
												   	   "&&&&&&&&&&&&&"));

}

TEST_CASE("Good input - the number of columns isn't equal to the number of rows and both signs creates the same number of rings") {
		
	/*The number of columns is greater than the number of rows*/

	CHECK(nospaces(mat(5, 3, '/', '*')) == nospaces ("/////\n"
												     "/***/\n"
												     "/////"));

	/*The number of columns is smaller than the number of rows*/

	CHECK(nospaces(mat(3, 7, '/', '*')) == nospaces ("///\n"
												     "/*/\n"
												 	 "/*/\n"
												 	 "/*/\n"
												 	 "/*/\n"
												 	 "/*/\n"
												 	 "///"));

}

TEST_CASE("Bad input") {

    CHECK_THROWS(mat(10, 5, '$', '%'));

	CHECK_THROWS(nospaces(mat(1, 1, '!', ' '))); // ' ' is invalid sign

	CHECK_THROWS(nospaces(mat(1, 1, ' ', '?'))); // ' ' is invalid sign

}

    /* Add more test here */

/*
Notes: It's impossible to make a design of a mat as described if one or more of mat's dimensions is even. 
       Hence, all those cases should fail. Also Both the number of rows and the numbers of columns should be positive. 
*/			

TEST_CASE("Bad input - both the number of rows and the number of columns is 0") {

	CHECK_THROWS(mat(0, 0, '+', '*')); // Both 'char' parameters aren't ' '
  
	CHECK_THROWS(mat(0, 0, '+', ' ')); // The left 'char' parameter is ' '

	CHECK_THROWS(mat(0, 0, ' ', '*')); // The right 'char' parameter is ' '

	CHECK_THROWS(mat(0, 0, ' ', ' ')); // Both 'char' parameters are ' '

}

TEST_CASE("Bad input - The number of columns is 0 and the number of rows isn't") {

	/*The number of rows is even and positive*/

	CHECK_THROWS(mat(0, 2, '^', '&'));

	/*The number of rows is even and negative*/

	CHECK_THROWS(mat(0, -2, '^', '&'));

	/*The number of rows is odd and positive*/

	CHECK_THROWS(mat(0, 1, '$', 'S'));

	/*The number of rows is odd and negative*/

	CHECK_THROWS(mat(0, -1, '$', 'S'));
}

TEST_CASE("Bad input - The number of rows is 0 and the number of columns isn't") {

	/*The number of columns is even and positive*/

	CHECK_THROWS(mat(2, 0, 'S', '$'));

	/*The number of columns is even and negative*/

	CHECK_THROWS(mat(-2, 0, 'S', '$'));

	/*The number of columns is odd and positive*/

	CHECK_THROWS(mat(1, 0, '^', '&'));

	/*The number of columns is odd and negative*/

	CHECK_THROWS(mat(-1, 0, '^', '&'));
}

TEST_CASE("Bad input - both the number of rows is equal to the number of columns and both are even") {

	CHECK_THROWS(mat(2, 2, '/', '/'));

}

TEST_CASE("Bad input - the number of rows isn't equal to the number of columns but both are even") {

	CHECK_THROWS(mat(4, 6, '[', ']'));

}

TEST_CASE("Bad input - the number of columns is even and the number of rows is odd") {

	/*Both the number of columns and rows are positive*/

	CHECK_THROWS(mat(4, 7, '[', ']'));

	/*The number of columns is negative and the number of rows is positive*/

	CHECK_THROWS(mat(-4, 7, '[', ']'));

	/*The number of columns is positive and the number of rows is negative*/

	CHECK_THROWS(mat(4, -7, '[', ']'));

}

TEST_CASE("Bad input - the number of columns is odd and the number of rows is even") {

	/*Both the number of columns and rows are positive*/

	CHECK_THROWS(mat(5, 6, '[', ']'));

	/*The number of columns is negative and the number of rows is positive*/

	CHECK_THROWS(mat(-5, 6, '[', ']'));

	/*The number of columns is positive and the number of rows is negative*/

	CHECK_THROWS(mat(5, -6, '[', ']'));

}
