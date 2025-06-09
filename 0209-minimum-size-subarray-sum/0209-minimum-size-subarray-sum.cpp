class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minSize = INT_MAX;
        int preSum = 0;
        int i = 0, j = 0;
        while (j < n) {
            preSum = preSum + nums[j];
            while (preSum >= target) {
                minSize = min(minSize, j - i + 1);
                preSum -= nums[i];
                i++;
            }
            j++;
        }
        return (minSize == INT_MAX) ? 0 : minSize;
    }
};
