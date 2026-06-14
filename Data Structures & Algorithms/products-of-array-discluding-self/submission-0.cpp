class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>pre_arr(n ,  1);
        vector<int>post_arr(n, 1);
        vector<int>res(n);
      for( int i = 1 ; i < n ; i++ ){
       pre_arr [i]= pre_arr[i - 1]  *  nums[i - 1];
      }
      for(int i = n - 2; i >= 0 ; i--){
        post_arr[i] = post_arr[ i +1 ] * nums[i + 1];
      }
    for ( int i = 0 ; i < n ; i++){
        res[i] = pre_arr[i] * post_arr[i];
    }

      return res;

    }
};
