class Solution {
public:
    bool isPrime(int num) {
        if (num < 2)
            return false;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0)
                return false;
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int> arr;
        for (int i = left; i <= right; i++) {
            if (isPrime(i)) {
                arr.push_back(i);
            }
        }
        int pair1 = -1, pair2 = -1;
        int mini = INT_MAX;
        if (arr.size() > 1) {
            for (int i = 0; i < arr.size() - 1; i++) {
                if (mini > abs(arr[i] - arr[i + 1])) {
                    mini = min(mini, abs(arr[i] - arr[i + 1]));
                    pair1 = arr[i], pair2 = arr[i + 1];
                }
            }
        }

        return {pair1, pair2};
    }
};