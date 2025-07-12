/*
   Question link --> https://leetcode.com/problems/add-two-numbers/description/
*/

// T.C. = O(max(m,n)) , S.C. = O(max(m,n))
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* temp1=l1;  
        ListNode* temp2=l2;

        ListNode* node=new ListNode(0);
        ListNode* ans=node;
        int carry=0;

        while(temp1!=NULL || temp2!=NULL || carry!=0){
            int sum=carry;
            // temp1 exists
            if(temp1!=NULL){
                 sum+=temp1->val;
                 temp1=temp1->next;
            }
            // temp2 exists
            if(temp2!=NULL){
                 sum+=temp2->val;
                 temp2=temp2->next;
            }
            
            carry=sum/10;
            ListNode* newNode=new ListNode(sum%10);
            node->next=newNode;
            node=node->next;//or node=newNode;

        }
        return ans->next;

    }
