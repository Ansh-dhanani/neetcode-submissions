class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size()) return false;
        sort(s1.begin(),s1.end());
        for(int i=0;i<s2.size();i++){
            if(s2.size()-i>=s1.size()){
                string temp=s2.substr(i,s1.size());
                sort(temp.begin(),temp.end());
                if(temp==s1) return true;
            }else{
                return false;
            }
        }
        return false;
    }
};
