class Solution {
public:
    int countSubsetSum(vector<int>& arr, int sum) {
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;  // base case

        for (int num : arr) {
            for (int j = sum; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }
        return dp[sum];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        // invalid case
        if (sum < abs(target) || (sum + target) % 2 != 0) 
            return 0;

        int s1 = (sum + target) / 2;
        return countSubsetSum(nums, s1);
    }
};
