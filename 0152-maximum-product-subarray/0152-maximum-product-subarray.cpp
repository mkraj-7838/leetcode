class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int maxi=INT_MIN;
        int pre=1, suf=1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if(pre==0) pre=1;
            if(suf==0) suf=1;

            pre=pre*nums[i];
            suf=suf*nums[n-i-1];
            maxi=max(maxi, max(suf, pre));
        }
        return maxi;
    }
};