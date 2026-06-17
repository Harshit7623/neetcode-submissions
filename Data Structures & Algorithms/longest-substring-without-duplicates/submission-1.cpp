class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>uniq_char;
        int max_count = 0;
        int left = 0;
        for( int r = 0 ; r < s.size(); r++){
            while(uniq_char.contains(s[r])){
                max_count = max(max_count, (int)uniq_char.size());
                uniq_char.erase(s[left]);
                left++;
            }
            uniq_char.insert(s[r]);
        }
        max_count = max((int)uniq_char.size(), max_count);
        return max_count;
        

    }
};
