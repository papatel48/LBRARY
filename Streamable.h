/*
MILESTONE 5
Name:PRANAV PATEL
Seneca Email: papatel48@myseneca.ca
Student ID: 119954212

Date: 07/08/2022
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
#ifndef SDDS_STREAMABLE_H_
#define SDDS_STREAMABLE_H_
#include<iostream>
using namespace std;
namespace sdds {
	class Streamable{
	public:
		virtual ostream& write(ostream&)const=0;
		virtual istream& read(istream&) = 0;
		virtual bool conIO(ios&)const = 0;
		virtual operator bool()const = 0;
		~Streamable(){};
	};


}
#endif