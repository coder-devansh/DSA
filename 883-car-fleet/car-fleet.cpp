class Solution {
public:
    // Sort cars by position descending (closest to target first)
    static bool compare(const pair<int,int>& a, const pair<int,int>& b){
        return a.first > b.first;
    }

    // Find meeting position of two cars
    double find_meet(double posA, double posB, double spA, double spB){
        if(spA <= spB) return -1; // will never meet
        double time = (posB - posA) / (spA - spB);
        return posA + spA * time;
    }

    // Calculate time to reach target
    double calculate(int p, int s, int target){
        return (double)(target - p) / s;
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> vec;

        for(int i = 0; i < n; i++){
            vec.push_back({position[i], speed[i]});
        }

        sort(vec.begin(), vec.end(), compare);

        stack<pair<double,int>> st; // store {fleet_time, speed} or you can store {fleet_time, pos}

        for(int i = 0; i < n; i++){
            int posA = vec[i].first;
            int spA = vec[i].second;
            double time = calculate(posA, spA, target);

            if(!st.empty()){
                auto it = st.top();
                double fleet_time = it.first;
                int spB = it.second;
                int posB = st.top().second; // optional if you want meeting position

                if(time <= fleet_time){ 
                    // car joins the fleet
                    st.pop();
                    int min_speed = min(spA, spB);
                    double meeting_pos = (posA < posB && spA > spB) ? find_meet(posA, posB, spA, spB) : posA;
                    st.push({fleet_time, min_speed});
                } else {
                    st.push({time, spA});
                }
            } else {
                st.push({time, spA});
            }
        }

        return st.size(); // number of fleets
    }
};
