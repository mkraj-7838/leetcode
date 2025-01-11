class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0;
        int sum = 0;
        int min_size = INT_MAX;

        while (j < nums.size()) {
            sum += nums[j];

            while (sum >= target) { 
                min_size = min(min_size, j - i + 1);
                sum -= nums[i];
                i++;
            }
            
            j++;
        }

        return min_size == INT_MAX ? 0 : min_size;
    }
};