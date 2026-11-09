class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> f;
        for (const auto& t : tasks) {
            f[t]++;
        }
        priority_queue<pair<int, char>> pq;
        for (const auto& it : f) {
            pq.push({it.second, it.first});
        }
        int ans = 0;
        while (!pq.empty()) {
            vector<pair<int, char>> arr;
            for (int i = 0; i <= n; i++) {
                if (!pq.empty()) {
                    auto top = pq.top();
                    pq.pop();
                    ans++;
                    if (top.first - 1 > 0) {
                        arr.push_back({top.first - 1, top.second});
                    }
                } else if (!arr.empty()) {
                    ans++;
                }
            }
            for (auto& it : arr) {
                pq.push(it);
            }
        }
        return ans;
    }
};
