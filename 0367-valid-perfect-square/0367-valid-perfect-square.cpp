class Solution {
public:
    bool isPerfectSquare(int x) {
        if(x==0 || x==1){
            return true;
        }
        long start=1;
        long end=x;
        long mid=-1;

        while(start<=end){
            mid=start+(end-start)/2;
            if(mid*mid==x) return true;
            else if(mid*mid>x) end=mid-1;
            else start=mid+1;
        }
        return false;
    }
};