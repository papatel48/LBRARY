/*
MILESTONE 5
Name:PRANAV PATEL
Seneca Email: papatel48@myseneca.ca
Student ID: 119954212

Date: 07/08/2022
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
#ifndef SDDS_DATE_H__
#define SDDS_DATE_H__
#include <iostream>
namespace sdds {
   const int Not_error = 0;
   const int input_Failed = 1;
   const int Error_Year = 2;
   const int Error_Month= 3;
   const int  Error_Day = 4;
   const char Error_Date[5][16] = {
      "No Error",
      "cin Failed",
      "Bad Year Value",
      "Bad Month Value",
      "Bad Day Value"
   };
   const int  MIN_YEAR = 1500;
   class Date {
   private:
      int m_year;
      int m_mon;
      int m_day;
      int m_ErrorCode;
      int m_CUR_YEAR;
      int daysSince0001_1_1()const; 
      bool validate();             
                                   
      void errCode(int);           
      int systemYear()const;       
      bool bad()const;             
      int mdays()const;           
   public:
      Date();                      
      Date(int year, int mon, int day);          
      int errCode()const;        
      const char* dateStatus()const;  
      int currentYear()const;         
      std::istream& read(std::istream& is = std::cin);
      std::ostream& write(std::ostream& os = std::cout)const;
      bool operator == (Date D2)const;
      bool operator != (Date D2)const;
      bool operator >= (Date D2)const;
      bool operator <= (Date D2)const;
      bool operator <  (Date D2)const;
      bool operator >  (Date D2)const;
      int operator -  (Date D2)const;
      operator bool();
      void setToToday();           

   };
   std::ostream& operator<<(std::ostream& os, const Date& RO);
   std::istream& operator>>(std::istream& is, Date& RO);
   extern bool sdds_test;
   extern int sdds_year;
   extern int sdds_mon;
   extern int sdds_day;
}
#endif