class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> mm;
        for (int i = 0; i < nums.size(); i++) {
            mm[nums[i]]++;
            if (mm[nums[i]] > 1) {
                return nums[i]; 
            }
        }
        return -1; 
    }
};
