class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(string srs : strs){
        res += to_string(srs.length()) + '#' + srs;
        }
        return res;

    }

    vector<string> decode(string s) {
        int main =0;
        vector<string>ds;
        while(main<s.size()){
            int j = main;
            while( s[j] != '#'){
                j++;
            }
            int length = stoi(s.substr(main  , j - main));
            string res = s.substr(j + 1 , length );
            ds.push_back(res);
            main = j + 1 + length ;
        }
        return ds;
    }
};
