class Solution {
public:
    bool isPalindrome(string s) {
        string cleaned = "";
        
        for (char c : s) {
            if (isalnum(static_cast<unsigned char>(c))) {
                cleaned += tolower(static_cast<unsigned char>(c));
            }
        }
        
        int left = 0;
        int right = cleaned.size() - 1;
        
        while (left < right) {
            if (cleaned[left] != cleaned[right]) {
                return false;
            }
            left++;
            right--;
        }
        
        return true;
    }
};
