class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mm;
        for (int i = 0; i < n; i++) {
            mm[nums[i]]++;
        }
        multimap<int, int> inverted;
        for (const auto& pair : mm) {
            inverted.insert(std::make_pair(pair.second, pair.first));
        }
        auto last_iter = --inverted.end();
        return last_iter->second;
    }
};
