class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        int maxDiff=INT_MIN;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(nums[j]>nums[i]){
                    maxDiff = max( maxDiff , nums[j] - nums[i] );
                } 
            }            
        }

        return maxDiff==INT_MIN?-1:maxDiff;
    }
};