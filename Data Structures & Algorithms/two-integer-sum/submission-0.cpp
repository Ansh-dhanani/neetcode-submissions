class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_set<int> arr(nums.begin(),nums.end());
        int v1,v2;
        for(int i=0;i<nums.size();i++){
            int val2=target-nums[i];
            int count=arr.count(val2);
            if(count>=1){
                auto it=find(nums.begin(),nums.end(),val2);
                if(it!=nums.end()){
                    v1=i;
                    v2=it-nums.begin();
                }
            }
        }
        return {v2,v1}; 
    }
};
