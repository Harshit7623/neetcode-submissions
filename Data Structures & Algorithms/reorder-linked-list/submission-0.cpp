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
    void reorderList(ListNode* head) {
       if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return;
        }

        // --- PHASE 1: Find the middle ---
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // --- PHASE 2: Reverse the second half ---
        ListNode* curr = slow->next;
        slow->next = nullptr; // Sever the tie between the two halves!
        ListNode* prev = nullptr;
        
        while (curr != nullptr) {
            ListNode* ptr_nxt = curr->next; // Hold onto the rest of the list
            curr->next = prev;              // Point backwards
            prev = curr;                    // Move prev forward
            curr = ptr_nxt;                 // Move curr forward 
        }

        // --- PHASE 3: Merge (Zip) the two halves ---
        ListNode* first = head;
        ListNode* second = prev; // 'prev' is now the head of the reversed second half
        
        while (second != nullptr) {
            // 1. Hold onto the next nodes in both lists
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
            
            // 2. Wire the 'first' node to the 'second' node
            first->next = second;
            
            // 3. Wire the 'second' node to the NEXT 'first' node
            second->next = temp1;
            
            // 4. Move both pointers forward for the next iteration
            first = temp1;
            second = temp2;
        }
    }
};
