class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> arr;
        int size=nums.size();
        int left=0, right=size-1;
        arr=nums;
        sort(arr.begin(), arr.end());
        while(left<right){
            int sum=arr[left]+arr[right];
            if(sum==target){
                int i=0,j=0;
                for(i;i<size;i++)
                    if(arr[left]==nums[i])
                        break;
                for(j=size-1;j>0;j--)
                    if(arr[right]==nums[j])
                        break;                
                return {i,j};
            }
            else if (sum<target) left++;
            else right--;
        }
        return {-1,-1};
    }
};