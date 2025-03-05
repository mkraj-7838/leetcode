class Solution {
public:
    long long coloredCells(int n) {
        if (n == 1)
            return 1;

        long long ans = 1, val = 4;
        for (int i = 2; i <= n; i++) {
            ans += val;
            val = 4 * i;
        }
        return ans;
    }
};