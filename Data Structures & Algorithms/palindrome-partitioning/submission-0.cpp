class Solution {
   public:
    bool isPalindrome(string& s,int i,int j) {
        int n = s.size();
        int left = i;
        int right = j;
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    void helper(string& s, vector<vector<string>>& ans, vector<string>& path, int i) {
        if (i == s.size()) {
            ans.push_back(path);
            return;
        }

        for (int j = i; j < s.size(); j++) {
            if (isPalindrome(s, i, j)) {
                string sub = s.substr(i, j - i + 1);
                path.push_back(sub);
                helper(s, ans, path, j + 1);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        helper(s, ans, path, 0);
        return ans;
    }
};
