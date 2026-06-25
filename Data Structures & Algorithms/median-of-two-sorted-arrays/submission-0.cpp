class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int x = nums1.size();
        int y = nums2.size();
        
        int low = 0;
        int high = x;
        
        while (low <= high) {
           
            int partitionX = low + (high - low) / 2;
            int partitionY = (x + y + 1) / 2 - partitionX;
            
            // Find the 4 numbers immediately surrounding our cuts
            // Use INT_MIN and INT_MAX for edges where the cut is at the very end of an array
            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];
            
            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];
            
            // Check if our cuts are perfectly valid!
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                if ((x + y) % 2 == 0) {
                    // Even total elements: average of the two middle numbers
                    return ((double)max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
                } else {
                    // Odd total elements: the median is simply the largest number on the left
                    return (double)max(maxLeftX, maxLeftY);
                }
            } 
            else if (maxLeftX > minRightY) {
                // We are too far to the right in nums1. Move the cut left.
                high = partitionX - 1;
            } 
            else {
                // We are too far to the left in nums1. Move the cut right.
                low = partitionX + 1;
            }
        }
        
        // The code should theoretically never reach here if arrays are valid
        return 0.0;
    }
};
