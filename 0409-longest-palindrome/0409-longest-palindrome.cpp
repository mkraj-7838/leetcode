class Solution {
public:
    static int longestPalindrome(string& s) {
        bitset<58> freq=0; //'A'=65~'z'=122
        for(char c: s)
            freq.flip(c-'A');
        int len=s.size();
        for(int i=0; i<58; i++){
            if (freq[i]) len--;//odd freq len-=1
        }
        return len+(freq.count()>=1);
    }
};