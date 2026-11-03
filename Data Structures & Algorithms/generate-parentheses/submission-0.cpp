class Solution {
   public:
    bool validate(string s) {
        vector<int> v;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                v.push_back(1);
            } else if (s[i] == ')') {
                if (!v.empty() && v.back() == 1) {
                    v.pop_back();
                } else {
                    return false;
                }
            }
        }
        return v.empty();
    }

    void helper(vector<string>& ans, int n, string curr, int i, int j) {
        if (curr.size() == n * 2) {
            if (validate(curr)) {
                ans.push_back(curr);
            }
            return;
        }
        if (i < n) {
            curr += '(';
            helper(ans, n, curr, i + 1, j);
            curr.pop_back();
        }
        if (j < i) {
            curr += ')';
            helper(ans, n, curr, i, j + 1);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(ans, n, "", 0, 0);
        return ans;
    }
};
