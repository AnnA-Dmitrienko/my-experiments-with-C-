
#pragma once
#include <iostream>
using namespace std;

const int CAPACITY = 31;

struct RecordType {
   int key; //PK -unique 
   double otherData;
   int importantData;
};

class Table {
   RecordType data[CAPACITY];
   int used; //track the amount of data elements in our hash table
public:
   Table();
   void insert(const RecordType& entry);
   void find(int key, bool& found, RecordType& result);//find a record (search)
   int hash(int key) const; //getter to receive a key and return the index
   void findIndex(int key, bool& found, int& i);
   int size() const;//how many data elements we have in the table 
   void remove(const RecordType& entry);
};
