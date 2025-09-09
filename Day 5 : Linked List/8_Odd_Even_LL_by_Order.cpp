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


/*

Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]

*/


class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        
        if(head==NULL || head->next==NULL)return head;//0 and 1 element element

        ListNode* temp=head;
        ListNode *odd=head;//odd 
        ListNode *even=head->next;//even
        ListNode* evenHead=even;

        while(even!=NULL && even->next!=NULL){
            odd->next=even->next;
            odd=odd->next;

            even->next=even->next->next;
            even=even->next;
        }
        odd->next=evenHead;
        return head;
    }
};
