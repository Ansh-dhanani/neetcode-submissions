class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()<=1) return true;
        int curr=nums.size()-1;
        for(int i=nums.size()-2;i>=0;i--){
            if(i+nums[i]>=curr){
                curr=i;
            }
        }
        return curr==0;
    }
};
