class Solution {
public:
    bool judgeSquareSum(int c) {
        int a=0;
        long b=(long)sqrt(c);

        while(a<=b){
            long long num=a*a+b*b;
            if(num==c) return true;
            else if(num<c) a++;
            else b--;
        }
        return false;
    }
};