class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;
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
            while((s[j]-'0'>=0) && (s[j]-'0'<=9) && j<s.size()){
                j++;
            }
            if (j >= s.size() || s[j] != '#') return {}; 
            int size=stoi(s.substr(i,j-i));
            i=j+1;
            ans.push_back(s.substr(i,size));
            i+=size;
        }
        return ans;
    }
};
