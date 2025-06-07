class Solution {
public:
    string clearStars(string s) {
        int n=s.length();
        vector<vector<int>>idx(26);
        string res="";
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
               for(int k=0;k<26;k++){
                if(idx[k].size()){
                s[idx[k].back()]='#';
                idx[k].pop_back();
                break;
                }
               }
            }
            else{
                idx[s[i]-'a'].push_back(i);
            }
        }
        for(int i=0;i<n;i++){
            if(s[i]!='*' && s[i]!='#')res+=s[i];
        }
        return res;
    }
};