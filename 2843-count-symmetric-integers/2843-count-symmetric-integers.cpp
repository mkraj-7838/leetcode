class Solution {
    int digitCnt(int n) {
        if (n == 0)
            return 1;
        return floor(log10(n)) + 1;
    }

public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for (int i = low; i <= high; i++) {
            int digit = digitCnt(i);
            if (digit % 2 == 0) {
                int temp = i;
                int lSum = 0, rSum = 0;
                int d = digit;

                for (int j = 0; j < d; j++) {
                    int digitVal = temp % 10;
                    temp /= 10;
                    if (j < d / 2)
                        rSum += digitVal; // Right side (since we're reading from LSB)
                    else
                        lSum += digitVal;
                }

                if (lSum == rSum)
                    cnt++;
            }
        }
        return cnt;
    }
};
