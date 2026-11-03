class Solution {
public:
    void helper(vector<vector<char>>& grid,int i,int j){
        if(grid[i][j]=='#' || grid[i][j]=='0') return;
        grid[i][j]='#';
        if(j>=1){
            helper(grid,i,j-1);
        }
        if(j<grid[0].size()-1){
            helper(grid,i,j+1);
        }
        if(i>=1){
            helper(grid,i-1,j);
        }
        if(i<grid.size()-1){
            helper(grid,i+1,j);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='0' || grid[i][j]=='#') continue;
                helper(grid,i,j);
                ans++;
            }
        }
        return ans;
    }
};
