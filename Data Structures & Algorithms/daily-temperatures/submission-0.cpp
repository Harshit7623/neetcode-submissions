class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>temp;
        vector<int>result(temperatures.size(), 0);
        for(int i = 0; i < temperatures.size(); i++){

                while(!temp.empty() && temperatures[i] > temperatures[temp.top()]){
                result[temp.top()] = i - temp.top();
                temp.pop();
                }
                temp.push(i);
        }
        return result;
    }
};
