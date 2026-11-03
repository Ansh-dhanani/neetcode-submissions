class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> my_set;
        for(int i=0;i<nums.size();i++){
            if(my_set.count(nums[i])){
                return true;
            }
            my_set.insert(nums[i]);
        }
        return false;
    }
};