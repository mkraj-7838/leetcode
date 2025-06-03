class Solution {
public:
    bool isMonotonic(vector<int>& nums) { 
        int n=nums.size();
        int i=0;
        while (i < n-1 && nums[i] == nums[i + 1]) i++;
        

        if(i < n-1 && nums[i]>nums[i+1]){
            for(int j=i; j<n-1; j++){
                if(nums[j]<nums[j+1]) return false;
            }
        }
        else if(i < n-1 && nums[i]<nums[i+1]){
            for(int j=i; j<n-1; j++){
                if(nums[j]>nums[j+1]) return false;
            }
        }
        return true;
    }
};