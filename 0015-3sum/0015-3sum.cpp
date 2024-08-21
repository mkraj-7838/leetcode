class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        set<vector<int>> arr;
        for(int i=0;i<n;i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
                vector<int> st={nums[i],nums[j],nums[k]};
                if(nums[i]+nums[j]+nums[k]==0){
                    arr.insert(st);
                    j++;
                    k--;
                }
                else if(nums[i]+nums[j]+nums[k]<0){
                    j++;
                }
                else k--;
            }

        }
        vector<vector<int>> ans(arr.begin(), arr.end());
        return ans;

    }
};
