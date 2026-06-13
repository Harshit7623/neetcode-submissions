class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>hash_map;
        int difference;
        for( int i = 0 ; i < nums.size() ; i++){
        difference = target - nums[i];
        if (hash_map.find(difference) != hash_map.end()){
            return  {hash_map[difference],i};
        }
        hash_map[nums[i]]=i;
        }
        return {};
    }
};
