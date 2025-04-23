/*
  Question Link --> https://leetcode.com/problems/linked-list-cycle-ii/description/
*/

// Using Set ,  T.C. & S.C. =O(N)
ListNode *detectCycle(ListNode *head) {
        ListNode* temp=head;
        set<ListNode*> st;
        
        while(temp!=NULL){
            if(st.find(temp)!=st.end())return temp;

            st.insert(temp);
            temp=temp->next;
        }

        return NULL;
    }

//OPTIMAL  --> slow & fast
// T.C.= O(N) , S.C. = O(1)
ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast){
                fast=head;
                while(slow!=fast){
                     slow=slow->next;
                     fast=fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
