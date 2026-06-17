class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int min_left = prices[0];
        int max_profit = 0;
        for ( int i = 1 ; i< n; i++){
            min_left = min( min_left, prices[i - 1]);
            max_profit = max(max_profit , prices[i] - min_left);
        }
        return max_profit;
    }
};
