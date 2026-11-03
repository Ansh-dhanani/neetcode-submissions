class Solution {
   public:
    string encode(vector<string>& strs) {
        string ans = "";
        for (const auto& s : strs) {
            ans += std::format("{}#{}", s.size(), s);
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        for (int i = 0; i < s.size() ; i++) {
            int j = i+1;
            while(s[j]!='#' && j<s.size()){
                j++;
            }
            int size = stoi(s.substr(i,j-i));
            ans.push_back(s.substr(j+1,size));
            i = j+size;
        }
        return ans;
    }
};
