class Solution {
public:
    bool isAnagram(string s, string t) {
        int freq1[126]={0};
        int freq2[126]={0};
        for(int i=0;i<s.length();i++){
            freq1[s[i]]++;
        }
        for(int i=0;i<t.length();i++){
            freq2[t[i]]++;
        }
        for(int i=0;i<126;i++)
        if(freq1[i]!=freq2[i]) return false;
        return true;
    }
};