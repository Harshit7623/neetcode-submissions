class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>hash_map;
        for( int i = 0 ; i < nums.size() ; i++){
        int d = target - nums[i];
        if (hash_map.find(d) != hash_map.end()){
            return  {hash_map[d],i};
        }
        hash_map[nums[i]]=i;
        }
        return {};
    }
};
