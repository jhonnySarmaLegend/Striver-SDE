//Qustion Link --> https://leetcode.com/problems/lru-cache/description/
/*
class LRUCache {
public:
    LRUCache(int capacity) {
        
    }
    
    int get(int key) {
        
    }
    
    void put(int key, int value) {
        
    }
};
*/

//More OPTIMIZED --> no node creation for addition & deletion all o(1)

class LRUCache {

  public:
    class node {
      public:
        int key;
      int val;
      node * next;
      node * prev;
      node(int _key, int _val) {
        key = _key;
        val = _val;
      }
    };

  node * head = new node(-1, -1);
  node * tail = new node(-1, -1);

  int cap;
  unordered_map < int, node * > m;

  LRUCache(int capacity) {
    cap = capacity;
    head -> next = tail;
    tail -> prev = head;
  }

  void addnode(node * newnode) {
  newnode -> next = head -> next;
  newnode -> prev = head;  
        
  head -> next -> prev = newnode;
  head -> next = newnode;       

  }

  void deletenode(node * delnode) {
    delnode -> prev -> next = delnode -> next;
    delnode -> next -> prev = delnode -> prev;
  }

  int get(int key_) {
    if (m.find(key_) != m.end()) {
      node * resnode = m[key_];
      int res = resnode -> val;
      m.erase(key_);
      deletenode(resnode);
      addnode(resnode);
      m[key_] = head -> next;
      return res;
    }

    return -1;
  }

  void put(int key_, int value) {
    if (m.find(key_) != m.end()) {
      node * existingnode = m[key_];
      m.erase(key_);
      deletenode(existingnode);
    }
    if (m.size() == cap) {
      m.erase(tail -> prev -> key);
      deletenode(tail -> prev);
    }

    addnode(new node(key_, value));
    m[key_] = head -> next;
  }

};









//COMMENTED
class LRUCache {

public:

  class node { // Defines a nested class 'node' to represent elements in the doubly linked list.

  public:

    int key; // Stores the key of the cache entry.

    int val; // Stores the value associated with the key.

    node * next; // Pointer to the next node in the list.

    node * prev; // Pointer to the previous node in the list.

    node(int _key, int _val) { // Constructor for the node class.

      key = _key; // Initializes the key.

      val = _val; // Initializes the value.

    }

  };

  node * head = new node(-1, -1); // Creates a dummy head node for the doubly linked list, initialized with arbitrary values.

  node * tail = new node(-1, -1); // Creates a dummy tail node for the doubly linked list, initialized with arbitrary values.

  int cap; // Stores the maximum capacity of the LRU cache.

  unordered_map < int, node * > m; // A hash map to store key-node pointer pairs for O(1) access to nodes.

  LRUCache(int capacity) { // Constructor for the LRUCache class.

    cap = capacity; // Initializes the cache capacity.

    head -> next = tail; // Links the head node to the tail node.

    tail -> prev = head; // Links the tail node back to the head node, forming an empty circular list (with dummy nodes).

  }

  void addnode(node * newnode) { // Function to add a new node right after the head (most recently used position).

    node * temp = head -> next; // Stores the current node after the head.

    newnode -> next = temp; // Links the new node to the 'temp' node.

    newnode -> prev = head; // Links the new node back to the head.

    head -> next = newnode; // Updates the head's next pointer to the new node.

    temp -> prev = newnode; // Updates the 'temp' node's previous pointer to the new node.

  }

  void deletenode(node * delnode) { // Function to delete a given node from the doubly linked list.

    node * delprev = delnode -> prev; // Stores the node before the one to be deleted.

    node * delnext = delnode -> next; // Stores the node after the one to be deleted.

    delprev -> next = delnext; // Links the previous node directly to the next node, bypassing 'delnode'.

    delnext -> prev = delprev; // Links the next node directly back to the previous node, bypassing 'delnode'.

  }

  int get(int key_) { // Function to retrieve the value associated with a key.

    if (m.find(key_) != m.end()) { // Checks if the key exists in the hash map.

      node * resnode = m[key_]; // Retrieves the node pointer from the hash map.

      int res = resnode -> val; // Stores the value of the retrieved node.

      m.erase(key_); // Removes the key-node pair from the hash map (as the node will be re-added).

      deletenode(resnode); // Deletes the node from its current position in the linked list.

      addnode(resnode); // Adds the node back to the front of the list (most recently used).

      m[key_] = head -> next; // Updates the hash map with the new position of the node (which is now after head).

      return res; // Returns the retrieved value.

    }

    return -1; // Returns -1 if the key is not found in the cache.

  }

  void put(int key_, int value) { // Function to add or update a key-value pair in the cache.

    if (m.find(key_) != m.end()) { // Checks if the key already exists in the cache.

      node * existingnode = m[key_]; // Retrieves the existing node.

      m.erase(key_); // Removes the key-node pair from the hash map.

      deletenode(existingnode); // Deletes the existing node from the linked list.

    }

    if (m.size() == cap) { // Checks if the cache has reached its maximum capacity.

      m.erase(tail -> prev -> key); // Removes the least recently used key from the hash map (key of the node before tail).

      deletenode(tail -> prev); // Deletes the least recently used node from the linked list.

    }

    addnode(new node(key_, value)); // Creates a new node with the given key and value and adds it to the front of the list.

    m[key_] = head -> next; // Adds/updates the new node's position in the hash map.

  }

};

/**

 * Your LRUCache object will be instantiated and called as such:

 * LRUCache* obj = new LRUCache(capacity);

 * int param_1 = obj->get(key);

 * obj->put(key,value);

 */
