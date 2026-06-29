/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
     if (head == nullptr) return nullptr;

        // --- PHASE 1: Clone and Weave ---
        Node* curr = head;
        while (curr != nullptr) {
            Node* clone = new Node(curr->val);
            clone->next = curr->next;
            curr->next = clone;
            
            // Jump over the newly created clone
            curr = clone->next; 
        }

        // --- PHASE 2: Wire Random Pointers ---
        curr = head;
        while (curr != nullptr) {
            if (curr->random != nullptr) {
                // The clone's random is the original random's clone
                curr->next->random = curr->random->next;
            }
            // Jump to the next ORIGINAL node
            curr = curr->next->next; 
        }

        // --- PHASE 3: Untangle ---
        curr = head;
        Node dummy(0); // Anchor for our new cloned list
        Node* copyTail = &dummy;

        while (curr != nullptr) {
            Node* clone = curr->next;
            
            // 1. Restore the original list
            curr->next = clone->next;
            
            // 2. Build the new cloned list
            copyTail->next = clone;
            copyTail = clone;
            
            // 3. Move forward
            curr = curr->next;
        }

        return dummy.next;
    }
};
