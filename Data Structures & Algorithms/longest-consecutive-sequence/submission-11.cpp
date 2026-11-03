class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return 1;
        unordered_set<int> s(nums.begin(), nums.end());
        int i = 0;
        int m = 0;

        while (i < nums.size()) {
            int count = 1;
            int curr = nums[i];
            if (s.count(curr - 1) == 0) {
                while ((s.count(curr) == s.count(curr + 1)) && (s.count(curr) == 1)) {
                    count++;
                    curr++;
                }
            }
            m = max(m, count);
            i++;
        }

        return m;
    }
};
