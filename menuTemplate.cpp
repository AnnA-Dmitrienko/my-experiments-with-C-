#include <iostream>
#include <iomanip>

using namespace std; 

//function headers
void mainMenu();
void goodbye();


int main() {
   int  choice = -1;
   
   while (choice != 0) {
      mainMenu(); 
      cout << "Enter your choice: ";
      cin >> choice;
      cin.ignore();

      switch (choice) {
      case 1:
         cout << "choice 1" << endl;
         break;
      case 2:
         cout << "choice 2" << endl;
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