class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(nums.size()==1) 1;

        int count=0;
        int maxProduct = 0;
        int n = nums.size();
        for (int l = 0; l < n; l++) {
            int product = 1;
            for (int i = l; i < n; i++) {
                product *= nums[i];
                if(product < k){
                    count++;
                }
            }
        }
        return count;
    }
};