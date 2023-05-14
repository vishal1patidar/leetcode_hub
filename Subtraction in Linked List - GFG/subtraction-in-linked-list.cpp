//{ Driver Code Starts
// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

Node* subLinkedList(Node* l1, Node* l2);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        
        Node* res = subLinkedList(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends


/* Structure of linked list Node

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

*/

//You are required to complete this method

pair<Node*,int> reverse(Node* head)

{

        if(head==NULL)

        {

            return make_pair(head,0);

        }

        

        Node* curr = head;

        Node* prev = NULL;

        Node* forward = NULL;

        int count = 0;

        int zero = 0;

        while(curr!=NULL)

        {

            if(curr->data==0)

            {

                zero++;

            }

            count++;

            forward = curr->next;

            curr->next = prev;

            prev = curr;

            curr = forward;

        }

        

        if(zero==count)

        {

            return make_pair(prev,-1);

        }

        return make_pair(prev,count);

}

Node* solve(Node* head1,Node* head2)

{

    Node* ans = new Node(-1);

    Node* tail = ans;

    int borrow = 0;

    while(head1!=NULL)

    {

        int t1 = head1->data;

        int t2 = head2->data;

        int diff = 0;

        if(t1<t2)

        {

            t1 = t1 + 10;

            diff = t1 - t2 - borrow;

            borrow=1;

        }

        else if(t1>t2)

        {

            diff = t1 - t2 - borrow;

            borrow = 0;

        }

        else

        {

            if(borrow)

            {

                t1 = t1 + 10;

                diff = t1 - t2 - borrow;

                borrow = 1;

            }

            else

                diff = t1 - t2;

        }

        Node* newNode  = new Node(diff);

        tail->next = newNode;

        tail = newNode;

        head1 = head1->next;

        head2 = head2->next;

    }

    return ans->next;

}

 

Node* check(Node* head)

{

    while(head->data==0&&head->next!=NULL)

    {

        head = head->next;

    }

    return head;

}

 

Node* subLinkedList(Node* l1, Node* l2)

{

    //Your code here

    l1 = check(l1);

    l2 = check(l2);

    Node* tail1 = l1;

    Node* tail2 = l2;

    pair<Node*,int> newL1 = reverse(l1);

    pair<Node*,int> newL2 = reverse(l2);

    l1 = newL1.first;

    int count1 = newL1.second;

    l2 = newL2.first;

    int count2 = newL2.second;

    bool oneTotwo = true;

    if(count1>count2)

    {

        oneTotwo = true;

        int diff = count1-count2;

        while(diff)

        {

            Node* zero = new Node(0);

            tail2->next = zero;

            tail2 = zero;

            diff--;

        }

    }

    else if(count1<count2)

    {

        oneTotwo = false;

        int diff = count2-count1;

        while(diff)

        {

            Node* zero1 = new Node(0);

            tail1->next = zero1;

            tail1 = zero1;

            diff--;

        }

    }

    else

    {

        if(tail1->data < tail2->data)

        {

            oneTotwo = false;

        }

    }

    pair<Node*,int>ans;

    if(oneTotwo)

    {

        ans = reverse(solve(l1,l2));

        if(ans.second==-1)

        {

            Node* newNode = new Node(0);

            return newNode;

        }

        return check(ans.first);

    }

    else

    {

        ans = reverse(solve(l2,l1));

        if(ans.second==-1)

        {

            Node* newNode = new Node(0);

            return newNode;

        }

        return check(ans.first);

    }

 

}