class Solution {
   public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        vector<pair<int, int>> dirs = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            int a = q.front().first;
            int b = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int l = a + dirs[i].first;
                int h = b + dirs[i].second;
                if (l < 0 || l >= grid.size() || h < 0 || h >= grid[0].size() || grid[l][h] <= 0) {
                    continue;
                }
                if (grid[l][h] > grid[a][b] + 1) {
                    grid[l][h] = grid[a][b] + 1;
                    q.push({l, h});
                }
            }
        }
    }
};
