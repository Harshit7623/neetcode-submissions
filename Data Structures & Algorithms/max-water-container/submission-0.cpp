class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_area = 0;
        int i = 0;
        int j = heights.size() - 1;
        while(i < j ){
            int current_area = (j-i) * min(heights[i], heights[j]);
            max_area = max(current_area, max_area);
            if(heights[i] > heights[j]){
                j--;
            }
            else{
                i++;
            }
        }
        return max_area;

    }
};
