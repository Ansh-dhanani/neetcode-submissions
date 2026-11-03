class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string t=strs[0];
        for(int i=0;i<strs.size();i++){
            for(int j=0;j<t.size();j++){
                if(t[j]!=strs[i][j]){
                    t=t.substr(0,j);
                    break;
                }
            }
        }   
        return t;
    }
};