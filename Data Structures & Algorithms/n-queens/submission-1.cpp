class Solution {
   public:
    bool check(vector<string>& grid, int i, int j) {
        int n=grid.size();
        for (int p = 0; p < n; p++) {
            if (p != i && grid[p][j] == 'Q') return false;
            if (p != j && grid[i][p] == 'Q') return false;
        }

        for (int p = i + 1, q = j + 1; p < n && q < n; p++, q++) {
            if (grid[p][q] == 'Q') return false;
        }

        for (int p = i - 1, q = j - 1; p >= 0 && q >= 0; p--, q--) {
            if (grid[p][q] == 'Q') return false;
        }

        for (int p = i - 1, q = j + 1; p >= 0 && q < n; p--, q++) {
            if (grid[p][q] == 'Q') return false;
        }

        for (int p = i + 1, q = j - 1; p < n && q >= 0; p++, q--) {
            if (grid[p][q] == 'Q') return false;
        }
        return true;
    }

    void helper(vector<vector<string>>& ans, vector<string> grid, int i, int curr) {
        if (i == grid.size()){
            ans.push_back(grid);
            return;
        }
        
        for(int p=0;p<grid.size();p++){
            if(check(grid,i,p)){
                grid[i][p]='Q';
                helper(ans,grid,i+1,curr+1);
                grid[i][p]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> curr(n, string(n, '.'));
        helper(ans, curr, 0, 1);
        return ans;
    }
};
