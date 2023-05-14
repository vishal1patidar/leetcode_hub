//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
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
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
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
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:
    queue<Node* > q;
    unordered_map<Node*, Node* > par;
    unordered_map<Node*, bool> vis;
    Node* targetNode = NULL;
    
public:
    void parent(Node* root) {
        q.push(root);
        while( !q.empty() ) {
            root = q.front(); q.pop();
            if(root->left) {
                q.push(root->left);
                par[root->left] = root;
            }
            if(root->right) {
                q.push(root->right);
                par[root->right] = root;
            }
        }
    }
    void getTargetNode(Node* root, int target) {
        if(root == NULL) 
            return;
        if(target == root->data)
        {
            targetNode = root;
            return;
        }
        getTargetNode(root->left, target);
        getTargetNode(root->right, target);
    }
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // Create a graph like structure for raidal traversal
        parent(root);
        getTargetNode(root, target);
        
        // Radial Level Order - Just like graph traversal 3 direction traversal, graph can have                 infinite so we can use 3 loop in case of graph
        q.push(targetNode);
        vis[targetNode] = true;
        
        // Declaration
        vector<vector<int>>radialTraversal;
        vector<int> res;
        int currLevel = 0;
        
        while(!q.empty()){
            int size = q.size();
            currLevel++;
            vector<int> radialLevel;
            for(int i = 0 ; i < size ; i++){
                Node* currNode = q.front(); q.pop();
                
                
                // Three Directions possible
                if(currNode -> left && !vis[currNode -> left]){
                    q.push(currNode -> left);
                    vis[currNode -> left] = 1;
                }
                
                if(currNode -> right && !vis[currNode -> right]){
                    q.push(currNode -> right);
                    vis[currNode -> right] = 1;
                }
                
                if(par[currNode] && !vis[par[currNode]]){
                    q.push(par[currNode]);
                    vis[par[currNode]] = 1;
                }
                
                radialLevel.push_back(currNode -> data);
            }
            radialTraversal.push_back(radialLevel);
        }
        sort(radialTraversal[k].begin(), radialTraversal[k].end());
        return k < radialTraversal.size() ? radialTraversal[k] : res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends