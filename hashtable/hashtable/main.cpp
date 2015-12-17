#include <iostream>
#include <string>

using namespace std;


struct Node
{
    int value;
    string key;
    Node* next;
};

class LinkedList
{
private:
    Node* head;
    int listSize;
    
public:
    
    LinkedList()
    {
        head = NULL;
        listSize = 0;
    }
    
    LinkedList(int value) //initialize the head with specific value
    {
        Node* newNode = new Node;
        newNode->value = value;
        newNode->next = NULL;
        newNode->key = "";
        head = newNode;
        listSize = 1;
    }
    
    Node* getHead()
    {
        return head;
    }
    
    int getSize()
    {
        return listSize;
    }
    
    int findNode(string key)
    {
        Node* currNode = head;
        while (currNode && currNode->key != key)
            currNode = currNode->next;
        
        if (currNode == NULL)
            return -1;
        
        return currNode->value;
        
    }
    
    void displayList()
    {
        Node* currNode = head;
        
        while (currNode)
        {
            //cout << "printing node" << endl;
            cout << currNode->key << " : ";
            cout << currNode->value << endl;
            currNode = currNode->next;
        }
    }
    
    
    int insertNode(int value, string key) //add node to the beginning of the list
    {
        
        Node* currNode = head;
        
        while (currNode && currNode->key != key)
            currNode = currNode->next;
        
        if (currNode == NULL) //insert new key-value pair
        {
            Node* newNode = new Node;
            newNode->value = value;
            newNode->next = NULL;
            newNode->key = key;
            
            newNode->next = head;
            head = newNode;
            
            listSize++;
        }
        else
        {
            currNode->value = value;
        }
        
        return listSize;
    }
    
    int deleteNode(string key) //remove the node from the list
    {
        Node* currNode = head;
        Node* prevNode = NULL;
        
        while (currNode && currNode->key != key)
            currNode = currNode->next;
        
        if (currNode == NULL)
        {
            return listSize;
        }
        
        if (prevNode == NULL)
        {
            head = head->next;
            delete currNode;
        }
        else
        {
            prevNode->next = currNode->next;
            delete currNode;
        }
        
        listSize--;
        return listSize;
        
    }
    
    
};



class HashTable
{
private:
    int tablesize = 2;
    int hashing(string key)
    {
        int sum = 0;
        
        for (int i = 0; i < key.length(); i++)
        {
            sum += key[i];
        }
        
        return sum % tablesize;

    }
    
    LinkedList* table = new LinkedList[tablesize];
    
public:
    int getSize()
    {
        int sum = 0;
        
        for (int i = 0; i < tablesize; i++)
        {
            sum = sum + table[i].getSize();
            
        }
        
        return sum;
    }
    
    int storeKey(string key, int value)
    {
        int hash = hashing(key);
        return table[hash].insertNode(value, key);
        
    }
    
    int removeKey(string key)
    {
        int hash = hashing(key);
        return table[hash].deleteNode(key);
        
    }
    
    int lookup(string key)
    {
        int hash = hashing(key);
        return table[hash].findNode(key);
    }
    
    void displayTable()
    {
        for (int i = 0; i < tablesize; i++)
        {
            table[i].displayList();
        }
    }
    
    
};



int main()
{
   // HashTable* table = new HashTable;
  
    /*
    table->storeKey("danqi", 19);
    table->storeKey("tiffany", 19);
    table->storeKey("alex", 26);
    table->storeKey("tobin", 27);
    
    table->displayTable();
    
    table->removeKey("tiffany");
    table->displayTable();
    cout << table->lookup("danqi") << endl;
    
    cout << table->getSize() << endl;
    */
    
    //10,8,7,8,6,10
    LinkedList* head = new LinkedList(10);
    head->insertNode(8, "first");
    head->insertNode(7, "second");
    head->insertNode(8, "third");
    head->insertNode(6, "fourth");
    head->insertNode(10, "fifth");
    
    
    head->displayList();
    /*
    HashTable* table = new HashTable;
    
    Node* currNode = head->getHead();
    Node* prevNode = NULL;
    
    while (currNode)
    {
        string thekey = to_string(currNode->value);
        if (table->lookup(thekey) == -1)
        {
            table->storeKey(thekey, 1);
            prevNode = currNode;
            currNode = currNode->next;
        }
        else
        {
            
            prevNode->next = currNode->next;
            Node* temp = currNode;
            currNode = currNode->next;
            delete temp;
        }
        
    }
    */
    
    Node* currNode = head->getHead();
    
    
    while (currNode)
    {
        Node* runner = currNode->next;
        Node* prevRunner = currNode;
        while (runner)
        {
            if (runner->value == currNode->value)
            {
                prevRunner->next = runner->next;
                Node* temp = runner;
                runner = runner->next;
                delete temp;
            }
            else
            {
                prevRunner = prevRunner->next;
                runner = runner->next;
            }
        }
        
        currNode = currNode->next;
        
    }
    
    head->displayList();
    
    
    return 0;
}





