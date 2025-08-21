/*
   Question Link --> https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
*/
// OPTIMAL --> T.C. = O(N) , S.C. = O(1)
ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow=head;
        ListNode* fast=head;

        for(int i=0;i<n;i++)fast=fast->next;

        //so difference between fast and slow is k or n units
        if(fast==NULL)return head->next;

       //when fast is at last node  , slow will be at n-1th node from last
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
  
        slow->next=slow->next->next;
  
        return head;
    }





// BRUTE FORCE 
//  T.C. = O(L)+O(L-N) , S.C. = O(1)
Node* DeleteNthNodefromEnd(Node* head, int N) {
    if (head == NULL) {
        return NULL;
    }
    int cnt = 0;
    Node* temp = head;

    // Count the number of nodes in the linked list
    while (temp != NULL) {
        cnt++;
        temp = temp->next;
    }

    // If N equals the total number of
    // nodes, delete the head
    if (cnt == N) {
        Node* newhead = head->next;
        delete (head);
        return newhead;
    }

    // Calculate the position of the node to delete (res)
    int res = cnt - N;
    temp = head;

    // Traverse to the node just before the one to delete
    while (temp != NULL) {
        res--;
        if (res == 0) {
            break;
        }
        temp = temp->next;
    }

    // Delete the Nth node from the end
    Node* delNode = temp->next;
    temp->next = temp->next->next;
    delete (delNode);
    return head;
}
