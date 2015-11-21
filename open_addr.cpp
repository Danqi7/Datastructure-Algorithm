#include <iostream>
#include <string>


using namespace std;

//linear probing for open addressing

const int TABLE_SIZE = 5;

class HashEntry
{
private:
	int value;
	string key;

public:
	HashEntry(int value, string key)
	{
		this->value = value;
		this->key = key;
	}

	int getValue()
	{
		return value;
	}

	void setValue(int value)
	{
		this->value = value;
	}

	string getKey()
	{
		return key;
	}

	void displayEntry()
	{
		cout << key << " : " << value << endl; 
	}



};


class HashTable
{
	private:
		HashEntry** table;


		int hashing(string key, int tempt)
		{
			int sum = 0;

			for (int i = 0; i < key.length(); i++)
			{
				sum += key[i];
			}

			return (sum + tempt) % TABLE_SIZE;
		}



	public:

		HashTable()
		{
			table = new HashEntry*[TABLE_SIZE];
			for (int i = 0; i < TABLE_SIZE; i++)
			{
				table[i] = NULL;
			}

		}

		// store the value of the key
		void store(string key, int value)
		{
			int find = 0;
			for (int i = 0; i < TABLE_SIZE && find == 0; i++)
			{
				int hashed = hashing(key, i);
				if (table[hashed] != NULL) 
				{	
					//update value of the current key
					if (table[hashed]->getKey() == key)
					{
						table[hashed]->setValue(value);
						find = 1;
					}
				}
				else //find empty bucket and insert the new key
				{
					HashEntry* entry = new HashEntry(value, key);
					table[hashed] = entry;
					find = 1;
				}

			}
		}

		int lookup(string key)
		{
			for (int i = 0; i < TABLE_SIZE; i++)
			{
				int hashed = hashing(key, i);
				if (table[hashed]->getKey() == key) //find the key value pair
					return table[hashed]->getValue();

			}
				return -1; // key not found
		}

		void deleteKey(string key)
		{
			for (int i = 0; i < TABLE_SIZE; i++)
			{
				int hashed = hashing(key, i);
				if (table[hashed]->getKey() == key)
				{
					delete table[hashed];
					table[hashed] = NULL;

				}
			}
		}

		void displayTable()
		{
			for (int i = 0; i < TABLE_SIZE; i++)
			{
				if (table[i] != NULL)
					table[i]->displayEntry();
			}
		}

		~HashTable()
		{
			for (int i = 0; i < TABLE_SIZE; i++)
			{
				if (table[i] != NULL)
					delete table[i];
			}

			delete[] table;
		}


};


int main()
{
	HashTable* table = new HashTable();
	table->displayTable();

	table->store("Tobin", 27);
	table->store("Danqi", 19);
	table->store("Alex", 26);
	table->store("Tiffany", 19);
	table->store("Xiaoxiao", 21);

	table->displayTable();

	cout << "Tobin is " << table->lookup("Tobin");

	table->deleteKey("Xiaoxiao");

	table->displayTable();

	delete table;

	return 0;
}

