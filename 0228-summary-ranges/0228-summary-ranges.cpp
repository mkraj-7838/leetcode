class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;
        int a, b;

        for (int i = 0; i < n; i++) {
            a = nums[i], b = nums[i];

            while (i + 1 < n && nums[i + 1] == nums[i] + 1) {
                i++;
                b = nums[i];
            }

            if (a == b)
                ans.push_back(to_string(a));
            else
                ans.push_back(to_string(a) + "->" + to_string(b));
        }
        return ans;
    }
};