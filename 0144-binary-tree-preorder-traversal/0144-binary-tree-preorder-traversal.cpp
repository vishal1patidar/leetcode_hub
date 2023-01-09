class Solution {
public:
    
    // Declairing global variable ans so that we don't declare it again and again and affect the SC by some factors
    vector<int> ans;

    void preorder(TreeNode* root) {
       
        if(root==NULL) {
            return;
        }
        
        // cout << root->val << " ";
        ans.push_back(root->val);
        preorder(root->left);
        preorder(root->right);        
    }
    
    // Recieve the preorder sequence from preorder() and return it
    vector<int> preorderTraversal(TreeNode* root) {

        preorder(root);
        return ans;
    }
};