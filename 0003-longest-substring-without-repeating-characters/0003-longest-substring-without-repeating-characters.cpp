class Solution {
public:
    int lengthOfLongestSubstring(string s){
        int hash[256];
        fill(hash, hash+256,-1);
        int n=s.length();
        int left=0;
        int right=0;
        int maxlen=0;
        while(right<n){
            if(hash[s[right]]!=-1 && hash[s[right]]>=left){
                left=hash[s[right]]+1;
            }
            maxlen=max(maxlen,right-left+1);
            hash[s[right]]=right;
            right++;
        }
        return maxlen;
    }
};