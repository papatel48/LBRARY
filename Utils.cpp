/*
MILESTONE 5
Name:PRANAV PATEL
Seneca Email: papatel48@myseneca.ca
Student ID: 119954212

Date: 07/08/2022
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
#include <iostream>
using namespace std;
#include "Utils.h"
namespace sdds {
	unsigned int getIntInRange(int min, int max) {
		int P;
		cin >> P;
		if (cin.fail() || P<min || P>max) {
			cin.clear();
			char ch;
			while (cin.get(ch) && ch != '\n') {
				;
			}
			cout << "Invalid Selection, try again: ";
			return getIntInRange(min, max);
		}
		else {
			return P;
		}
	}


}