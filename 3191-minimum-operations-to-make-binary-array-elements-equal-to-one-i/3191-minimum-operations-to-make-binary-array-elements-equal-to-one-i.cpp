class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        bool allOnes = true;

        for (int num : nums) {
            if (num == 0) {
                allOnes = false;
                break;
            }
        }

        if (allOnes)
            return 0;

        for (int i = 0; i <= n - 3; i++) {
            if (nums[i] == 0) {
                for (int j = i; j < i + 3; j++) {
                    nums[j] = (nums[j] == 0) ? 1 : 0;
                }
                count++;
            }
        }

        for (int num : nums) {
            if (num == 0)
                return -1;
        }

        return count;
    }
};