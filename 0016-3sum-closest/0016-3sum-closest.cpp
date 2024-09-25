class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int closeSum = nums[0] + nums[1] + nums[2];  
        int mini = abs(closeSum - target);
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            
            int j = i + 1;
            int k = n - 1;
            
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                
                if (sum == target) return sum;
                
                int diff = abs(sum - target);
                if (diff < mini) {
                    mini = diff;
                    closeSum = sum;
                }
                
                if (sum < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return closeSum;
    }
};
