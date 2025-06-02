class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int lcnt=0;
        int rcnt=0;
        int n=moves.size();
        for(int i=0; i<n ; i++){
            if(moves[i]=='L') lcnt++;
            if(moves[i]=='R') rcnt++;
        }
        return n-2*min(lcnt,rcnt);
    }
};