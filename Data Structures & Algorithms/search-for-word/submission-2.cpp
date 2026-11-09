class Solution {
   public:
    bool helper(vector<vector<char>>& board, int i, int j, string& word, int curr) {
        if (board[i][j] != word[curr]) {
            return false;
        }
        if (curr == word.size() - 1) {
            return true;
        }


        char t = board[i][j];
        board[i][j] = '#';
        bool a=false, b=false, c=false, d=false;
        if (i > 0) {
            a = helper(board, i - 1, j, word, curr + 1);
        }
        if (j > 0) {
            b = helper(board, i, j - 1, word, curr + 1);
        }
        if (i < board.size() - 1) {
            c = helper(board, i + 1, j, word, curr + 1);
        }
        if (j < board[0].size() - 1) {
            d = helper(board, i, j + 1, word, curr + 1);
        }
        board[i][j] = t;
        return a || b || c || d;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (word[0] == board[i][j]) {
                    bool temp = helper(board, i, j, word, 0);
                    if (temp) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
