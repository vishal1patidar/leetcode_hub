class Solution {
public:
   
    ListNode* reverseList(ListNode* head) {
        if(head==NULL){
           return NULL;
        }
        if(head->next==NULL){
            return head;
        }
        // -----------Base case ----------
        
        ListNode* temp = head->next;
  
        //----------- store  2  node  in temp for example one ----------

        ListNode* temp1 = reverseList(temp);

        //----------- we will call the  reverseList for 2,3,4,5  ----------


        ListNode* temp2 = temp1;
        //we store the result temp2 and from this while loop we will go to the end 
        while(temp2->next!=NULL){
         temp2=temp2->next;
         }

         //whatever the result(5 ,4 ,3 ,2) we will append the next node head(1) to next of it

        temp2->next=head;
        //(5 ,4 ,3 ,2->1) 
        head->next=NULL;
        //(1->null)
        return  temp1;
    }
};


