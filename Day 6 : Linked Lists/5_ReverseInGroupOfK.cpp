/*
  Question Link --> https://leetcode.com/problems/reverse-nodes-in-k-group/description/
*/


//Using DEQUEUE
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k == 1) return head;
        deque<ListNode*> dq;
        ListNode * newHead = new ListNode(0);
        ListNode * cur = newHead;
        while(head){
            dq.push_back(head);
            head = head -> next;
            if(dq.size() == k){
                while(!dq.empty()){
                    cur->next = dq.back();
                    dq.pop_back();
                    cur = cur->next;
                }
                cur -> next = head;
            }
        }
        while(!dq.empty()){
            cur -> next = dq.front();
            dq.pop_front();
            cur = cur -> next;
        }
        ListNode * rst = newHead -> next;
        delete newHead;
        return rst;
    }
};

/*
1. Intuition
We want to process the list in “chunks” of k nodes.
For each full chunk, we reverse the node order.
Any leftover chunk with size < k remains in original order.
A deque (double-ended queue) lets us collect k nodes, then pop from the back to rebuild them in reverse


2. Approach
Edge Cases

If head == nullptr or k == 1, nothing changes. Return head.
Setup

Create a dummy newHead node to simplify list-building.
cur points to the tail of our rebuilt list (starts at dummy).
A deque<ListNode*> dq collects up to k pointers.
Traverse & Collect

While head is not null:
a. dq.push_back(head) and advance head = head->next.
b. If dq.size() == k, we have a full group:
Pop from back of dq, attach to cur->next, advance cur.
Repeat until dq is empty.
Link cur->next = head (the next unprocessed node).
Handle Remainder

After the main loop, any nodes left in dq (< k) must remain in order:
Pop from front, attach to cur->next, advance cur.
Cleanup & Return

rst = newHead->next is the real head.
Delete dummy and return rst.




*/





//Alternate  without extra space
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return NULL; // If the list is empty, return NULL.
        
        ListNode* temp = head, *start = head, *prevStart = NULL; // Initialize pointers for traversal.
        int counter = 1; // Counter to track nodes in the current group.

        while (temp) { // Traverse the list.
            if (counter < k) { // If the current group size is less than k, continue counting.
                counter++;
                temp = temp->next; // Move to the next node.
            }
            else { // If the current group size equals k, reverse the group.
                ListNode *curr = start->next, *prevCurr = start, *ptr; // Initialize pointers for reversing the group.

                while (counter > 1) { // Reverse the group of size k.
                    ptr = curr->next; // Store the next node of curr.
                    curr->next = prevCurr; // Reverse the link by pointing curr->next to prevCurr.
                    prevCurr = curr; // Move prevCurr to curr.
                    curr = ptr; // Move curr to ptr (next node).
                    counter--; // Decrement the counter.
                }

                start->next = curr; // Connect the reversed group to the rest of the list.

                if (prevStart) prevStart->next = temp; // Connect the previous reversed group to the current reversed group.
                if (!prevStart) { // If prevStart is NULL (first group), update the head of the list.
                    head = prevCurr;
                }

                prevStart = start; // Update prevStart to the end of the current reversed group.
                temp = curr; // Move temp to the next group's starting node.
                start = temp; // Update start to the next group's starting node.
            }
        }

        return head; // Return the modified list head.
    }
};






//ANOTHER WAY


//HARD QUESTION
/*
  Time Complexity: O(2N) The time complexity consists of actions of reversing segments of K and finding the Kth node which operates in linear time. Thus, O(N) + O(N) = O(2N), which simplifies to O(N).

Space Complexity: O(1) The space complexity is O(1) as the algorithm operates in place without any additional space requirements.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

// This function has been explained
// in previous videos/articles

// Function to reverse a linked list
// using the 3-pointer approach
ListNode* reverseLinkedList(ListNode *head)
{
   // Initialize'temp' at
   // head of linked list
   ListNode* temp = head;  
   
   // Initialize pointer 'prev' to NULL,
   // representing the previous node
   ListNode* prev = NULL;  
   
   // Traverse the list, continue till
   // 'temp' reaches the end (NULL)
   while(temp != NULL){  
       // Store the next node in
       // 'front' to preserve the reference
       ListNode* front = temp->next;  
       
       // Reverse the direction of the
       // current node's 'next' pointer
       // to point to 'prev'
       temp->next = prev;  
       
        // Move 'prev' to the current
        // node for the next iteration
       prev = temp;  
       
        // Move 'temp' to the 'front' node
        // advancing the traversal
       temp = front; 
   }
   
   // Return the new head of
   // the reversed linked list
   return prev;  
}

// Function to get the Kth node from
// a given position in the linked list
ListNode* getKthNode(ListNode* temp, int k){
    // Decrement K as we already
    // start from the 1st node
    k -= 1; 

    // Decrement K until it reaches
    // the desired position
    while(temp != NULL && k > 0){
        // Decrement k as temp progresses
        k--; 
        
        // Move to the next node
        temp = temp -> next; 
    }
    
    // Return the Kth node
    return temp; 
}

// Function to reverse nodes in groups of K
ListNode* reverseKGroup(ListNode* head, int k){
    // Initialize a temporary
    // node to traverse the list
    ListNode* temp = head; 

    // Initialize a pointer to track the
    // ;ast node of the previous group
    ListNode* prevLast = NULL; 
    
    // Traverse through the linked list
    while(temp != NULL){
        // Get the Kth node of the current group
        ListNode* kThNode = getKthNode(temp, k); 

        // If the Kth node is NULL
        // (not a complete group)
        if(kThNode == NULL){
            // If there was a previous group,
            // link the last node to the current node
            if(prevLast){
                prevLast -> next = temp; 
            }
            
            // Exit the loop
            break; 
        }
        
        // Store the next node
        // after the Kth node
        ListNode* nextNode = kThNode -> next; 

        // Disconnect the Kth node
        // to prepare for reversal
        kThNode -> next = NULL; 

        // Reverse the nodes from
        // temp to the Kth node
        reverseLinkedList(temp); 
        
        // Adjust the head if the reversal
        // starts from the head
        if(temp == head){
            head = kThNode;
        }else{
            // Link the last node of the previous
            // group to the reversed group
            prevLast -> next = kThNode; 
        }

        // Update the pointer to the
        // last node of the previous group
        prevLast = temp; 

        // Move to the next group
        temp = nextNode; 
    }
    
    // Return the head of the
    // modified linked list
    return head; 
}

   
};
