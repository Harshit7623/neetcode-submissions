class Solution {
public:
    int trap(vector<int>& height) {
        //The naive solution
        int n = height.size();
        int total_water = 0;
        for ( int i = 0 ; i < n ; i++){
            int left_max = 0;
            int right_max = 0;
             for( int j = 0 ; j <= i ; j++){
                left_max = max( left_max, height[j]);
             }

             for ( int k = i ; k < n ; k++){
                right_max = max(right_max, height[k]);
             }
             total_water += min(left_max, right_max) - height[i];
        }
        return total_water;


    }
};
