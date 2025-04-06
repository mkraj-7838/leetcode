class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) return {};
        
        int n = nums.size();
        sort(nums.begin(), nums.end()); // Step 1: Sort the array
        
        vector<int> dp(n, 1), prev(n, -1);
        int maxSize = 1, maxIndex = 0;

        // Step 2: Build DP table
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > maxSize) {
                maxSize = dp[i];
                maxIndex = i;
            }
        }

        // Step 3: Reconstruct the subset
        vector<int> res;
        for (int i = maxIndex; i >= 0; i = prev[i]) {
            res.push_back(nums[i]);
            if (prev[i] == -1) break;
        }

        reverse(res.begin(), res.end()); // Maintain correct order
        return res;
    }
};