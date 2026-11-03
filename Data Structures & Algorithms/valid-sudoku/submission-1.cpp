class Solution {
   public:
    bool isvalid_box(vector<vector<char>>& board, int p, int q) {
        int i_end = p + 3;
        int j_end = q + 3;
        set<char> s;
        bool final = false;
        int count = 0;
        for (int i = p; i < i_end; i++) {
            for (int j = q; j < j_end; j++) {
                if (board[i][j] == '.') {
                    continue;
                } else {
                    s.insert(board[i][j]);
                    count++;
                }
            }
        }
        if (s.size() == count) return true;
        return false;
    }

    bool isvalid_rc(vector<vector<char>>& board, int p) {
        set<char> r_s;
        set<char> c_s;
        int count_r = 0;
        int count_c = 0;
        for (int i = 0; i < 9; i++) {
            if (board[p][i] == '.') {
                continue;
            } else {
                count_r++;
                r_s.insert(board[p][i]);
            }
        }
        for (int i = 0; i < 9; i++) {
            if (board[i][p] == '.') {
                continue;
            } else {
                count_c++;
                c_s.insert(board[i][p]);
            }
        }
        if ((r_s.size() == count_r) && (c_s.size() == count_c)) return true;
        return false;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        bool v1 = true;
        bool v2 = true;
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                bool temp;
                temp = isvalid_box(board, i, j);
                v1 = v1 && temp;
            }
        }
        for (int i = 0; i < 9; i++) {
            bool temp;
            temp = isvalid_rc(board, i);
            v2 = v2 && temp;
        }
        return v1 && v2;
    }
};
