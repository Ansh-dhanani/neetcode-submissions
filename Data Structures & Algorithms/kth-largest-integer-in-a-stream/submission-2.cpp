class KthLargest {
private:
    multiset<int> m;
    int k=0;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int n:nums){
            add(n);
        }
    }
    
    int add(int val) {
        m.insert(val);
        while(m.size()>k){
            m.erase(m.begin());
        }
        return *m.begin();
    }
};
