class Solution {
public:
    vector<string> commonChars(vector<string>& words) 
    {
        vector<int> temp(26,INT_MAX);
        for (auto& word : words)
        {
            vector<int> t(26,0);
            for (char c : word)
            {
                t[c-'a']++;
            }
            for(int i=0;i<26;i++)
            {
                temp[i] = min(temp[i],t[i]);
            }
        }
        vector<string> res;
        for(int i=0;i<26;i++)
        {
            while(temp[i] > 0)
            {
                res.push_back(string(1,i+'a'));
                temp[i]--;
            }
        }
        return res;
    }
};