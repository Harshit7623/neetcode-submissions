class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>hm;
        for( int i = 0 ; i < nums.size() ; i++){
        int d = target - nums[i];
        if (hm.contains(d)){
            return  {hm[d],i};
        }
        hm[nums[i]]=i;
        }
        return {};
    }
};
