class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int aSum = nums[0];
        int maxSum = aSum;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                aSum += nums[i];
            } else {
                maxSum = max(maxSum, aSum);
                aSum = nums[i]; // Start new ascending sum
            }
        }

        maxSum = max(maxSum, aSum); // Final check
        return maxSum;
    }
};