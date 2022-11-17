//main.cpp 
#include <iostream> 
#include <cstdlib> 
#include <string> 
#include "Book.h" 
using namespace std;

//function headers 
void mainMenu();
void goodbye();

int main()
{
   int i = 0;
   char choice{};
   int copies{}, year{};
   string title{}, a_name{};
   bool found = false;
   //creating a binary tree 
   Dictionary<Book> tree;
   Book book;

   do {
      mainMenu();
      cout << "Enter choice: ";
      cin >> choice;
      choice = toupper(choice);
      cin.ignore();

      switch (choice) {
      case 'I':
         cout << "Enter the book titlte for book #" << i + 1 << ": ";
         getline(cin, title);
         cout << "Enter the author name for book #" << i + 1 << ": ";
         cin >> a_name;
         cout << "Enter the number of copies for book #" << i + 1 << ": ";
         cin >> copies;
         cout << "Enter the publication year for book #" << i + 1 << ": ";
         cin >> year;

         book.setTitle(title);
         book.setAuthor(a_name);
         book.setCopies(copies);
         book.setYear(year);

         tree.insertNode(book);
         i++;
         cout << endl;
         break;
      case 'S':
         tree.showNodesInOrder();
         break;
      case 'C':
         tree.showNodesFiltered(); 
         break;
      case 'F':
         cout << "\nEnter book title to search: ";
         getline(cin, title);
         book.setTitle(title);
         tree.searchNode(book) ? cout << "Book with title " << title << " was found" :
            cout << "Book with title" << title << " was **not** found in the tree" << endl;
         break;
      case 'D':
         cout << "\nEnter book title to delete: ";
         getline(cin, title);
         book.setTitle(title);
         tree.remove(book);
         break;
      case 'Q':
         goodbye();
         break;
      default:
         cout << choice << " is invalid, try again." << endl;
      }
   } while (choice != 'Q');


   return 0;
}//!main 

//implementations 
void goodbye() {
   cout << endl;
   cout << std::setfill('*') << std::setw(55);
   cout << "*" << endl;
   cout << "Thank you and goodbye" << endl;
   cout << std::setfill('*') << std::setw(55);
   cout << "*" << endl;
   cout << endl;
   cout << std::setfill(' ');
}

void mainMenu() {
   cout << endl;
   cout << std::setfill('*') << std::setw(55);
   cout << "*" << endl;
   cout << "Welcome To Dictionary App" << endl;
   cout << std::setfill('*') << std::setw(55);
   cout << "*" << endl;
   cout << endl;
   cout << "\nSelect an option, Q to quit: "
      << "\n I Insert Records to Dictionary"
      << "\n S Display All Records In-Order"
      << "\n C Display Books With More Than One Copy"
      << "\n F Find a record "
      << "\n D Delete a record"
      << "\n Q quit the program" << endl << endl;

   cout << std::setfill(' ');
}

