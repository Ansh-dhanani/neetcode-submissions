class Solution {
   public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int s:stones){
            pq.push(s);
        }        
        while(pq.size()>=2){
            int v1=pq.top();
            pq.pop();
            int v2=pq.top();
            pq.pop();
            if(pq.size()==0){
                if(v1==v2) return 0;
            }
            if(v1>v2){
                pq.push(v1-v2);
            }
        }
        return pq.top();
    }
};
