class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        // 1. Build the frequency map for the target string 't'
        // Using an array is much faster than an unordered_map for ASCII
        vector<int> target_freq(128, 0);
        for (char c : t) {
            target_freq[c]++;
        }

        int left = 0;
        int right = 0;
        int matched_chars = 0; // How many valid characters we have collected
        int required_chars = t.length();

        // Variables to track the winning substring
        int min_len = INT_MAX;
        int min_start = 0;

        // 2. Expand the window with 'right'
        while (right < s.length()) {
            char current_char = s[right];

            // If this is a character we actually need, reduce its required count
            if (target_freq[current_char] > 0) {
                matched_chars++;
            }
            // We unconditionally decrease the frequency (unneeded chars become negative)
            target_freq[current_char]--;
            right++;

            // 3. Shrink the window from the 'left' as long as it remains valid
            while (matched_chars == required_chars) {
                
                // Did we just find a new shorter window?
                if (right - left < min_len) {
                    min_len = right - left;
                    min_start = left;
                }

                char left_char = s[left];
                
                // Add the character back to our requirement map as we leave it behind
                target_freq[left_char]++;
                
                // If it was a character we actually needed, our window is now invalid
                if (target_freq[left_char] > 0) {
                    matched_chars--;
                }
                left++;
            }
        }

        return min_len == INT_MAX ? "" : s.substr(min_start, min_len);
    }
};
