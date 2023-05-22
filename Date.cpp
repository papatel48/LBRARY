/*
MILESTONE 5
Name:PRANAV PATEL
Seneca Email: papatel48@myseneca.ca
Student ID: 119954212

Date: 07/08/2022
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
#include<iomanip>
using namespace std;
#include "Date.h"
namespace sdds {
    bool sdds_test = false;
    int sdds_year = 2022;
    int sdds_mon = 8;
    int sdds_day = 7;
   bool Date::validate() {
      errCode(Not_error);
      if (m_year < MIN_YEAR || m_year > m_CUR_YEAR + 1) {
         errCode(Error_Year);
      }
      else if (m_mon < 1 || m_mon > 12) {
         errCode(Error_Month);
      }
      else if (m_day < 1 || m_day > mdays()) {
         errCode(Error_Day);
      }
      return !bad();
   }
   int Date::mdays()const {
      int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
      int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
      mon--;
      return days[mon] + int((mon == 1) * ((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
   }
   int Date::systemYear()const {
       int theYear = sdds_year;
       if (!sdds_test) {
           time_t t = time(NULL);
           tm lt = *localtime(&t);
           theYear = lt.tm_year + 1900;
       }
       return theYear;
   }
   void Date::setToToday() {
       if (sdds_test) {
           m_day = sdds_day;
           m_mon = sdds_mon;
           m_year = sdds_year;
       }
       else {
           time_t t = time(NULL);
           tm lt = *localtime(&t);
           m_day = lt.tm_mday;
           m_mon = lt.tm_mon + 1;
           m_year = lt.tm_year + 1900;
       }
       errCode(Not_error);
   }
   int Date::daysSince0001_1_1()const { // Rata Die day since 0001/01/01
      int ty = m_year;
      int tm = m_mon;
      if (tm < 3) {
         ty--;
         tm += 12;
      }
      return 365 * ty + ty / 4 - ty / 100 + ty / 400 + (153 * tm - 457) / 5 + m_day - 306;
   }
   Date::Date() :m_CUR_YEAR(systemYear()) {
      setToToday();
   }
   Date::Date(int year, int mon, int day) : m_CUR_YEAR(systemYear()) {
      m_year = year;
      m_mon = mon;
      m_day = day;
      validate();
   }
   const char* Date::dateStatus()const {
      return Error_Date[errCode()];
   }
   int Date::currentYear()const {
      return m_CUR_YEAR;
   }
   void Date::errCode(int readErrorCode) {
      m_ErrorCode = readErrorCode;
   }
   int Date::errCode()const {
      return m_ErrorCode;
   }
   bool Date::bad()const {
      return m_ErrorCode != 0;
   }
   std::istream& Date::read(std::istream& is) {
       errCode(0);
       char c;
       is>>m_year;
       is.get(c);
       is >>m_mon;
       is.get(c);
       is >>m_day;
       if (is.fail()) {
           errCode(1);
           is.clear();
       }
       else {
           validate();
       }

       return is;
   }
   std::ostream& Date::write(std::ostream& os)const {
       if (bad()) {
           os << dateStatus();
       }
       else {
        
           os << m_year << "/" <<setw(2)<<std::setfill('0') << m_mon << "/" << setw(2) << m_day;
           os << std::setfill(' ');
       }
       return os;
   }
   bool Date::operator == (Date D2)const {
       return (this->daysSince0001_1_1() == D2.daysSince0001_1_1());
   }
   bool Date::operator != (Date D2)const {
       return (this->daysSince0001_1_1() != D2.daysSince0001_1_1());
   }
   bool Date::operator >= (Date D2)const{
       return (this->daysSince0001_1_1() >= D2.daysSince0001_1_1());
   }
   bool Date::operator <= (Date D2)const{
       return (this->daysSince0001_1_1() <= D2.daysSince0001_1_1());
   }
   bool Date::operator <  (Date D2)const{
       return (this->daysSince0001_1_1() < D2.daysSince0001_1_1());
   }
   bool Date::operator >  (Date D2)const{
       return (this->daysSince0001_1_1() > D2.daysSince0001_1_1());
   }
   int Date::operator -  (Date D2)const{
       return (this->daysSince0001_1_1() - D2.daysSince0001_1_1());
   }
   Date::operator bool()
   {
       return !bad();
   }
   ostream& operator<<(ostream& os, const Date& RO) {
      return RO.write(os);
   }
   istream& operator>>(istream& is, Date& RO) {
      return RO.read(is);
   }


}