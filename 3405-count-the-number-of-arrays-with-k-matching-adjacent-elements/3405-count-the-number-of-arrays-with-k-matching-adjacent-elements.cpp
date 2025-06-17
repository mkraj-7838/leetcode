int MOD = 1e9+7;
class Solution {
public:

    // binary exponention formula to compute power TC O(log(b)
    int findPower(long long a,long long b){
        if(b == 0){
            return 1;
        }

        long long half = findPower(a,b/2);
        long long res = (half*half)%MOD;

        // if the power is odd then multiply once again 
        if(b%2 == 1){
            res = (res*a)%MOD;
        }
        return res;
    }

    // apply the normal nCr formula
    long long nCr(int n,int r, vector<long long> &factorial, vector<long long> &fermatFact){
        // n!/((n-r)! * r!)) % MOD
        // n! * ((n-r)^-1)! * (r^-1)!

        return factorial[n] * fermatFact[n-r]%MOD * fermatFact[r]%MOD; //O(1) bz all are precalculated values
    }

    int countGoodArrays(int n, int m, int k) {
        vector<long long> factorial(n+1,1);
        factorial[0] = 1;
        factorial[1] = 1;

        // precalculate the factorial
        for(int i = 2;i<=n;i++){
            factorial[i] = (factorial[i-1]*i) %MOD;
        }

        // precalculate the inverse factorial using Fermat Little theoram
        vector<long long> fermatFact(n+1,1);

        for(int i = 0;i<=n;i++){
            fermatFact[i] = findPower(factorial[i],MOD-2);
        }

        long long res = nCr(n-1,k,factorial,fermatFact); //n-1Ck

        res = (res * m) % MOD;
        res = (res * findPower(m-1,n-k-1))%MOD;

        return res;
    }
};