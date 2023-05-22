/*
MILESTONE 5
Name:PRANAV PATEL
Seneca Email: papatel48@myseneca.ca
Student ID: 119954212

Date: 07/08/2022
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__
#include <iostream>
#include"Utils.h"
const unsigned int MAX_MENU_ITEMS = 20;
namespace sdds {
	class MenuItem {
	private:
		char* item;
		MenuItem();
		MenuItem(const char* menuitem);
		operator char* () const;
		operator bool() const;
		std::ostream& write(std::ostream& os = std::cout)const;
		~MenuItem();
	public:
		friend class Menu;
	};

	class Menu {
	private:
		MenuItem *title;
		MenuItem *itemList[MAX_MENU_ITEMS];
		unsigned int no_of_items;
	public:
		Menu();
		Menu(const char* menuitem);
		std::ostream& display(std::ostream& os = std::cout)const;
		unsigned int run();
		unsigned int operator ~();
		Menu& operator<<(const char* menuitemConent);
		std::ostream& displayT(std::ostream& os);
		operator int();
		operator unsigned int();
		operator bool();
		const char* operator [](int i)const;

		~Menu();
	};
	std::ostream& operator<<(std::ostream& os,Menu& menu);
	
}
#endif // !