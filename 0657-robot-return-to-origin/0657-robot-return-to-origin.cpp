class Solution {
public:
    bool judgeCircle(string moves) {
        int LR=0;
        int UD=0;
        int n=moves.length();
        for(int i=0; i<n; i++){
            if(moves[i]=='R') LR++;
            else if(moves[i]=='L') LR--;
            else if(moves[i]=='U') UD++;
            else UD--;
        }
        return (LR==0 && UD==0)?true:false;
    }
};