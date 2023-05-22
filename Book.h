/*
MILESTONE 5
Name:PRANAV PATEL
Seneca Email: papatel48@myseneca.ca
Student ID: 119954212

Date: 07/08/2022
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
#ifndef SDDS_BOOK_H__
#define SDDS_BOOK_H__
#include"Publication.h"
#include <iostream>
namespace sdds {
	class Book :public Publication {
	private:
		char* Author_name ;
	public:	
		Book();
		Book(const Book& other);
		Book& operator = (const Book& other);
		char type()const;
		ostream& write(ostream&)const;
		istream& read(istream&);
		void set(int member_id);
		operator bool()const;
		~Book();
	};
}
#endif