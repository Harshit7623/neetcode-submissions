class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>lcs;
        int max_count = 0 ;
        sort(nums.begin(), nums.end());
        for ( int num : nums){
            if (lcs.empty() || lcs.contains(num - 1)){
                lcs.insert(num);
            }
            else{
                if(max_count < lcs.size()){
                    max_count = lcs.size();
                }
                lcs.clear();
                lcs.insert(num);
            }
        }
        if(max_count < lcs.size()){
            max_count = lcs.size();        }
        return max_count;
    }
};
