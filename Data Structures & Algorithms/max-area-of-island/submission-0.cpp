class Solution {
public:
    void helper(vector<vector<int>>& grid, int& ans, int i, int j){
        if(grid[i][j]!=1) return;
        
        grid[i][j]=-1;
        ans++;

        if(i<grid.size()-1){
            helper(grid,ans,i+1,j);
        }
        if(j<grid[0].size()-1){
            helper(grid,ans,i,j+1);
        }
        if(i>0){
            helper(grid,ans,i-1,j);
        }
        if(j>0){
            helper(grid,ans,i,j-1);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==-1 || grid[i][j]==0) continue;
                int temp=0;
                helper(grid,temp,i,j);
                ans=max(ans,temp);
            }
        }
        return ans;
    }
};
