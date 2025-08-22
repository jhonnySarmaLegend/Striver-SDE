/*
  Question Link --> https://leetcode.com/problems/rotate-list/description/
*/

   ListNode* rotateRight(ListNode* head, int k) {

        if(head==NULL||k==0)return head; // NULL LL or k==0

        ListNode* temp=head;
        int count=1;
        while(temp->next!=NULL){
            count++;temp=temp->next;
        }

        k=k%count;    // k==n
        if(k==0)return head;
        
        temp=head;
        while(temp->next!=NULL){
             temp=temp->next;
        }
        temp->next=head;//last node to 1st
        k=k-1;//since head at node 1
     
        for(int i=1;i<count-k;i++)temp=temp->next;
        head=temp->next;
        temp->next=NULL;
        return head;

    }

/*
  Time Complexity: O(length of list) + O(length of list - (length of list%k))

Reason: O(length of the list) for calculating the length of the list. O(length of the list - (length of list%k)) for breaking link.

Space Complexity: O(1)

Reason: No extra data structure is used for computation.
*/
