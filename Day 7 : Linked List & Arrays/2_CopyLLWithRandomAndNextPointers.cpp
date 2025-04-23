//HARD
/*
  Question Link --> https://leetcode.com/problems/copy-list-with-random-pointer/description/
*/

/*
  Time Complexity: O(3N)where N is the number of nodes in the linked list. The algorithm makes three
  traversals of the linked list, once to create copies and insert them between original nodes, then to set the
  random pointers of the copied nodes to their appropriate copied nodes and then to separate the copied and original nodes.

  Space Complexity : O(N) where N is the number of nodes in the linked list as the only extra additional space allocated 
  it to create the copied list without creating any other additional data structures.
*/

    Node* copyRandomList(Node* head) {
        // 1. Insert Node in between
        Node* temp = head;
        while(temp!=NULL){
            //adding node in b/w
            Node* node=new Node(temp->val);
            node->next=temp->next;
            temp->next=node;
            //moving temp to next node to copy
            temp=temp->next->next;
        }
        
        //2. Connect random pointers
        temp=head;
        while(temp!=NULL){
            if(temp->random){
                temp->next->random=temp->random->next;
            }
            else{
                temp->next->random==NULL;
            }
             // Move to the next original node
             temp = temp->next->next;  
        }

        //3. connecting next pointers
        temp=head;
        Node* dummy=new Node(0);
        Node* res=dummy;

        while(temp!=NULL){
            //new copy LL
            res->next=temp->next;
            res=res->next;
            //making original LL in given form
            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummy->next;
    }
