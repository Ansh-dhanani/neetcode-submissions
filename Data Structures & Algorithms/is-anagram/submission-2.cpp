class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int> freq_s(26,0);
        vector<int> freq_t(26,0);
        for(int i=0;i<s.size();i++){
            freq_s[tolower(s[i])-'a']++;
        }
        for(int i=0;i<t.size();i++){
            freq_t[tolower(t[i])-'a']++;
        }
        if(freq_s==freq_t) return true;
        return false;
    }
};
