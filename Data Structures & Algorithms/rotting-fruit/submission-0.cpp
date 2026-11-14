class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int total_time = 0;
        int fresh = 0;

        int rows = grid.size();
        int cols = grid[0].size();

        deque<pair<int, int>> q;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    q.push_front({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        if (fresh == 0) {
            return 0;
        }

        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        while (!q.empty() && fresh>0) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                for (int i = 0; i < 4; i++) {
                    pair<int, int> curr = {q.front().first + dir[i].first,
                                           q.front().second + dir[i].second};
                    if (curr.first < 0 || curr.second < 0 || curr.first > rows - 1 ||
                        curr.second > cols - 1) {
                        continue;
                    }
                    if (grid[curr.first][curr.second] == 0 || grid[curr.first][curr.second] == 2) {
                        continue;
                    }
                    grid[curr.first][curr.second] = 2;
                    q.push_back({curr.first, curr.second});
                    fresh--;
                }
                q.pop_front();
            }
            total_time++;
        }

        return fresh == 0 ? total_time : -1;
    }
};
