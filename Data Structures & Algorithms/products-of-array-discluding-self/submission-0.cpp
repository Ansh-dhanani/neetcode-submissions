class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr1(n+2,1);
        vector<int> arr2(n+2,1);
        vector<int> ans;
        int k=nums.size()-1;
        for(int i=1;i<nums.size()+1;i++){
            arr1[i]=arr1[i-1]*nums[i-1];
        }
        for(int i=nums.size();i>0;i--){
            arr2[i]=arr2[i+1]*nums[i-1];
        }
        
        for(int i=1;i<arr1.size()-1;i++){
            ans.push_back(arr1[i-1]*arr2[i+1]);
        }
        return ans;
    }
};
