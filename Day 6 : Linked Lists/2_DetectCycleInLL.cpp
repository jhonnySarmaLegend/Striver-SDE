/*

*/

//OPTIMAL SOLUTION
//slow & fast pointer  , T.C.=O(N) , S.C.=O(1) 
    bool hasCycle(ListNode *head) {
        if(head==NULL||head->next==NULL)return false;//0 or 1 element

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL && fast->next!=NULL){
            
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast)return true;
        }
        return false;

    }


// GOOD solution using SET
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> st;
        ListNode* temp=head;
        while(temp!=NULL){
            if(st.find(temp)!=st.end())return true;
            
            st.insert(temp);
            temp=temp->next;
        }
        return false;        

    }
