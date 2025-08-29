class Solution {
public:
    long long flowerGame(int n, int m) {

        long long nOdd=(n+1)/2;
        long long nEven=n/2;
        long long mOdd=(m+1)/2;
        long long mEven=m/2;
        return nOdd*mEven+mOdd*nEven;
    }
};