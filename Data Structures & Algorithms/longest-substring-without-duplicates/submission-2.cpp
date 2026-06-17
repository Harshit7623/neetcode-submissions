class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      vector<int>uniq_char(128, -1);
        int max_count = 0;
        int left = 0;
        for( int r = 0 ; r < s.size(); r++){
            char curr_char = s[r];
            if(uniq_char[curr_char] >= left){
                left = uniq_char[curr_char] + 1;
            }
            uniq_char[curr_char] = r;
            max_count = max(max_count, r - left + 1);
        }
        return max_count;
    }
};
