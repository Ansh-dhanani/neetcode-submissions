class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mp=0;
       for(int i=0;i<prices.size()-1;i++){
            for(int j=i+1;j<prices.size();j++){
                if(prices[j]>prices[i]){
                    mp=max(mp,prices[j]-prices[i]);
                }
            }
       } 
       return mp;
    }
};
