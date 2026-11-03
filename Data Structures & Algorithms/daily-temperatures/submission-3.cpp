class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans(n,0);
        stack<int> stk;
        int i = n-1;
        while (i >= 0) {
            if (stk.empty()) {
                stk.push(i);
                ans[i]=0;
            } else {
                while (!stk.empty() && temperatures[stk.top()] <= temperatures[i]) {
                    stk.pop();
                }
                if (stk.empty()) {
                    stk.push(i);
                    ans[i]=0;
                } else {
                    ans[i]=stk.top() - i;
                    stk.push(i);
                }
            }
            --i;
        }
        return ans;
    }
};
