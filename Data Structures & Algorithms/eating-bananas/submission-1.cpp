class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // if(h>piles.size()) return -1;
        int left=1;
        int right=*std::max_element(piles.begin(), piles.end());
        int ans=right;

        while(left<=right){
            int  mid=left + (right - left) / 2; 
            long long hours=0;
            for(int i=0;i<piles.size();i++){
                hours+=ceil((double)piles[i]/mid);
            }
            if(hours<=h){
                ans=min(ans,mid);
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return ans;
    }
};
