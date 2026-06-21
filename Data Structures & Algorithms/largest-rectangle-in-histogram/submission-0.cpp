class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>stk;
        int max_area = 0;
        int n = heights.size();
         
         for( int i = 0 ; i <= n; i++){
            int curr_height = (i == n)? 0 : heights[i];

            while( !stk.empty() && curr_height < heights[stk.top()]){

                int h = heights[stk.top()];
                stk.pop();
                int width;
                if(stk.empty()){
                    width = i;
                }
                else{
                    width = i - stk.top() - 1;
                }
                max_area = max (max_area , h* width);
            }
            stk.push(i);
         }
        return max_area;

    }
};
