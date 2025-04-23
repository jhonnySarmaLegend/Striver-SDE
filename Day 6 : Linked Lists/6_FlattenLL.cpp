//BRUTE Force
/*Algorithm / Intuition
To transform the given linked list into a single level sorted list ensuring that the nodes are arranged in an ascending order, we initialise an array to temporarily hold the extracted nodes during the traversal.

We iterate over the array by first going over the top-level next pointers of the linked list then accessing each node within its child pointers adding all to the array. Then the array is sorted to arrange all values sequentially and a new linked list from that array is created and returned.

Algorithm
Step 1:Initialise an empty array to store the data extracted during the traversal.


Step 2: Start traversing through the top-level ‘next’ pointers of the linked list and for each node accessed by the ‘next’ pointer, traverse its ‘child’ nodes.

Iterate all the nodes until reaching the end of the child pointer list appending each node’s value to the array. Move to the next primary node and repeat the process of traversing the child nodes.

Step 3: Sort the array to arrange its collected node data in ascending order.


Step 4: Create a new linked list from the sorted array and return the flattened linked list.*/

// Function to convert a vector to a linked list
Node* convertArrToLinkedList(vector<int>& arr){
    // Create a dummy node to serve as
    // the head of the linked list
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    // Iterate through the vector and
    // create nodes with vector elements
    for(int i = 0; i < arr.size(); i++){
        // Create a new node
        // with the vector element
        temp->child = new Node(arr[i]); 
        // Move the temporary pointer
        // to the newly created node
        temp = temp->child; 
    }
    // Return the linked list starting
    // from the next of the dummy node
    return dummyNode->child; 
}

// Function to flatten a
// linked list with child pointers
Node* flattenLinkedList(Node* head) {
    vector<int> arr;

    // Traverse through the linked list
    while (head != nullptr) {
        // Traverse through the child
        // nodes of each head node
        Node* t2 = head;
        while (t2 != nullptr) {
            // Store each node's data in the array
            arr.push_back(t2->data);
            // Move to the next child node
            t2 = t2->child;
        }
        // Move to the next head node
        head = head->next;
    }

    // Sort the array containing
    // node values in ascending order
    sort(arr.begin(), arr.end());

    // Convert the sorted array
    // back to a linked list
    return convertArrToLinkedList(arr);
}


//OPTIMAL
// Merges two linked lists in a particular
// order based on the data value
Node* merge(Node* list1, Node* list2){
    // Create a dummy node as a
    // placeholder for the result
    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;

    // Merge the lists based on data values
    while(list1 != NULL && list2 != NULL){
        if(list1->data < list2->data){
            res->child = list1;
            res = list1;
            list1 = list1->child;
        }
        else{
            res->child = list2;
            res = list2;
            list2 = list2->child;
        }
        res->next = NULL;
    }

    // Connect the remaining
    // elements if any
    if(list1){
        res->child = list1;
    } else {
        res->child = list2;
    }

    // Break the last node's
    // link to prevent cycles
    if(dummyNode->child){
        dummyNode->child->next = NULL;
    }

    return dummyNode->child;
}

// Flattens a linked list with child pointers
Node* flattenLinkedList(Node* head){
    // If head is null or there 
    // is no next node, return head
    if(head == NULL || head->next == NULL){
        return head;
    }

    // Recursively flatten the
    // rest of the linked list
    Node* mergedHead = flattenLinkedList(head->next);
    head = merge(head, mergedHead);
    return head;
}
