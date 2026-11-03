class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIdx(256, -1);
        int maxLen = 0;
        int start = 0;
        
        for (int i = 0; i < (int)s.size(); i++) {
            unsigned char currChar = s[i];
            if (lastIdx[currChar] >= start) {
                start = lastIdx[currChar] + 1;
            }
            lastIdx[currChar] = i;
            maxLen = max(maxLen, i - start + 1);
        }
        
        return maxLen;
    }
};
