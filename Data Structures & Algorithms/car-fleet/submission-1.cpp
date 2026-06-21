class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
       int n = position.size();
        if (n == 0) return 0;
        vector<pair<int, double>> cars;
        for(int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }
        
        
        sort(cars.rbegin(), cars.rend());
        
        int fleets = 0;
        double slowest_time_ahead = 0.0; 
        
        
        for(int i = 0; i < n; i++) {
         
            if (cars[i].second > slowest_time_ahead) {
                fleets++;
                slowest_time_ahead = cars[i].second; 
            }
          
        }
        
        return fleets;
    }
};
