class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int l = n - 1; l >= 0; l--) {
            if (l < n-1 && nums[l] == nums[l + 1])
                    continue;
            for (int i = 0; i < n; i++) {
                if (i > 0 && nums[i] == nums[i - 1])
                    continue;
                int j = i + 1;
                int k = l - 1;
                while (j < k) {
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[k] + (long long)nums[l];
                    if (sum == (long long)target) {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        j++;
                        k--;
                        while (nums[j] == nums[j - 1] && j < k)
                            j++;
                        while (nums[k] == nums[k + 1] && j < k)
                            k--;                        
                    } else if (sum < (long long)target)
                        j++;
                    else
                        k--;
                }
            }
        }
        return ans;
    }
};