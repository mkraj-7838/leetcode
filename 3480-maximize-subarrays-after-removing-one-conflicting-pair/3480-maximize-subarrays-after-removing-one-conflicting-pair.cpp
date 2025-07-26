class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        int m = conflictingPairs.size();
        long long total = 1LL * n * (n + 1) / 2;
        long long maxValid = 0;

        for (int i = 0; i < m; ++i) {
            long long invalid = 0;

            for (int j = 0; j < m; ++j) {
                if (i == j) continue;

                int a = conflictingPairs[j][0];
                int b = conflictingPairs[j][1];
                int l = min(a, b);
                int r = max(a, b);

                invalid += 1LL * l * (n - r + 1);
            }

            long long valid = total - invalid;
            maxValid = max(maxValid, valid);
        }

        return maxValid;
    }
};