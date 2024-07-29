class Solution {
public:
    bool check(vector<int>& nums) {

        int n = nums.size();
        if (n <= 2) {
            return true;
        }
        
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
        }
        return count <= 1;
    }
};