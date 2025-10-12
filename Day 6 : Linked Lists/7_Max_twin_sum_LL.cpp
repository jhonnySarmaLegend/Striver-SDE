// Link --> https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/

class Solution {
  
    ListNode* revList(ListNode* head){
    ListNode* prev = NULL;
    ListNode* next =NULL;
    while(head != NULL){
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

public:
     int pairSum(ListNode* head) {
        int maxi=INT_MIN;
       // step 1 find middle of the even length LL
       ListNode *slow=head;
       ListNode *fast=head;
       
       while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;

       }
       //slow at middle
       slow=slow = revList(slow); // STEP 2 --> reverse from middle 
       fast=head;
       while(slow!=NULL){
        maxi=max(maxi,slow->val+fast->val); // step 3 --> check for max  twin pairs
        slow=slow->next;
        fast=fast->next;
       }
       return maxi;

     }
};

