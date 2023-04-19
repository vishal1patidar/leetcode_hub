class Solution {
   public:
    void helper(TreeNode* root, int &ans, int left, int right){
        if(!root)   return;
        ans = max(ans, max(left,right));
        helper(root->left,ans,0,left+1);
        helper(root->right,ans,right+1,0);
    }
    
    int longestZigZag(TreeNode* root) {
        int ans = 0;
        helper(root, ans, 0, 0);
        return ans;
    }
};