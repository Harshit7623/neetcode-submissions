class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int n1 = s1.size();
        int n2 = s2.size();
        if( n1 > n2) return false;
        vector<int>s1_str(26 , 0);
        vector<int>s2_str(26, 0);
        for( int i = 0; i< n1; i++){
            s1_str[s1[i] - 'a']++;
            s2_str[s2[i] - 'a']++;
        }
        for(int i = 0; i < n2 - n1; i++){
            if (s1_str == s2_str){
                return true;
            }
            s2_str[s2[i] - 'a']--;
            s2_str[s2[i + n1] - 'a']++;
        }
        return s1_str == s2_str;
    }
};
