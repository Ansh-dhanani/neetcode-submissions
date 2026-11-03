class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0;
        int right=0;
        int ans=0;
        vector<int> freq(26,0);
        while(left<=right && right<s.size()){
            freq[s[right]-'A']++;
            int max;
            auto it=max_element(freq.begin(),freq.end());
            if(it!=freq.end()){
                max=*it;
            }else{
                max=0;
            }
            int other=accumulate(freq.begin(),freq.end(),0);
            other-=max;
            if(other>k){
                freq[s[left]-'A']--;
                left++;
                // freq[s[left]-'A']++;
            }else{
                ans=std::max(ans,max+other);
            }
            right++;
        }
        return ans;
    }
};
