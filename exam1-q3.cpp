#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;


class StudentRecord {
public:
   string m_name;
   int m_grade;
   int m_id;


   //parameterized constructor
   StudentRecord(string name = "John", int grade = 0, int id = 00000) {
      m_name = name;
      m_grade = grade;
      m_id = id;
   }

   virtual ~StudentRecord() {};   //destructor


   void setName(string name_) {
      if (validateString(name_)) {
         m_name = name_;
      }
      else m_name = "unknown";

   }
   void setGrade(int grade_) {
      if (grade_ <= 100 && grade_ >= 0) {
         m_grade = grade_;
      }
      else if (grade_ > 100) {
         m_grade = 100;
      }
      else {
         m_grade = 30;
      }
   }
   void setId(int id_) {
      if (id_ >= 100 && id_<=999) {
         m_id = id_;
      }
      else {
         m_id = 100;
      }
   }

   string getName()const { return m_name; }
   int getGrade()const { return m_grade; }
   int getID()const { return m_id; }


   bool operator < (const StudentRecord& stud) const {
      return (m_name < stud.m_name);
   }

   bool validateString(const std::string& s)
   {
      for (const char c : s) {
         if (!isalpha(c) && !isspace(c))
            return false;
      }

      return true;
   }

};




//function headers
void mainMenu();
void goodbye();


int main() {

   int  choice = -1;
   int grade, id, min = 100, max = 0;
   int sum = 0;
   string name;



   StudentRecord student;
   vector<StudentRecord> vec;
   vector<StudentRecord>::iterator iter;




   while (choice != 0) {
      mainMenu();
      cout << "Enter your choice: ";
      while (!(cin >> choice)) {
         cin.clear();
         cin.ignore(1000, '\n');
         cout << "\nBad data, try again!" << endl;
         cout << "Enter your choice: ";
      }
      cin.ignore();

      switch (choice) {
      case 1:

         cout << "Enter Student name: ";
         while (!(cin >> name)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nBad data, try again!" << endl;
            cout << "Enter Student name: ";
         }
         cout << "Enter Student grade: ";
         cin >> grade;
         cout << "Enter Student id: (XXX) ";
         cin >> id;

         student.setName(name);
         student.setId(id);
         student.setGrade(grade);

         vec.push_back(student);


         break;
      case 2:
         //sorting with lambda
         sort(vec.begin(), vec.end(), [](const StudentRecord& lhs, const StudentRecord& rhs)
            {
               return lhs.getName() < rhs.getName();
            });



         for (iter = vec.begin(); iter != vec.end(); iter++) {
            cout << "\nDisplay Students" << "\n.............." << endl;
            cout << "student name: " << iter->getName() << endl;
            cout << "student grade: " << iter->getGrade() << endl;
            cout << "student id: " << iter->getID() << endl;
         }


         for (iter = vec.begin(); iter != vec.end(); iter++) {
            sum += iter->getGrade();
         }


        for (iter = vec.begin(); iter != vec.end(); iter++) {
            if (max < iter->getGrade()) {
               max = iter->getGrade();
            }
         }

         for (iter = vec.begin(); iter != vec.end(); iter++) {
            if (min > iter->getGrade()) {
               min = iter->getGrade();
            }
         }
     


         cout << "\n\nSummary" << "\n........." << endl;
         cout << "Max grade is: " << max << endl;
         cout << "Min grade is: " << min << endl;
         //cout << "sum grades is :" << sum << endl;
         cout << "Average grade is: " << sum / vec.size();

         break;
      case 0:
         goodbye();
         exit(0);
      default:
         cout << "Invalid choice, please try again" << endl << endl;
      }
   }




   return 0;
}//!main

//implementations
void goodbye() {
   cout << endl;
   cout << std::setfill('*') << std::setw(55);
   cout << "*" << endl;
   cout << "\t\tThank you and goodbye" << endl;
   cout << std::setfill('*') << std::setw(55);
   cout << "*" << endl;
   cout << endl;
}

void mainMenu() {
   cout << endl;
   cout << std::setfill('*') << std::setw(55);
   cout << "*" << endl;
   cout << "\t\tWelcome To Anna's App" << endl;
   cout << std::setfill('*') << std::setw(55);
   cout << "*" << endl;
   cout << endl;
   cout << "Select an option, press 0 to quit: " << endl;
   cout << "\t 1. Add " << endl;
   cout << "\t 2. Display" << endl;
   cout << "\t 0. Quit the program" << endl;
}