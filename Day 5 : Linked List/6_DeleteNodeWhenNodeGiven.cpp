/*
  Question Link --> https://leetcode.com/problems/delete-node-in-a-linked-list/description/
*/

//OPTIMAL SOlution --> T.C.=O(1) , S.C.=O(1)
void deleteNode(ListNode* node) { // 4,5,1,9  [5]
                                    // 4->5->1->9->x
        node->val=node->next->val; //  4->1->1->9->x , 4->1-x->1->9->x
        node->next=node->next->next; // 4->1->9->x
    }  

