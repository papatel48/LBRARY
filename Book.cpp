/*
MILESTONE 5
Name:PRANAV PATEL
Seneca Email: papatel48@myseneca.ca
Student ID: 119954212

Date: 07/08/2022
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
#define _CRT_SECURE_NO_WARNINGS
#include"Book.h"
#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
namespace sdds {
	Book::Book():Publication(){
		Author_name  = nullptr;
	}
	Book::Book(const Book& other):Publication(other) {
		Author_name  = nullptr;
		if (other.Author_name  != nullptr) {
			Author_name  = new char[strlen(other.Author_name )+1];
			strcpy(Author_name , other.Author_name );
		}
	}
	Book& Book::operator=(const Book& other)
	{
		this->Publication::operator=(other);
		if (Author_name  != nullptr)
			delete[] Author_name ;
		Author_name  = nullptr;
		if (other.Author_name  != nullptr) {
			Author_name  = new char[strlen(other.Author_name )+1];
			strcpy(Author_name , other.Author_name );
		}
		return *this;
	}
	char Book::type() const
	{
		return 'B';
	}
	ostream& Book::write(ostream& os) const
	{
		Publication::write(os);
		if (conIO(os)) {
			os << " ";
			string str = Author_name ;
			if (strlen(Author_name ) > SDDS_AUTHOR_WIDTH) {
				os << str.substr(0, SDDS_AUTHOR_WIDTH);
			}
			else {
				os <<left << setw(SDDS_AUTHOR_WIDTH) << Author_name ;
			}
			os<< " |";
		}
		else {
			os << "\t" << Author_name ;
		}
		return os;
	}
	istream& Book::read(istream& is)
	{
		Publication::read(is);
		if (Author_name  != nullptr)
			delete[] Author_name ;
		Author_name  = nullptr;
		char author[257];
		if (conIO(is)) {
			is.ignore();
			cout << "Author: ";
			is.getline(author,250);
		}
		else {
			is.ignore();
			is.get(author,250,'\n');
		}

		if (!is.fail()) {
			Author_name  = new char[strlen(author)+1];
			strcpy(Author_name , author);
		}
		return is;
	}
	void Book::set(int member_id)
	{
		Publication::set(member_id);
		resetDate();
	}
	Book::operator bool() const
	{
		return (this->Publication::operator bool()  && Author_name  !=nullptr );
	}
	Book::~Book()
	{
		if(Author_name !=nullptr) {
			delete[] Author_name ;
		}
	}
}