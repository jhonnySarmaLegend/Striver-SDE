// User function template for C++


/// Question Link --> https://www.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/


// Input: Linked list: 17->15->8->9->2->4->6
//Output: 8->2->4->6->17->15->9
// even --> odd

Node* divide(Node* head) {
        // code here
        Node *even=new Node(-1);
        Node *temp1=even;
        Node *odd=new Node(-1);
        Node *temp2=odd;
        
        Node *temp=head;
        while(temp){
            if(temp->data%2==0){
                temp1->next=temp;
                temp1=temp1->next;
            }
            else{
                temp2->next=temp;
                temp2=temp2->next;
            }
            temp=temp->next;
        }
        
        temp1->next=odd->next;
        temp2->next=NULL;
        return even->next;
    }
