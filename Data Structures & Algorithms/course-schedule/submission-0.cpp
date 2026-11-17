class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>> adj(n);
        vector<int> in(n, 0);
        for (auto& e : p) {
            adj[e[1]].push_back(e[0]);
            in[e[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
            if (in[i] == 0) q.push(i);

        int count = 0;
        while (!q.empty()) {
            int curr = q.front(); q.pop();
            count++;
            for (int next : adj[curr])
                if (--in[next] == 0) q.push(next);
        }
        return count == n;
    }
};
