class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string temp=strs[0];
        for(int i=0;i<strs.size();i++){
            for(int j=0;j<temp.size();j++){
                if(temp[j]!=strs[i][j]){
                    temp=temp.substr(0,j);
                    break;
                }
            }
        }   
        return temp;
    }
};