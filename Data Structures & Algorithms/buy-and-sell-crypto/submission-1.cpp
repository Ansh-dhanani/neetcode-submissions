class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m=0;
        for(int i=0;i<prices.size()-1;i++){
            for(int j=i;j<prices.size();j++){
                m=max(m,prices[j]-prices[i]);
            }
        }
        return m;
    }
};
