class Solution {
public:
    bool subsetSum(vector<int>& nums, int target) {
        int n = nums.size();
        // Create a DP table of size (n+1) x (target+1)
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        // Base case: A sum of 0 is always possible (empty subset)
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        // The answer is in dp[n][target]
        return dp[n][target];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum = sum + nums[i];
        }
        if(sum%2 != 0){
            return false;
        }
        else{
            return subsetSum(nums, sum/2);
        }
    }
};