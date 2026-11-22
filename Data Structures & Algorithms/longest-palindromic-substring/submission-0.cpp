class Solution {
   private:
    void expandAroundCenter(const string& s, int left, int right, int& start, int& maxLen) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            int currentLen = right - left + 1;
            if (currentLen > maxLen) {
                start = left;
                maxLen = currentLen;
            }
            --left;
            ++right;
        }
    }

   public:
    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }

        int start = 0;
        int maxLen = 1;

        for (int i = 0; i < s.length(); ++i) {
            expandAroundCenter(s, i, i, start, maxLen);
            expandAroundCenter(s, i, i + 1, start, maxLen);
        }

        return s.substr(start, maxLen);
    }
};
