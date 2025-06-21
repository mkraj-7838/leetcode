class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        list<int> maxL;
        int n=nums.size();
        int maxi=INT_MIN;
        int i=0, j=0;
        vector<int>ans;
        while(j<n){
            maxi=max(maxi, nums[j]);

            maxL.push_back(nums[j]);
            if(maxL.front()<maxi) maxL.pop_back();

            if(j-i+1<k) j++;

            else if(j-i+1==k){
                ans.push_back(maxi);

                if(maxL.size()>0 && maxL.front()==maxi){
                    maxL.pop_back();
                    maxi=maxL.front();
                }
                i++;
                j++;
            }


        }
        return ans;
    }
};