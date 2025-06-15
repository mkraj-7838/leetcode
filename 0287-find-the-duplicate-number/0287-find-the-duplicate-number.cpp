class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int ans;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i]==nums[j]){
                    ans = nums[i];
                    break;
                } 
            }
            if(ans == nums[i]) break;
        }
        return ans;
    }
};