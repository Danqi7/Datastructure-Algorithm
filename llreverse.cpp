#include <iostream>

using namespace std;

class ListNode
{
public:
    int val;
    ListNode* next;

    ListNode(int value, ListNode* n)
    {
        val = value;
        next = n;
    }
};


ListNode* reverse(ListNode* head)
{
	ListNode* prev = NULL;
	ListNode* next;
	while(head != NULL)
	{
		next = head->next;

		head->next = prev;

		//update head and pre
		prev = head;
		head = next;
	}

	return prev;
}

int main()
{
	ListNode* head = new ListNode(1, NULL);
    ListNode* second = new ListNode(2, NULL);
    ListNode* third = new ListNode(3, NULL);
    ListNode* fourth = new ListNode(4, NULL);
    head->next = second;
    second->next = third;
    third->next = fourth;

    ListNode* cur = reverse(head);

    while (cur != NULL)
    {
    	cout << cur->val << " ";
    	cur = cur->next;

    }
    cout << "\n";


    return 0;
}