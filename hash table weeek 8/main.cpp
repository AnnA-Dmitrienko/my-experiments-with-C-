/***********************************************************************
// Week 8 -Hash Table
// Author   Anna Dmitrienko
***********************************************************************/


#include <iostream>
#include "HashTable.h"
using namespace std;

void print_menu() {
   cout << "\nThe following choices are available: "
      << "\n I insert a new record or update an existing record"
      << "\n F find a record "
      << "\n S get the number of records(size)"
      << "\n D to delete a record "//MAKE SHURE IT'S NOT INTERFERING WITHT THE SEARCH!!
      << "\n Q quit the program" << endl << endl;
}
int main() {

   char choice;
   size_t key, size = 0;
   bool found = false;
   RecordType rec;
   Table dataTable;//the hash table

   do {
      print_menu();
      cout << "Enter choice: ";
      cin >> choice;
      choice = toupper(choice);

      switch (choice) {
      case 'I':
         cout << "Enter key(integer>=0) for a record: ";
         cin >> rec.key;
         cout << "Enter other data (double) for a record: ";
         cin >> rec.otherData;
         cout << "Enter important data(integer) for a record: ";
         cin >> rec.importantData;
         dataTable.insert(rec);
         cout << "Record is inserted in the hash table" << endl;
         break;
      case 'F':
         cout << "Enter key(integer>=0) to search for: ";
         cin >> key;
         dataTable.find(key, found, rec);
         if (found) {
            cout << "Record was found." << endl;
            cout << "Key           = " << rec.key << endl;
            cout << "other data    = " << rec.otherData << endl;
            cout << "important data = " << rec.importantData << endl;
         }
         else {
            cout << "Record with key " << key << " not found" << endl;
         }
         break;
      case 'S':
         size = dataTable.size();
         cout << "There are " << size << " records in the hash table." << endl;
         cout << "There are " << CAPACITY - size << " empty slots left in the table." << endl;
         break;
      case 'D':
         cout << "Enter entry key(integer>=0) to delete: ";
         cin >> rec.key;
         dataTable.remove(rec);
         cout << "The record was sucessfully removed" << endl;
         break;
      case 'Q':
         cout << "Thank you for using my hash table...GOODBYE" << endl;
         break;
      default:
         cout << choice << " is invalid, try again." << endl;
      }
   } while (choice != 'Q');



   return 0;
}//!main




