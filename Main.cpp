#include <iostream>
#include <string>
#include <stdexcept>
#include "mat.hpp"

using namespace std;
using namespace ariel;

int main() {
    cout << mat(3, 5, '$', '-') << endl; // Should be able to run
    for (int i = 1; i <= 10; i++) {
        cout << endl;
    }
    try {
        cout << mat(0, 1, '+', '-') << endl; //Shouldn't be able to run
    }
    catch (exception &e) {
	 	cout << "Exception has been caught: " << e.what() << endl; // Should print "The parameter 'columns' is invalid"
    }
    for (int i = 1; i <= 10; i++) {
        cout << endl;
    }
    cout << mat(9, 7, '!', '`') << endl; // Should be able to run
    for (int i = 1; i <= 10; i++) {
        cout << endl;
    }
    try {
        cout << mat(1, 0, '+', '-') << endl; //Shouldn't be able to run
    }
    catch (exception &e) {
	 	cout << "Exception has been caught: " << e.what() << endl; // Should print "The parameter 'rows' is invalid"
    }
    for (int i = 1; i <= 10; i++) {
        cout << endl;
    }
    cout << mat(79, 83, ':', ':') << endl; // Should be able to run
    for (int i = 1; i <= 10; i++) {
        cout << endl;
    }
    try {
        cout << mat(1, 1, ' ', '-') << endl; //Shouldn't be able to run
    }
    catch (exception &e) {
	 	cout << "Exception has been caught: " << e.what() << endl; // Should print "The first sign parameter is invalid" 
    }
    for (int i = 1; i <= 10; i++) {
        cout << endl;
    }
    cout << mat(1, 157, '&', '*') << endl; // Should be able to run
    for (int i = 1; i <= 10; i++) {
        cout << endl;
    }
    try {
        cout << mat(1, 1, '+', ' ') << endl; //Shouldn't be able to run
    }
    catch (exception &e) {
	 	cout << "Exception has been caught: " << e.what() << endl; // Should print "The second sign parameter is invalid"
    }
    return 0;
}

