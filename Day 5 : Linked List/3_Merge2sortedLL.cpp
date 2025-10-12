/*
  Question Link --> https://leetcode.com/problems/merge-two-sorted-lists/description/
*/



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

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)return list2;
        if(list2==NULL)return list1;
        if(list1==NULL && list2==NULL)return NULL;

        ListNode *dummy=new ListNode(-1);
        ListNode *temp=dummy;

        while(list1 && list2){
            if(list1->val<=list2->val){
                temp->next=list1;
                list1=list1->next;
            }
            else{
                temp->next=list2;
                list2=list2->next;
            }
            temp=temp->next;
        }
 
        if (list1) temp->next = list1;
        if (list2) temp->next = list2;
        
        return dummy->next;
 
    }


//OR
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL && list2==NULL)return NULL;
        if(list1==NULL && list2!=NULL)return list2;
        if(list1!=NULL && list2==NULL)return list1;

        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;

        while(list1 && list2){
            if(list1->val<=list2->val){
                temp->next=list1;
                list1=list1->next;
                temp=temp->next;
            }
            else{
                temp->next=list2;
                list2=list2->next;
                temp=temp->next;
            }
        }

        //use 2 while loops
        while(list1){
                temp->next=list1;
                list1=list1->next;
                temp=temp->next;
        }
        while(list2){
                temp->next=list2;
                list2=list2->next;
                temp=temp->next;
        }
        temp->next=NULL;
        
        return dummy->next;
    }
};


// brute force
// put both in set and make LL from set
// T.C. =O(2(N+M)) , S.C.=O(N+M)
 vector<int> ans;
        ListNode* temp=l1;
        while(temp){
           ans.push_back(temp->val);temp=temp->next;
        }
        temp=l2;
 while(temp){
           ans.push_back(temp->val);temp=temp->next;
        }


        sort(ans.begin(),ans.end());

        ListNode* head=new ListNode(-1);
        ListNode* curr=head;

        for(auto it:ans){
              ListNode* node=new ListNode(it);
              curr->next=node;
              curr=curr->next;
        }
        return head->next;



//Optimal --> One pass Both LL  --> T.C. = O(N+M) , S.C.=O(1)
 ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        
        if(head1==NULL && head2==NULL)return NULL;
        if(head1!=NULL && head2==NULL)return head1;
        if(head1==NULL && head2!=NULL)return head2;
        
        ListNode* temp1=head1;
        ListNode* temp2=head2;

        ListNode* node=new ListNode(0);
        ListNode* ans=node;

        while(temp1 && temp2){

           if(temp1->val<=temp2->val){
            node->next=temp1;
            temp1=temp1->next;
            node=node->next;
           }else{
             node->next=temp2;
            temp2=temp2->next;
            node=node->next;
           }

        }

        if(temp1!=NULL){
            node->next=temp1;
            temp1=temp1->next;
        }

        if(temp2!=NULL){
            node->next=temp2;
            temp2=temp2->next;
        }

        return ans->next;

    }



// USING RECURSION
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
  {
		// if list1 happen to be NULL
		// we will simply return list2.
		if(l1 == NULL)
        {
			return l2;
		}
		
		// if list2 happen to be NULL
		// we will simply return list1.
		if(l2 == NULL)
        {
			return l1;
		} 
		
		// if value pointend by l1 pointer is less than equal to value pointed by l2 pointer
		// we wall call recursively l1 -> next and whole l2 list.
		if(l1 -> val <= l2 -> val)
        {
			l1 -> next = mergeTwoLists(l1 -> next, l2);
			return l1;
		}
		// we will call recursive l1 whole list and l2 -> next
		else
        {
			l2 -> next = mergeTwoLists(l1, l2 -> next);
			return l2;            
		}
	}
};	
