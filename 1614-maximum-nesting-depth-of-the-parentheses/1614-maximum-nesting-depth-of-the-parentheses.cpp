class Solution {
public:
    int maxDepth(string s) {
        int openB=0;
        int result=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                openB++;
                result=max(result,openB);
            }
            else if(s[i]==')')
                openB--;

        }
        return result;
    }
};