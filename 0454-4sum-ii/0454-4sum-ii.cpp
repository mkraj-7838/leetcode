class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int>mpp;
        int n=nums1.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                mpp[nums1[i]+nums2[j]]++;
            }
        }
        int count=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int sum = -(nums3[i] + nums4[j]);
                if (mpp.find(sum) != mpp.end()) {
                    count += mpp[sum];
                }
            }
        }
        return count;
        
    }
};