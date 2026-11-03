class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        multimap<int,int> i;
        for(auto it=freq.begin();it!=freq.end();it++){
            i.insert({it->second,it->first});
        }
        for(auto it=i.rbegin();it!=i.rend();it++){
            if(ans.size()<k){
                ans.push_back(it->second);
            }else{
                break;
            }
        }
        return ans;
    }
};
