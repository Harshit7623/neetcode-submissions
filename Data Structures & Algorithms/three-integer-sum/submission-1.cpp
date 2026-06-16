class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       vector<vector<int>> triplets;
        
        // 1. Sort the array to handle duplicates and enable Two Pointers
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            // Optimization: If the first number is > 0, the sum can never be 0!
            if (nums[i] > 0) break;
            
            // Skip duplicates for our locked number 'i'
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            // 2. Standard Two Pointers setup
            int left = i + 1;
            int right = nums.size() - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum > 0) {
                    right--; // Sum is too big, shrink from the right
                } 
                else if (sum < 0) {
                    left++; // Sum is too small, grow from the left
                } 
                else {
                    // We found a valid triplet!
                    triplets.push_back({nums[i], nums[left], nums[right]});
                    
                    // Move both pointers inward to look for other combinations
                    left++;
                    right--;
                    
                    // Skip duplicates for the 'left' pointer
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                    
                    // Skip duplicates for the 'right' pointer
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                }
            }
        }
        
        return triplets;
    }
};
