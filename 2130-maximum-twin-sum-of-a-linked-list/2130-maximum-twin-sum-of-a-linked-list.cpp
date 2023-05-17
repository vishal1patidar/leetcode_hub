class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow=head,*fast=head;
        ListNode* p;
        while(fast && fast->next){
            p=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* curr = slow;
        ListNode* prev = NULL, *next = NULL;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        p->next=prev;
        ListNode* q=head;
        int ans=INT_MIN;
        while(prev){
            int sum=0;
            sum=prev->val+q->val;
            ans=max(ans,sum);
            prev=prev->next;
            q=q->next;
        }
        return ans;
    }
};