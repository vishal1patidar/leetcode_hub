class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head ->next == NULL){
            return head;
        }
        queue<ListNode*>q;
        ListNode* lar = head;
        while(lar != NULL){
            if(lar ->val >= x){
                break;
            }
            lar = lar ->next;
        }
        ListNode* temp = head;
        ListNode* prev = head;
        ListNode* back = NULL;
        while(temp != NULL){
            temp = temp ->next;
            if(prev ->val >=x){
                back = prev;
            }
            if(prev ->val <x){
                prev ->next = NULL;
                if(back != NULL){
                    back ->next = temp;
                }
                q.push(prev);
            }
            prev = temp;
        }
        ListNode* temp1 = NULL;
        if(q.empty()==false){
            ListNode* l = q.front();
            temp1 = l;
            q.pop();
            while(!q.empty()){
                l ->next = q.front();
                q.pop();
                l = l ->next;
            }
            if(l != NULL){
                l ->next = lar;
            }
            return temp1;
        }
        return head;
        
    }
};