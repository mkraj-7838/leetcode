class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long peri = -1;
        sort(nums.begin(), nums.end());
        long long preSum = nums[0] + nums[1];
        for (int i = 2; i < nums.size(); i++) {
            if (preSum > nums[i]) {
                peri = preSum + nums[i];
            }
            preSum = preSum + nums[i];
        }
        return peri;
    }
};