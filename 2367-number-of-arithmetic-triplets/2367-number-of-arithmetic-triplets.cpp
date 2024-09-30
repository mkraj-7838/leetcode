class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_set<int> seen(nums.begin(), nums.end());
        int count = 0;
        for (int num : nums) {
            if (seen.find(num - diff) != seen.end() && seen.find(num - 2 * diff) != seen.end()) {
                count++;
            }
        }
        return count;
    }
};