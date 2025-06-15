class Solution {
public:
    int reverse(int x) {
        int sign = 1;
        if (x < 0) {
            sign = -1;
            x = -1 * x;
        }
        long long ans = 0;
        while (x > 0) {
            int remain = x % 10;
            x = x / 10;
            ans = ans * 10 + remain;
        }
        ans *= sign;

        // Check 32-bit signed integer range
        if (ans < INT_MIN || ans > INT_MAX)
            return 0;

        return (int)ans;
    }
};