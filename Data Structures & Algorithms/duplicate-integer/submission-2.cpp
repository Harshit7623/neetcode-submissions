class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
      unordered_map<int,int> dict;
      for(int num : nums){
        if( dict.count(num) ){
            return true;
        }
        dict[num]=+1;
      }
      return false;
    }
};