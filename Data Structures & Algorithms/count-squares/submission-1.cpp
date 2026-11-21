class CountSquares {
   private:
    int grid[1001][1001] = {};
    vector<vector<int>> points;

   public:
    CountSquares() {}

    void add(vector<int> point) {
        grid[point[0]][point[1]]++;
        points.push_back(point);
    }

    int count(vector<int> point) {
        int x1 = point[0];
        int y1 = point[1];

        int count = 0;
        for (auto& p : points) {
            int x2 = p[0];
            int y2 = p[1];

            if (abs(x1 - x2) == abs(y2 - y1) && x1 != x2 ) {
                count += grid[x1][y2] * grid[x2][y1];
            }
        }

        return count;
    }
};
