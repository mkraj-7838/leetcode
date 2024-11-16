class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        int n=nums.size();
        if(n==1) return {nums[0]};
        for(int i=0; i<=n-k;i++){
            int maxi;
            int conti=0;;
            for(int j=i; j<i+k; j++){
                maxi=max(maxi, nums[j]);
                if(nums[j+1]==nums[j]+1) conti++;
                else break;
            }
            if(conti>=k-1) ans.push_back(maxi);
            else ans.push_back(-1);
        }
        return ans;
    }
};