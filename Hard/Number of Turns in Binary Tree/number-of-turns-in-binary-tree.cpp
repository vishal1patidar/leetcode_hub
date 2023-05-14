//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
      
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
          
        // Get the current node's value from the string
        string currVal = ip[i];
          
        // If the left child is not null
        if(currVal != "N") {
            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }
          
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
          
        // If the right child is not null
        if(currVal != "N") {
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function template for C++
/*
Structure of the node of the tree is as follows 
struct Node {
    struct Node* left, *right;
    int data;
};
*/

class Solution{
  public:
   struct Node* lowestCommonAncestor(struct Node* root, int p, int q) 
    {
        if(root==NULL || root->data==p || root->data==q) return root;
        struct Node* left  = lowestCommonAncestor(root->left,p,q);
        struct Node* right = lowestCommonAncestor(root->right,p,q);
        if(left==NULL) return right;
        else if(right == NULL) return left;
        else return root;
    }
    void solve(struct Node* root,int count,int dir,int num,int &ans)
    {
        if(!root)return;
        if(root->data==num)
        {
            ans=count;
            return;
        }
        solve(root->left,count+(dir!=0),0,num,ans);
        solve(root->right,count+(dir!=1),1,num,ans);
    }
    int NumberOFTurns(struct Node* root, int p, int q)
    {
      struct Node* lca=lowestCommonAncestor(root,p,q);
      int count=0;
      int ans=0;
      solve(lca,count,-1,p,ans);
      int pans=--ans;
      ans=0;
      count=0;
      solve(lca,count,-1,q,ans);
      int qans=--ans;
      if(lca->data==p)
      {
          if(qans!=0)return qans;
          else return -1;
      }
      else if(lca->data==q)
      {
          if(pans!=0)return pans;
          else return -1;
      }
      else return pans+qans+1;
    return 0;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    struct Node *child;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        int turn, first, second;
        cin>>first>>second;
        Solution ob;
        if ((turn = ob.NumberOFTurns(root, first, second) ))
            cout<<turn<<endl;
        else 
            cout<<"-1\n";
        cin.ignore();
    }
    return 0;
}

// } Driver Code Ends