class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>lcs(nums.begin(), nums.end());
        int max_count = 0 ;
        for ( int num : lcs){
            if (! lcs.contains(num - 1)){
                int current_num = num;
                int curr_count = 1;

                while(lcs.contains(current_num + 1)){
                    current_num += 1;
                    curr_count += 1;
                }
                max_count = max(curr_count,max_count);
            }
        }
        return max_count;
    }
};
