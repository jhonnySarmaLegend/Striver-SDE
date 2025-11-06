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
 
        while(fast->next!=NULL){ // fast will stop at 1 position before null , so slow will stop at 1 position before kth node from end
            fast=fast->next;
            slow=slow->next;
        }

        //when fast is at last node  , slow will be at n-1th node from last , hence nth node from last can be deleted.
        slow->next=slow->next->next;
  
        return head;
    }


//ALTERNATIVE
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp=head;
        int size=0;
        while(temp!=NULL){
            size++;
            temp=temp->next;
        }
        
        if(size<n)return head;
        if(size==n)return head->next;

        //if(size>n)
        int k=size-n-1;// 1 position before nth node from end
        temp=head;
        while(k--){
          temp=temp->next;
        }
        
        temp->next=temp->next->next;
        
        return head;
    }
};



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
