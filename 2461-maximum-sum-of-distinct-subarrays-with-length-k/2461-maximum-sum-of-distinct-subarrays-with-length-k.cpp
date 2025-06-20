class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n) return 0;
        long long maxi = LLONG_MIN;
        long long current_sum = 0; 
        unordered_map<int, int> freq_map;
        int left = 0;
        for (int right = 0; right < n; ++right) {
            
            freq_map[nums[right]]++;
            current_sum += nums[right];
            
            while (freq_map[nums[right]] > 1 || right - left + 1 > k) {
                freq_map[nums[left]]--;
                current_sum -= nums[left];
                left++;
            }
            if (right - left + 1 == k) {
                maxi = max(maxi, current_sum);
            }
        }
        return maxi == LLONG_MIN ? 0 : maxi;
    }
};