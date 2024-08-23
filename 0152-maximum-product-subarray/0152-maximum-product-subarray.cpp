class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==1) return nums[0];

        int maxProduct = 0;
        int n = nums.size();
        for (int l = 0; l < n; l++) {
            int product = 1;
            for (int i = l; i < n; i++) {
                product *= nums[i];
                maxProduct = max(product, maxProduct);
            }
        }

        return maxProduct;
    }
};