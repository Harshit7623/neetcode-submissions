class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
      vector<double> time_at_pos(target, -1.0);
        
        for (int i = 0; i < position.size(); i++) {
            time_at_pos[position[i]] = (double)(target - position[i]) / speed[i];
        }
        
        int fleets = 0;
        double slowest_time_ahead = 0.0;
        
        for (int i = target - 1; i >= 0; i--) {
            if (time_at_pos[i] > slowest_time_ahead) {
                fleets++;
                slowest_time_ahead = time_at_pos[i];
            }
        }
        
        return fleets;
    }
};
