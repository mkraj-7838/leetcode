class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.size();
        if(n==1) return s;
        vector<string> ans(numRows, "");
        int i=0;
        while(i<n){
            for(int rows=0;rows<numRows && i<n; rows++){
                ans[rows]+=s[i++];
            }
            for(int rows=numRows-2; rows>0 && i<n; rows--){
                ans[rows]+=s[i++];
            }
        }
        string result="";
        for(string c : ans){
            result+=c;
        }
        return result;
    }
};