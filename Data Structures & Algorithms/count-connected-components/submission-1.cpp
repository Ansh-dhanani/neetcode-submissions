class Solution {
   public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> vis(n, 0);
        queue<int> q;
        int ans=0;
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for (int i = 0; i < vis.size(); i++) {
            if (vis[i] == 0) {
                vis[i] = 1;
                q.push(i);
                while (!q.empty()) {
                    int curr = q.front();
                    q.pop();
                    for (auto& e : adj[curr]) {
                        if (!vis[e]) {
                            vis[e] = 1;
                            q.push(e);
                        }
                    }
                }
                ans++;
            }
        }

        return ans;
    }
};
