class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=speed.size();
        if (n == 0) return 0;
        vector<pair<int,int>> cars;
        for(int i=0;i<n;i++){
            cars.push_back({position[i],speed[i]});
        }
        sort(cars.begin(),cars.end());
        int fleet=0;
        double max_time = 0.0;
        for(int i=n-1;i>=0;--i){
            double curr=(double) (target-cars[i].first)/cars[i].second;
            if(curr>max_time){
                fleet++;
                max_time=curr;
            }
        }
        return fleet;
    }
};
