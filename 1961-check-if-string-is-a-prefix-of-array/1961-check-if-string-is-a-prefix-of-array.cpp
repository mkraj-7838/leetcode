class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int i;
        string s1;
        for(i=0;i<words.size();i++)
        {
            s1 += words[i];
            if(s1==s)
            {
                return true;
            }
        }
        return false;
    }
};