class Solution {
public:
    bool isAnagram(string s, string t) {
    unordered_map<char,int>freq_map;
    for(char str : s){
        freq_map[str]++;
    }
    for(char str : t){
        freq_map[str]--;
        if (freq_map[str]==0){
            freq_map.erase(str);
        }
    }
    if (freq_map.size()==0){
        return true;

    }
    return false;
    }
};
