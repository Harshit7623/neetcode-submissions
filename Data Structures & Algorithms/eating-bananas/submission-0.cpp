class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int min_speed = right;
        while( left <= right){
            long long hours = 0;
            int mid = left + (right - left)/2;
            for( int i  = 0; i < piles.size(); i++){
                 hours += ceil((double)piles[i]/mid);
            }
            if(h >= hours){
                min_speed = mid;
                right = mid - 1;
            }
            else if ( h < hours){
                left = mid + 1;
            }
        }
        return min_speed;
    }
};
