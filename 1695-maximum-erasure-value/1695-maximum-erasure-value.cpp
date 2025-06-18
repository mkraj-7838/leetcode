class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int n = nums.size();
        int maxS = 0, currentSum = 0;
        int left = 0;
        for (int right = 0; right < n; right++) {
            if (mpp.find(nums[right]) != mpp.end() &&
                mpp[nums[right]] >= left) {
                int dupIdx = mpp[nums[right]];
                while (left <= dupIdx) {
                    currentSum -= nums[left];
                    mpp.erase(nums[left]);
                    left++;
                }
            }
            currentSum += nums[right];
            mpp[nums[right]] = right;
            maxS = max(maxS, currentSum);
        }
        return maxS;
    }
};