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

void display(ListNode* head)
{
    ListNode* cur = head;
    while (head != NULL)
    {
        cout << cur->val << " ";
        cur = cur->next;

    }

    cout << endl;
}

ListNode* reverse(ListNode* head)
{
    ListNode* prev = NULL;
    ListNode* next;

    while (head != NULL)
    {
        next = head->next;

        head->next = prev;

        prev = head;
        head = next;
    }

    return prev;
}

bool isPalindrome(ListNode* head) 
{
    ListNode* cur = head;
    int size = 0;

    //get size
    while (cur != NULL)
    {
        cur = cur->next;
        size++;
    }
    

    // middle node
    cur = head;
    int middle = size / 2;
    int index = 1;
    while (index < middle)
    {
        cur = cur->next;
        index++;
    }
    ListNode* middle_node = cur;

    if (size % 2 != 0)
        middle_node = cur->next;

    cout << "-------";
    cout << middle_node->val << endl;

    //split the original list to 2 sub lists
    ListNode* head1 = head;
    ListNode* head2 = middle_node->next;
    middle_node->next = NULL;

    ListNode* start1 = reverse(head1);
   // cout << start1->val << endl;

    //skip the first one
    if (size % 2 != 0)
    {
        start1 = start1->next;
    }
    cout << start1->val << endl;
   // display(start1);
   // display(head2);

    while (start1!= NULL)
    {
        if (start1->val != head2->val)
            return false;

        start1 = start1->next;
        head2 = head2->next;
    }

    return true;
       

}


int main()
{
    ListNode* head = new ListNode(3, NULL);
    ListNode* second = new ListNode(1, NULL);
    ListNode* third = new ListNode(1, NULL);
    ListNode* fourth = new ListNode(3, NULL);
   // ListNode* fifth = new ListNode(3 ,NULL);
    head->next = second;
    second->next = third;
    third->next = fourth;
    //fourth->next = fifth;

    cout << isPalindrome(head) << endl;



    return 0;
}
