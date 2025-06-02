class Solution {
public:
    int distributeCandies(int n, int limit) {
        int ways=0;
        for(int ch1=0; ch1<=min(n,limit); ch1++){
            for(int ch2=0; ch1<min(n-ch1, limit); ch2++){
                int ch3=n-ch1-ch2;
                if(ch1+ch2+ch3==n) ways++;
            }
        }
        return ways;
    }
};