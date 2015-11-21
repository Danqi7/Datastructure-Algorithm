#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Node
{
	int value;
	Node* next;
};

class LinkedList
{
private:
	int size;
	Node* head;

public:
	LinkedList()
	{
		size = 0;
		head = NULL;
	}

	Node* getHead()
	{
		return head;
	}

	bool insertNode(int value, int index)
	{
		if (index < 0)
			return false;

		Node* currnode = head;

		for (int i = 1; currnode != NULL && i < index; i++)
		{
			currnode = currnode->next;
		}

		if (currnode == NULL && head != NULL) // index out of range
			return false;

		Node* new_node = new Node;
		new_node->value = value;
		new_node->next = NULL;

		if(index == 0)
		{
			//insert at the beginning
			new_node->next = head;
			head = new_node;
		}
		else
		{
			new_node->next = currnode->next;
			currnode->next = new_node;
		}

		return true;
	}
	//find node with the input value and return its index at the linked list
	int findNode(int value)
	{
		Node* currnode = head;
		int i;

		for (i = 1; currnode != NULL && currnode->value != value; i++)
			currnode = currnode->next;

		if (currnode == NULL)
			return -1;
		else
			return i;

	
	}

	bool deleteNode(int value)
	{
		Node* currnode = head;
		Node* prevnode = NULL;

		int index = findNode(value);

		if (index != -1)
		{
			for (int i = 1; i < index; i++)
			{
				prevnode = currnode;
				currnode = currnode->next;
			}
		

			if (currnode == head) //delete the head
			{
				Node* temp = head;
				head = head->next;
				delete temp;
			}
			else
			{
				prevnode->next = currnode->next;
				delete currnode;
			}

			return true;
		}

		return false;
	}

	void displayList()
	{
		Node* currnode = head;
		while (currnode != NULL)
		{
			cout << currnode->value << endl;
			currnode = currnode->next;
		}
	}


};


int main()
{	

	LinkedList list = LinkedList();
	list.insertNode(9,0);
	list.insertNode(2,1);
	list.insertNode(3,2);
	list.insertNode(3,3);
	list.insertNode(10,4);
	list.insertNode(9,5);
	list.insertNode(9,6);
	list.insertNode(3,7);	

	list.displayList();

	map<int, int> table;
	Node* currnode = list.getHead();
	while (currnode != NULL)
	{
		if (table.find(currnode->value) == table.end())
			table[currnode->value] = 1;
		else
		{
			cout << currnode->value << " ";
			list.deleteNode(currnode->value);
		}
		currnode = currnode->next;
	}

	cout << "-------" << endl;
	list.displayList();

	return 0;
}