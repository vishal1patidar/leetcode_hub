class Solution {
public:
    void it(ListNode* &t,int v){
        ListNode* s=new ListNode(v);
        t->next=s;
        t=t->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& l) {
        vector<int>v;
        if(l.size()==0){//base case
            return NULL;
        }
        for(int p=0;p<l.size();p++){
            ListNode* a=l[p];
            while(a){
                v.push_back(a->val);
                a=a->next;
            }
        }
        if(v.size()==0){
            return NULL;
        }
        sort(v.begin(),v.end());
		//sorted vector
        ListNode* s=new ListNode(v[0]);
        ListNode* t=s;
        for(int p=1;p<v.size();p++){
            it(t,v[p]);//adding to tail
        }
        return s;
    }
};