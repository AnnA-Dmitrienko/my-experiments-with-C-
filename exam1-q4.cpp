#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;


class StudentRecord {



   string m_name;
   int m_grade;
   int m_id;

public:
   //default constructor
   StudentRecord(string name = "John", int grade = 0, int id = 00000) {
      m_name = name;
      m_grade = grade;
      m_id = id;
   }

   virtual ~StudentRecord() {};   //destructor


   void setName(string name_) {
      m_name = name_;

   }
   void setGrade(int grade_) {
      if (grade_ <= 100 && grade_ >= 0) {
         m_grade = grade_;
      }
      else if (grade_ > 100) {
         m_grade = 100;
      }
      else if (grade_ < 0) { m_grade = 0; }
      else {
         m_grade = grade_;
      }
   }

   void setId(int id_) {
      if (id_ >= 0) {
         m_id = id_;
      }
      else {
         m_id = 0;
      }
   }

   string getName()const { return m_name; }
   int getGrade()const { return m_grade; }
   int getID()const { return m_id; }


   bool operator < (const StudentRecord& stud) const {
      return (m_name < stud.m_name);
   }

   int operator() (int s) { return s; }

};



//template<typename T>
////template function 
//int sum(vector<T>& vec, int n) {
//   int sum = 0;
//   for (auto stud : vec) {
//      sum += stud.getGrade();
//   }
//   return sum;
//
//}

//function headers
void mainMenu();
void goodbye();


int main() {

   int  choice = -1;
   int grade, id, min = 100, max = 0;
   int sumS = 0;
   double average = 0.00;
   string name;


   StudentRecord student;
   vector<StudentRecord> vec;
   vector<StudentRecord>::iterator iter;


   while (choice != 0) {
      mainMenu();
      cout << "Enter your choice: ";
      cin >> choice;
      cin.ignore();

      switch (choice) {
      case 1:

         cout << "Enter Student name: ";
         cin >> name;
         cout << "Enter Student grade: ";
         cin >> grade;
         cout << "Enter Student id: ";
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
         for (iter = vec.begin(); iter != vec.end(); iter++) {
            sumS += student(iter->getGrade());
         }
         cout << "sum grades is :" << sumS << endl;

        

         average = sumS / vec.size();
         cout << "Average grade is: " << fixed << setprecision(2) << average;

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


/*SAMPLE OUTPUT
*
*******************************************************
                Welcome To Anna's App
*******************************************************

Select an option, press 0 to quit:
         1. Add
         2. Display
         0. Quit the program
Enter your choice: 1
Enter Student name: Ruth
Enter Student grade: 50
Enter Student id: 123

*******************************************************
                Welcome To Anna's App
*******************************************************

Select an option, press 0 to quit:
         1. Add
         2. Display
         0. Quit the program
Enter your choice: 1
Enter Student name: Anna
Enter Student grade: 50
Enter Student id: 111

*******************************************************
                Welcome To Anna's App
*******************************************************

Select an option, press 0 to quit:
         1. Add
         2. Display
         0. Quit the program
Enter your choice: 1
Enter Student name: Vaily
Enter Student grade: 30
Enter Student id: 111

*******************************************************
                Welcome To Anna's App
*******************************************************

Select an option, press 0 to quit:
         1. Add
         2. Display
         0. Quit the program
Enter your choice: 2

Display Students
..............
student name: Anna
student grade: 50
student id: 111

Display Students
..............
student name: Ruth
student grade: 50
student id: 123

Display Students
..............
student name: Vaily
student grade: 30
student id: 111


Summary
.........
Max grade is: 50
Min grade is: 30
Average grade is: 43.00
*******************************************************
                Welcome To Anna's App
*******************************************************

Select an option, press 0 to quit:
         1. Add
         2. Display
         0. Quit the program
Enter your choice: 0

*******************************************************
                Thank you and goodbye
*******************************************************
*/