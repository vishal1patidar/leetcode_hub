class Solution {
public:
    int cnt=0;
    int countNodes(TreeNode*root,int prev){
        if(!root)return 0;
        if(prev<=root->val){
            cnt++;
        }
        countNodes(root->left,max(prev,root->val));
        countNodes(root->right,max(prev,root->val));
        return cnt;

    }
    int goodNodes(TreeNode* root) {
        return countNodes(root,INT_MIN);
    }
};