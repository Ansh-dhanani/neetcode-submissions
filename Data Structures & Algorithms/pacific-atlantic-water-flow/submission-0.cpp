class Solution {
public:
    void helper(vector<vector<int>>& heights,int i,int j,vector<vector<int>>& ocean){
        int n=heights.size();
        int m=heights[0].size();

        ocean[i][j]=1;

        if(i>0 && ocean[i-1][j]!=1 && heights[i][j]<=heights[i-1][j]){
            helper(heights,i-1,j,ocean);
        }
        if(j>0 && ocean[i][j-1]!=1 && heights[i][j]<=heights[i][j-1]){
            helper(heights,i,j-1,ocean);
        }
        if(i<n-1 && ocean[i+1][j]!=1 && heights[i][j]<=heights[i+1][j]){
            helper(heights,i+1,j,ocean);
        }
        if(j<m-1 && ocean[i][j+1]!=1 && heights[i][j]<=heights[i][j+1]){
            helper(heights,i,j+1,ocean);
        }

    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> pacific(n,vector<int>(m,0));
        vector<vector<int>> atlantic(n,vector<int>(m,0));
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            helper(heights, i, 0, pacific);
            helper(heights, i, m - 1, atlantic);
        }
        for (int j = 0; j < m; j++) {
            helper(heights, 0, j, pacific);
            helper(heights, n - 1, j, atlantic);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
