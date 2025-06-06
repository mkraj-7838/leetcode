class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long l = 0, r = 0;
        long long ans = 0, count = 0;
        unordered_map<int, int> mp;
        int n = nums.size();
        while (r < n) {
            mp[nums[r]]++;
            count += (mp[nums[r]] - 1);
            while (l < n && (count - (mp[nums[l]] - 1)) >= k) {
                mp[nums[l]]--;
                count -= mp[nums[l]];
                l += 1;
            }
            if (count >= k) {
                ans += (l + 1);
            }
            r++;
        }
        return ans;
    }
};