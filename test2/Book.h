//Book.h  
#pragma once 
#include <iostream> 
#include <string> 
#include "Dictionary.h" 
using namespace std;

class Book {

private:
   string m_title{};
   string m_author{};
   int m_copies{};
   int m_year{};

public:
   //default constructor 
   Book() {
      m_copies = 0;
      m_year = 0;
      m_title = "";
      m_author = "";
   };

   //parameterized constructor  
   Book(string title, string author, int copies, int year) {
      m_title = title;
      m_author = author;
      m_copies = copies;
      m_year = year;
   }

   //destructor 
   virtual ~Book() {};

   //getters 
   int getCopies()const { return m_copies; }
   int getYear()const { return m_year; }
   string getTitle()const { return m_title; }
   string getAuthor()const { return m_author; }

   //setters 
   void setCopies(int copies) {
      if (copies > 0) {
         m_copies = copies;
      }
      else m_copies = 0;
   }


   void setYear(int year) {
      if (year > 1900 && year <= 2050) {
         m_year = year;
      }
      else m_year = 0;
   }


   void setTitle(string title) {
      //i would like to allow title to have numbers 
      //and special characters 
      //therefore I'm not adding validation rules on purpose 
      m_title = title;
   }

   void setAuthor(string author) {
      if (validateString(author)) {
         m_author = author;
      }
      else m_author = "unknown";
   }


   bool validateString(const std::string& s)
   {
      for (const char c : s) {
         if (!isalpha(c) && !isspace(c))
            return false;
      }

      return true;
   }



   //overloading operators  
   bool operator < (const Book& rhs);
   bool operator > (const Book& rhs);
   bool operator == (const Book& rhs);
   friend ostream& operator << (ostream& out, const Book& cust);

   template <typename T>
   friend class Dictionary; 

};

//we will be inserting by book title as a key, teherefore  
//overolading the operators by title  
bool Book::operator < (const Book& rhs) {
   bool compare;
   if (m_title < rhs.m_title)
   {
      compare = true;
   }
   else {
      compare = false;
   }
   return compare;
}
bool Book::operator > (const Book& rhs) {
   bool compare;
   if (m_title > rhs.m_title)
   {
      compare = true;
   }
   else {
      compare = false;
   }
   return compare;
}
bool Book::operator == (const Book& rhs) {
   bool compare;
   if (m_title == rhs.m_title)
   {
      compare = true;
   }
   else {
      compare = false;
   }
   return compare;
}

//for the display to the ostream  
ostream& operator << (ostream& out, const Book& book)
{
   out << "Title: " << left << setw(5) << book.m_title << endl;
   out << "Author: " << left << setw(5) << book.m_author << endl;
   out << "Copies: " << left << setw(5) << book.m_copies << endl;
   out << "Year: " << left << setw(5) << book.m_year << endl;
   return out;
}