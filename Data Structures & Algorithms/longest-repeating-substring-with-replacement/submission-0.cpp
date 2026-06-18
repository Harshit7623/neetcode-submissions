class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>freq(26, 0);
        int left = 0;
        int max_freq = 0;
        int max_len = 0;
        for( int right = 0 ; right < s.size(); right++ ){
            freq[s[right] - 'A']++;
             max_freq = max(max_freq, freq[s[right] - 'A']);
            int window_size = right - left + 1;
            if( window_size - max_freq > k ){
                freq[s[left] - 'A']--;
                left++;
            }
            max_len = max( max_len, right - left + 1);

        }
        return max_len;
        
    }
};
