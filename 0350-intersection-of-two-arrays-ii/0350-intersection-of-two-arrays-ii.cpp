class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n1=nums1.size(), n2=nums2.size();
        vector<int>ans;
        int i=0, j=0;
        while(i<n1 && j<n2){
            if(nums1[i]==nums2[j]){
                ans.push_back(nums1[i]);
                i++;
                j++;
            } 
            else if(nums1[i]<nums2[j]){
                i++;
            }
            else j++;
        }
        return ans;
    }
};