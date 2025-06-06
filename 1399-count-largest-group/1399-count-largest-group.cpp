class Solution {
    int sumOfDigits(int num) {
        int sum = 0;
        while (num > 0) {
            sum = sum + num % 10;
            num = num / 10;
        }
        return sum;
    };

public:
    int countLargestGroup(int n) {
        vector<int> count(10000, 0);
        int cnt = 0;
        int maxSize = 0;
        for (int i = 1; i <= n; i++) {
            int sum = sumOfDigits(i);
            count[sum]++;

            if (count[sum] == maxSize) {
                cnt++;
            } else if (count[sum] > maxSize) {
                maxSize = count[sum];
                cnt = 1;
            }
        }
        return cnt;
    }
};