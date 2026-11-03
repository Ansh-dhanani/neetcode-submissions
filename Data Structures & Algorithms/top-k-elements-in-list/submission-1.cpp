class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        multimap<int,int> rev;
        for(int n:nums){
            m[n]++;
        }
        for(auto it = m.begin();it!=m.end();++it){
            rev.insert({it->second,it->first});
        }
        vector<int> ans;
        for(auto it = rev.rbegin();(it!=rev.rend())&&(k>0);++it){
            ans.push_back(it->second);
            k--;
        }
        return ans;
    }
};
