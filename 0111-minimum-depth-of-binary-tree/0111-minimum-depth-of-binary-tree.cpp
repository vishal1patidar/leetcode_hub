class Solution {
public:
    int dfs(TreeNode* root) {
        if (root == NULL)
        {
            return 0;
        }
        
        if (!root->left) 
        {
            return 1 + dfs(root->right);
        } 
        else if (!root->right)
        {
            return 1 + dfs(root->left);
        }
        
        return 1 + min(dfs(root->left), dfs(root->right));
    }
    
    int minDepth(TreeNode* root) {
        return dfs(root);
    }
};