class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) nums[i] |= (nums[nums[i]] % 1024) * 1024;
        for (int i = 0; i < n; ++i) nums[i] /= 1024;
        return nums;
    }
};