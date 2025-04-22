/*
   Question Link --> https://leetcode.com/problems/intersection-of-two-linked-lists/description/
*/

// Good Solution using set
// T.C. = O(M+N) , S.C.=O(M)
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> st;
        while(headA!=NULL){
            st.insert(headA);
            headA=headA->next;
        }
          while(headB!=NULL){
           if(st.find(headB)!=st.end())return headB;
            headB=headB->next;
        }
        return NULL;
    }

// OPTIMAL SOLUTION
//  Time Complexity: O(2*max(length of list1,length of list2))

// Reason: Uses the same concept of the difference of lengths of two lists.

// Space Complexity: O(1)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       ListNode* tempA=headA;
       ListNode* tempB=headB;
       //In question said, no cycle and 1 intersection always present
       while(tempA!=NULL || tempB!=NULL){
        if(tempA==tempB)return tempA;
      
        if(tempA==NULL)tempA=headB;
        else{
            tempA=tempA->next;
        }

        if(tempB==NULL)tempB=headA;
        else{
              tempB=tempB->next;
        }

       }

       return NULL;
    }


//In small
node* intersectionPresent(node* head1,node* head2) {
    node* d1 = head1;
    node* d2 = head2;
    
    while(d1 != d2) {
        d1 = d1 == NULL? head2:d1->next;
        d2 = d2 == NULL? head1:d2->next;
    }
    
    return d1;
}
