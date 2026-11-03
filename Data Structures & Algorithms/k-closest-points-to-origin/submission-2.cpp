class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<vector<int>>>> pq;
        vector<vector<int>> ans;
        for (auto p : points) {
            int dist = -(p[0] * p[0] + p[1] * p[1]);
            if(!pq.empty() && pq.top().first==dist){
                auto temp=pq.top();
                temp.second.push_back(p);
                pq.pop();
                pq.push(temp);
            }else{
                pq.push({dist,{p}});
            }
        }

        while(k>0 && !pq.empty()){
            vector<vector<int>> temp=pq.top().second;
            int i=0;
            while(k>0 && i<temp.size()){
                ans.push_back(temp[i]);
                i++;
                k--;
            }
            pq.pop();
        }
        return ans;
    }
};
