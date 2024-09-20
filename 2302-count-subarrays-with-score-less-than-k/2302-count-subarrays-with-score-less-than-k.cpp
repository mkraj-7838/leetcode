class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long count = 0;
        int n = nums.size();
        long long sum = 0;
        int left = 0;
        
        for (int right = 0; right < n; right++) {
            sum += nums[right];  // Add nums[right] to the sum
            
            while ((sum * (right - left + 1)) >= k) {  // Check the product of sum and the length of the subarray
                sum -= nums[left];  // Reduce sum by nums[left]
                left++;  // Move left pointer to the right
            }
            
            count += (right - left + 1);  // Add the number of valid subarrays ending at 'right'
        }
        
        return count;
    }
};
