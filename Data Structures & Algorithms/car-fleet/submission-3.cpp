class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
                vector<pair<int,double>>fleet;
                int n = position.size();
                if( n == 0){
                    return 0;
                }
                for( int i = 0; i < n; i++){
                double time = (double)(target - position[i])/ speed[i];
                fleet.push_back({position[i], time});
                }
                sort(fleet.begin(), fleet.end());
                double slowest_time = 0.0;
                int fleets = 0 ;
                for( int i = n-1; i >= 0 ; i--){
                if (fleet[i].second > slowest_time) {
                fleets++;
                slowest_time = fleet[i].second; 
            }
                }

            return fleets; 
    }
};
