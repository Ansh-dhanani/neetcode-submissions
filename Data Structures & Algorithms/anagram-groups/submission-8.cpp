class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> m;
        for(int i=0;i<strs.size();i++){
            string temp=strs[i];
            sort(strs[i].begin(),strs[i].end());
            m[strs[i]].push_back(temp);
        }
        auto it=m.begin();
        while(it!=m.end()){
            ans.push_back(it->second);
            it++;
        }
        return ans;
    }
};
