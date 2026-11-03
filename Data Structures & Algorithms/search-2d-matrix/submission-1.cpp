class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int row_start = 0;
        int row_end = matrix.size() - 1;
        int row_mid;

        int main_row = -1;

        while(row_start <= row_end){
            row_mid = (row_start + row_end) / 2;
            if(matrix[row_mid][0] == target){
                return true;
            }
            if(matrix[row_mid][0] < target){
                main_row = row_mid; 
                row_start = row_mid + 1;
            }
            if(matrix[row_mid][0] > target){
                row_end = row_mid - 1;
            }
        }
        
        if (main_row == -1) return false;

        int col_start = 0;
        int col_end = matrix[main_row].size() - 1; 
        int col_mid;

        while(col_start <= col_end){
            col_mid = (col_start + col_end) / 2;
            if(matrix[main_row][col_mid] == target) return true;
            if(matrix[main_row][col_mid] < target){
                col_start = col_mid + 1;
            }
            if(matrix[main_row][col_mid] > target){
                col_end = col_mid - 1;
            }   
        }

        return false;
    }
};
