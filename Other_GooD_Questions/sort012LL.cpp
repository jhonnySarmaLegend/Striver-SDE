/*
  Question Link --> https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1
*/

// Solution 1 --> Overwriting the values of the nodes
// T.C. = O(2N) , S.C.=O(1)
Node* segregate(Node* head) {
        int zeroes = 0;
        int ones = 0;
        int twos = 0;
        
        Node* temp = head;
        while(temp){
            if(temp->data==0)zeroes++;
            else if(temp->data==1)ones++;
            else if(temp->data==2)twos++;
            
            temp = temp -> next;
        }
        temp = head;
        while(temp){
            if(zeroes){
                temp -> data = 0;
                zeroes--;
            }else if(ones){
                temp -> data = 1;
                ones--;
            }else{
                temp -> data = 2;
                twos--;
            }
            
            temp = temp ->  next;
        }
        return head;
    }


//SOLUTION 2 -->  Rearranging existing Nodes

 Node* segregate(Node* head) {
    // T.C. = O(N) , S.C.=O(1)
    Node* dummyZero=new Node(-1);
    Node* dummyOne=new Node(-1);
    Node* dummyTwo=new Node(-1);
    
    Node* zero=dummyZero;
    Node* one=dummyOne;
    Node* two=dummyTwo;
    
    Node* temp=head;
    while(temp!=NULL){
        if (temp->data == 0) {
            zero->next = temp;
            zero = zero->next;
        } else if (temp->data == 1) {
            one->next = temp;
            one = one->next;
        } else {
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }
    
    // Ensure the tails are properly connected
    zero->next = (dummyOne->next != NULL) ? dummyOne->next : dummyTwo->next;
    one->next = dummyTwo->next;
    two->next = NULL; // Terminate the list
    
    return dummyZero->next;
    
    }