/*SAMPLE OUTPUT

*******************************************************
Welcome To Dictionary App
*******************************************************


Select an option, Q to quit:
 I Insert Records to Dictionary
 S Display All Records In-Order
 C Display Books With More Than One Copy
 F Find a record
 D Delete a record
 Q quit the program

Enter choice: i
Enter the book titlte for book #3: Programming 101
Enter the author name for book #3: Peter
Enter the number of copies for book #3: 5
Enter the publication year for book #3: 2005


*******************************************************
Welcome To Dictionary App
*******************************************************


Select an option, Q to quit:
 I Insert Records to Dictionary
 S Display All Records In-Order
 C Display Books With More Than One Copy
 F Find a record
 D Delete a record
 Q quit the program

Enter choice: i
Enter the book titlte for book #4: Immunology Advanced
Enter the author name for book #4: Marie
Enter the number of copies for book #4: 1
Enter the publication year for book #4: 2005


*******************************************************
Welcome To Dictionary App
*******************************************************


Select an option, Q to quit:
 I Insert Records to Dictionary
 S Display All Records In-Order
 C Display Books With More Than One Copy
 F Find a record
 D Delete a record
 Q quit the program

Enter choice: s
..........................
Books  displayed In-Order:
..........................
Title: Biology 101
Author: Michael
Copies: 1
Year: 2002

Title: Chemistry For Beginners
Author: Anna
Copies: 3
Year: 1999

Title: Immunology Advanced
Author: Marie
Copies: 1
Year: 2005

Title: Programming 101
Author: Peter
Copies: 5
Year: 2005


*******************************************************
Welcome To Dictionary App
*******************************************************


Select an option, Q to quit:
 I Insert Records to Dictionary
 S Display All Records In-Order
 C Display Books With More Than One Copy
 F Find a record
 D Delete a record
 Q quit the program

Enter choice: c
..........................
Filtered Books (count>1):
..........................
Book is: Chemistry For Beginners
# of Copies: 3

Book is: Programming 101
# of Copies: 5


*******************************************************
Welcome To Dictionary App
*******************************************************


Select an option, Q to quit:
 I Insert Records to Dictionary
 S Display All Records In-Order
 C Display Books With More Than One Copy
 F Find a record
 D Delete a record
 Q quit the program

Enter choice: f

Enter book title to search: Biology 101
Book with title Biology 101 was found
*******************************************************
Welcome To Dictionary App
*******************************************************


Select an option, Q to quit:
 I Insert Records to Dictionary
 S Display All Records In-Order
 C Display Books With More Than One Copy
 F Find a record
 D Delete a record
 Q quit the program

Enter choice: f

Enter book title to search: Astrology
Book with titleAstrology was **not** found in the tree

*******************************************************
Welcome To Dictionary App
*******************************************************


Select an option, Q to quit:
 I Insert Records to Dictionary
 S Display All Records In-Order
 C Display Books With More Than One Copy
 F Find a record
 D Delete a record
 Q quit the program

Enter choice: D

Enter book title to delete: Immunology Advanced
Book successfully deletedBook successfully deletedBook successfully deleted
*******************************************************
Welcome To Dictionary App
*******************************************************


Select an option, Q to quit:
 I Insert Records to Dictionary
 S Display All Records In-Order
 C Display Books With More Than One Copy
 F Find a record
 D Delete a record
 Q quit the program

Enter choice: s
..........................
Books  displayed In-Order:
..........................
Title: Biology 101
Author: Michael
Copies: 1
Year: 2002

Title: Chemistry For Beginners
Author: Anna
Copies: 3
Year: 1999

Title: Programming 101
Author: Peter
Copies: 5
Year: 2005


*******************************************************
Welcome To Dictionary App
*******************************************************


Select an option, Q to quit:
 I Insert Records to Dictionary
 S Display All Records In-Order
 C Display Books With More Than One Copy
 F Find a record
 D Delete a record
 Q quit the program

Enter choice: s
..........................
Books  displayed In-Order:
..........................
Title: Biology 101
Author: Michael
Copies: 1
Year: 2002

Title: Chemistry For Beginners
Author: Anna
Copies: 3
Year: 1999

Title: Programming 101
Author: Peter
Copies: 5
Year: 2005


*******************************************************
Welcome To Dictionary App
*******************************************************


Select an option, Q to quit:
 I Insert Records to Dictionary
 S Display All Records In-Order
 C Display Books With More Than One Copy
 F Find a record
 D Delete a record
 Q quit the program

Enter choice: c
..........................
Filtered Books (count>1):
..........................
Book is: Chemistry For Beginners
# of Copies: 3

Book is: Programming 101
# of Copies: 5


*******************************************************
Welcome To Dictionary App
*******************************************************


Select an option, Q to quit:
 I Insert Records to Dictionary
 S Display All Records In-Order
 C Display Books With More Than One Copy
 F Find a record
 D Delete a record
 Q quit the program

Enter choice: q

*******************************************************
Thank you and goodbye
*******************************************************


Destructor...all nodes were deleted!
*/
