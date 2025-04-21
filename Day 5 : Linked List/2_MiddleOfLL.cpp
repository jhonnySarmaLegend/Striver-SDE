/*
  Question Link --> https://leetcode.com/problems/middle-of-the-linked-list/description/
*/


//OPTIMAL --> O(N/2) 
 ListNode* middleNode(ListNode* head) {
        if(head==NULL||head->next==NULL)return head;
        
        ListNode* slow=head;
        ListNode* fast=head;
       
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        return slow;
    }


// BRUTE FORCE --> O(N+N/2)
Node *findMiddle(Node *head) {
    // If the list is empty or has only
    // one element, return the head as
    // it's the middle.
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* temp = head;
    int count = 0;

    // Count the number of nodes in the linked list.
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    // Calculate the position of the middle node.
    int mid = count / 2 + 1;
    temp = head;

    // Traverse to the middle node by moving
    // temp to the middle position.
    while (temp != null) {
        mid = mid - 1;

        // Check if the middle
        // position is reached.
        if (mid == 0){
            // break out of the loop
            // to return temp
            break;
        }
        // Move temp ahead
        temp = temp->next;
    }

    // Return the middle node.
    return temp;
}
