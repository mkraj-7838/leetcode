class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int validSplit = 0;
        long long totalSum =
            accumulate(nums.begin(), nums.end(), 0LL); // Total sum of the array
        long long leftSum = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            leftSum += nums[i]; // Add current element to left sum
            long long rightSum = totalSum - leftSum; // Calculate right sum
            if (leftSum >= rightSum) {
                validSplit++;
            }
        }
        return validSplit;
    }
};