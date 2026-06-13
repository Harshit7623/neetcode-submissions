class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string,vector<string>>hm;
    for (string str : strs){
        string key(26,'0');
        for(char st : str){
         key[st - 'a']++;
        }
        hm[key].push_back(str);

    }
    vector<vector<string>>result;
    for(const auto& pair : hm){
        result.push_back(pair.second);
    }
    return result;
    }
};
