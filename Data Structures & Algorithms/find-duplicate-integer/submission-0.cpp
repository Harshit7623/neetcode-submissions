class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        
        // We use a do-while loop because they start at the same place,
        // and we need them to take their first steps before checking for collision.
        do {
            slow = nums[slow];           // Tortoise takes 1 step
            fast = nums[nums[fast]];     // Hare takes 2 steps
        } while (slow != fast);
        
        // --- PHASE 2: Find the entrance to the cycle (the duplicate) ---
        // Move the tortoise back to the start line
        slow = nums[0];
        
        // Now they both move at the EXACT SAME speed
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        // The point where they meet is the duplicate number!
        return slow;
    }
};
