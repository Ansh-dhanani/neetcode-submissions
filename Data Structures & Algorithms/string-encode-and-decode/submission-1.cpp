class Solution {
public:

    string encode(vector<string>& strs) {
        string ans="";
        for(int i=0;i<strs.size();i++){
            ans+=std::format("{}#{}",(int)strs[i].size(),strs[i]);
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i=0;
        while(i<s.size()){
            int j=i;
            while(((s[j]-'0'>=0) && (s[j]-'0'<=9)) && j<s.size()){
                j++;
            }
            if(s[j]!='#'&&j<s.size()) return {};  
            int size=stoi(s.substr(i,j-i));
            i=j;
            ans.push_back(s.substr(i+1,size));
            i+=size+1;
        }

        return ans;
    }
};
