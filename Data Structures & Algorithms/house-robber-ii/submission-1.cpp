class Solution {
public:
    int robLinear(vector<int>& nums, int start, int end) {
        int num = 0;
        int num2 = 0;
        for (int i = start; i <= end; i++) {
            int temp = num;
            num = max(num, num2 + nums[i]);
            num2 = temp;
        }
        return num;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int excludeLast = robLinear(nums, 0, n - 2);
        int excludeFirst = robLinear(nums, 1, n - 1);

        return max(excludeLast, excludeFirst);
    }
};
