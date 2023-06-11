//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
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
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Node* result = findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends


/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

Node* findIntersection(Node* head1, Node* head2)
{
   map<int,int> m;
    // Store all the value of node in map
    while(head1!=NULL){
        m[head1->data]++;
        head1=head1->next;
    }

while(head2 !=NULL){
        m[head2->data]++;
        head2=head2->next;
    }

// make new node as ans and initially store 0 in it.
    Node* ans= new Node(0);

    Node* cur=ans;

//traverse the map and extract all the element greater than 1.
    for(auto i:m){
        if(i.second>=2){

// if there are same duplicate element in both the lists then we will store the element   i.second/2 number of times       

int t=i.second/2;

 while(t--){
            Node* temp=new Node(i.first);
            cur->next=temp;
          cur=cur->next;
        }
        }
    }

//delete the first node as we stored 0 in ans node
    cur =ans;
    ans=ans->next;
    free(cur);
    return ans; 
}