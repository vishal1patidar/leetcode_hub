class Solution {
public:
    TreeNode* constructBST(ListNode *leftHead, ListNode *rightHead) {
        if (leftHead == rightHead)
            return nullptr;
        ListNode *slow = leftHead, *fast = leftHead;
        while (fast != rightHead && fast -> next != rightHead) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        TreeNode *root = new TreeNode(slow -> val);
        root -> left = constructBST(leftHead, slow);
        root -> right = constructBST(slow -> next, rightHead);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        if (head -> next == nullptr) {
            TreeNode *root = new TreeNode(head -> val);
            return root;
        }
        return constructBST(head, nullptr);
    }
};