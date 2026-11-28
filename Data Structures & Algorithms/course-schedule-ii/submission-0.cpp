class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<vector<int>> adj(n);
        vector<int> in(n,0);
        vector<int> ans;

        queue<int> q;

        for(auto& v:p){
            adj[v[1]].push_back(v[0]);
            in[v[0]]++;
        }

        for(int i=0;i<in.size();i++){
            if(in[i]==0) q.push(i);
        }

        while(!q.empty()){
            int curr=q.front();q.pop();
            ans.push_back(curr);
            for(auto& c:adj[curr]){
                if(--in[c]==0){
                    q.push(c);
                }
            }
        }

        if (ans.size() != n) return {};
        return ans;
    }
};
