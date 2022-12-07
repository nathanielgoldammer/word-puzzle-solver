#include "hashTable.h"
using namespace std;
//Default Constructor
hashTable::hashTable(unsigned int tableSize)
{
	//If tableSize is a prime number
	if(checkPrime(tableSize) == true)
	{
		//Set the hashTable's size = tableSize
		size = tableSize;

		//Resize theHashTable with size
		theHashTable.resize(size);
	}

	//Else tableSize is not a prime number
	else
	{
		//Set the hashTable's size = the next prime number after tableSize
		size = getNextPrime(tableSize);

		//Resize theHashTable with size
		theHashTable.resize(size);
	}
}

//Destructor
hashTable::~hashTable()
{
	//No actions to be taken
}

//Inserts the key into theHashTable.
void hashTable::insert(string key)
{
	//Let hashValue = the key's corresponding hash value
	unsigned int hashValue = hash(key);

	//Insert the key into the head of the list in hashValue'th index of theHashTable
	theHashTable[hashValue].push_front(key);
}

//Searches theHashTable for the key; returns true if the key is found, and false if otherwise.
bool hashTable::search(string key)
{
	//Let hashValue = the key's corresponding hash value
	unsigned int hashValue = hash(key);

	//If the hashValue'th index of theHashTable is not empty
	if(theHashTable[hashValue].empty() == false)
	{
		//Let itty = an iterator pointing to the beginning of the list in hashValue'th index of theHashTable
		list<string>::iterator itty = theHashTable[hashValue].begin();

		//While itty is not pointing to the end of the list in hashValue'th index of theHashTable
		while(itty != theHashTable[hashValue].end())
		{
			//If *itty = the key
			if(*itty == key)
			{
				//Return true 
				return true;
			}

			//Advance itty by 1 position
			advance(itty, 1);
		}
	}

	//Return false
	return false;
}

int hashTable::numberOfKeys()
{
	//Let keys = the number of keys in theHashTable
	int keys = 0;

	//For each index of theHashTable
	for(int i = 0; i < theHashTable.size(); i++)
	{
		//If the i'th index of theHashTable is not empty
		if(theHashTable[i].empty() == false)
		{
			//Increment keys by the size of the List in the i'th index of theHashTable
			keys = keys + theHashTable[i].size();
		}
	}

	//Return keys
	return keys;
}

//Computes and returns the corresponding hash value of the key. 
unsigned int hashTable::hash(string key)
{
	//Let the hashValue = 0
	unsigned int hashValue = 0; 

	//For each character of the key
	for(char character : key)
	{
		//Let the hashValue = 37 * hashValue + character
		hashValue = (37 * hashValue) + character;
	}

	//Return the hashValue in the proper range
	return hashValue % size;
}

//Determines if n is a prime number; returns true if n is prime, and false if otherwise.  
bool hashTable::checkPrime(unsigned int n)
{
	//If n is less than or equal to 1
	if(n <= 1)
	{
		//Return false
		return false;
	}

	//If n = 2
	else if(n == 2)
	{
		//Return true
        return true;
	}

	//If n is an even number other than 2
    else if(n % 2 == 0)
    {
    	//Return false
        return false;
    }

    //For each odd integer greater than or equal to 3, whose square is less than or equal to n
    for (int i = 3; i*i <= n; i += 2)
    {
    	//If the remainder n%i = 0
        if (n % i == 0)
        {
        	//Return false
            return false;
        }
    }

    //Return true
    return true;
}

//Returns the next prime number after n. 
int hashTable::getNextPrime(unsigned int n)
{
	//While ++n is not a prime number
	while(!checkPrime(++n)); 

	//Return n 
	return n;
}