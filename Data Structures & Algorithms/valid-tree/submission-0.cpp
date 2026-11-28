class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        vector<vector<int>>adj(n);
        vector<bool> visited(n, false);
        queue<int> q;

        for(auto& curr:edges){
            adj[curr[1]].push_back(curr[0]);
            adj[curr[0]].push_back(curr[1]);
        }

        q.push(0);
        visited[0] = true;
        int count = 0;

        while(!q.empty()){
            int curr=q.front(); q.pop();
            count++;
            for(auto& curr:adj[curr]){
                if (!visited[curr]) {
                    visited[curr] = true;
                    q.push(curr);
                }
            }
        }

        return count==n;
    }
};
