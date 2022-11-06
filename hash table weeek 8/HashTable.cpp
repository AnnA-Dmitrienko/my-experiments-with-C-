/***********************************************************************
// Week 8 -Hash Table
// Author   Anna Dmitrienko
***********************************************************************/

#include <iostream>
#include <cassert>
#include "HashTable.h"

using namespace std;
int idex{};

Table::Table() {
   used = 0;
   for (int i = 0; i < CAPACITY; i++) {
      data[i].key = -1; //all data keys set to -1
      //if we delete it, we should mark it differently (eg -1000)
   }
}
void Table::insert(const RecordType& entry) {
   //convert entry.key to index
   //find is the index is empty or not(if not- linear probing)

   bool alreadyThere;
   int index = 0;
   findIndex(entry.key, alreadyThere, index);
   if (!alreadyThere) {
      //find if we exceeded the capacity or not 
      assert(size() < CAPACITY); //assert- evaluates of the condition true- lets pass; if false - throw an error message and stop there
      used++; //increase how many used
   }
   data[index] = entry;
}
void Table::find(int key, bool& found, RecordType& result) {
   cout << "Key to find: " << key << endl;
   findIndex(key, found, idex);
   if (found) {
      result = data[idex];
   }
}
int Table::hash(int key) const {
   return key % CAPACITY;
}
void Table::findIndex(int key, bool& found, int& index) {
   index = hash(key);

   int count = 0; //loop counter
   //do linear probing if you need  to do it
   while (count < CAPACITY && data[index].key != -1 && data[index].key != -1000 && data[index].key != key) {//meaning the slot is not empty && the record not already there
      cout << "I am doing linear probing since the slot:"<< endl; 
      cout << "data[" << index << "].key= " << data[index].key << " is occupied" << endl<< endl;
      count++;
      index = (index + 1) % CAPACITY;//go to next slot 
   }
   found = data[index].key == key;
   string No="No";
   string Yes="Yes";
   
   cout << "found = ";
   if (found) { cout << "Yes"<<endl;  }
   else cout << "No" << endl; //if true display 1 if false display 0 

}
int Table::size() const {
   return used;
}

void Table::remove(const RecordType& entry) {
   //convert entry.key to index
   //find is the index is empty or not
   bool alreadyThere;
   int index = 0;
   cout << "original used count: " << used<<endl;
   findIndex(entry.key, alreadyThere, index);
   if (alreadyThere) {
      used--; //decrease use count
   }
   data[index].key = -1000; //mark the data as deleted 
   data[index].otherData = 0; //null the other data 
   data[index].importantData = 0;
   cout << "used is now: " << used<<endl; 
}

