class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int a=0, b=0, c=0;
        for(int i=n-1; i>=2; i--){
            a=nums[i-2],b=nums[i-1], c=nums[i];
            if(a+b>c) return a+b+c;
        }
        return 0;

    }
};