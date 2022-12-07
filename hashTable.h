#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <string>
using namespace std;
class hashTable 
{
	public:

		//Default Constructor
		hashTable(unsigned int tableSize);

		//Destructor
		~hashTable();

		//Inserts the key into theHashTable.
		void insert(string key);

		//Searches theHashTable for the key; returns true if the key is found, and false if otherwise.
		bool search(string key);

		//Returns the number of keys in the hashTable. 
		int numberOfKeys();

	private:

		//The hashTable is implemented as a vector of linked-lists, which themselves contain strings. 
		vector< list<string> > theHashTable;

		//The size of the hashTable.
		int size;

		//Computes and returns the corresponding hash value of the key. 
		unsigned int hash(string key);

		//Determines if n is a prime number; returns true if n is prime, and false if otherwise.  
		bool checkPrime(unsigned int n);

		//Returns the next prime number after n. 
		int getNextPrime(unsigned int n);
	
};
#endif