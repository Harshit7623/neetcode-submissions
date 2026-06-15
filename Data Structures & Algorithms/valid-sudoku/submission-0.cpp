class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char>rows[9];
        unordered_set<char>cols[9];
        unordered_set<char>boxes[9];
        int n = board[0].size();
        for (int i = 0 ; i < n; i++){
            for (int j = 0 ; j < n; j++){
                int val = board[i][j];
                if (val == '.'){
                    continue;
                }
                int index = (i/3) * 3 + (j/3);
                if( rows[i].count(val) || cols[j].count(val) || boxes[index].count(val)){
                    return false;
                }
                rows[i].insert(val);
                cols[j].insert(val);
                boxes[index].insert(val);

            }

        }
        return true;

       
    }
};