/*SAMPLE OUTPUT (that tests deletion and linear probing with %1 modulus)
* The following choices are available:
 I insert a new record or update an existing record
 F find a record
 S get the number of records(size)
 D to delete a record
 Q quit the program

Enter choice: s
There are 0 records in the hash table.
There are 31 empty slots left in the table.

The following choices are available:
 I insert a new record or update an existing record
 F find a record
 S get the number of records(size)
 D to delete a record
 Q quit the program

Enter choice: i
Enter key(integer>=0) for a record: 32
Enter other data (double) for a record: 32.32
Enter important data(integer) for a record: 3232
found = No
Record is inserted in the hash table

The following choices are available:
 I insert a new record or update an existing record
 F find a record
 S get the number of records(size)
 D to delete a record
 Q quit the program

Enter choice: i
Enter key(integer>=0) for a record: 1
Enter other data (double) for a record: 1.1
Enter important data(integer) for a record: 11
I am doing linear probing since the slot:
data[1].key= 32 is occupied

found = No
Record is inserted in the hash table

The following choices are available:
 I insert a new record or update an existing record
 F find a record
 S get the number of records(size)
 D to delete a record
 Q quit the program

Enter choice: i
Enter key(integer>=0) for a record: 1
Enter other data (double) for a record: 1.121
Enter important data(integer) for a record: 111
I am doing linear probing since the slot:
data[1].key= 32 is occupied

found = Yes
Record is inserted in the hash table

The following choices are available:
 I insert a new record or update an existing record
 F find a record
 S get the number of records(size)
 D to delete a record
 Q quit the program

Enter choice: f
Enter key(integer>=0) to search for: 1
Key to find: 1
I am doing linear probing since the slot:
data[1].key= 32 is occupied

found = Yes
Record was found.
Key           = 1
other data    = 1.121
important data = 111

The following choices are available:
 I insert a new record or update an existing record
 F find a record
 S get the number of records(size)
 D to delete a record
 Q quit the program

Enter choice: i
Enter key(integer>=0) for a record: 63
Enter other data (double) for a record: 63.63
Enter important data(integer) for a record: 6363
I am doing linear probing since the slot:
data[1].key= 32 is occupied

I am doing linear probing since the slot:
data[2].key= 1 is occupied

found = No
Record is inserted in the hash table

The following choices are available:
 I insert a new record or update an existing record
 F find a record
 S get the number of records(size)
 D to delete a record
 Q quit the program

Enter choice: d
Enter entry key(integer>=0) to delete: 32
original used count: 3
found = Yes
used is now: 2
The record was sucessfully removed

The following choices are available:
 I insert a new record or update an existing record
 F find a record
 S get the number of records(size)
 D to delete a record
 Q quit the program

Enter choice: s
There are 2 records in the hash table.
There are 29 empty slots left in the table.

The following choices are available:
 I insert a new record or update an existing record
 F find a record
 S get the number of records(size)
 D to delete a record
 Q quit the program

Enter choice: 94
9 is invalid, try again.

The following choices are available:
 I insert a new record or update an existing record
 F find a record
 S get the number of records(size)
 D to delete a record
 Q quit the program

Enter choice: 4 is invalid, try again.

The following choices are available:
 I insert a new record or update an existing record
 F find a record
 S get the number of records(size)
 D to delete a record
 Q quit the program

Enter choice: i
Enter key(integer>=0) for a record: 94
Enter other data (double) for a record: 94.94
Enter important data(integer) for a record: 949494
found = No
Record is inserted in the hash table

The following choices are available:
 I insert a new record or update an existing record
 F find a record
 S get the number of records(size)
 D to delete a record
 Q quit the program

Enter choice: s
There are 3 records in the hash table.
There are 28 empty slots left in the table.

The following choices are available:
 I insert a new record or update an existing record
 F find a record
 S get the number of records(size)
 D to delete a record
 Q quit the program

Enter choice: i
Enter key(integer>=0) for a record: 125
Enter other data (double) for a record: 125.125
Enter important data(integer) for a record: 125
I am doing linear probing since the slot:
data[1].key= 94 is occupied

I am doing linear probing since the slot:
data[2].key= 1 is occupied

I am doing linear probing since the slot:
data[3].key= 63 is occupied

found = No
Record is inserted in the hash table

The following choices are available:
 I insert a new record or update an existing record
 F find a record
 S get the number of records(size)
 D to delete a record
 Q quit the program

Enter choice: d
Enter entry key(integer>=0) to delete: 1
original used count: 4
I am doing linear probing since the slot:
data[1].key= 94 is occupied

found = Yes
used is now: 3
The record was sucessfully removed

The following choices are available:
 I insert a new record or update an existing record
 F find a record
 S get the number of records(size)
 D to delete a record
 Q quit the program

Enter choice: i
Enter key(integer>=0) for a record: 2
Enter other data (double) for a record: 2.2
Enter important data(integer) for a record: 22
found = No
Record is inserted in the hash table

The following choices are available:
 I insert a new record or update an existing record
 F find a record
 S get the number of records(size)
 D to delete a record
 Q quit the program

Enter choice: s
There are 4 records in the hash table.
There are 27 empty slots left in the table.

The following choices are available:
 I insert a new record or update an existing record
 F find a record
 S get the number of records(size)
 D to delete a record
 Q quit the program

Enter choice: q
Thank you for using my hash table...GOODBYE
*/