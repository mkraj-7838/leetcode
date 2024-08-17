class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size=nums.size();
        int low=0,high=size-1;
        if(target>nums[size-1]) return size;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};