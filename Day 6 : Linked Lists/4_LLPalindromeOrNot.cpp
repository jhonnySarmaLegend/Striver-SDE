/*
   Question Link --> https://leetcode.com/problems/palindrome-linked-list/description/
*/

//BRUTE FORCE
bool isPalindrome(ListNode* head) {
        vector<int> num;
        while(head){
            num.push_back(head->val);
            head=head->next;
        }
        vector<int> numRev(num.rbegin(),num.rend());
        return num==numRev;  
    }

//OPTIMAL
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
  
    ListNode* rev(ListNode* head){
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL){
            ListNode* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
         return prev;
    }
   

    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;

       //to stop at 1 node before middle
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

       ListNode* prev= rev(slow->next);
       slow->next=prev;

       ListNode* temp1=head;
       ListNode* temp2=prev;

       while(temp2!=NULL){
        if(temp1->val!=temp2->val)return false;

        temp1=temp1->next;
         temp2=temp2->next;

       }

       return true;

    }
};
