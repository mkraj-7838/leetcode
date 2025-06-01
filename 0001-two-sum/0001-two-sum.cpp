class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int first=INT_MIN, sec=INT_MIN;
        for(int i=0; i<nums.size()-1; i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i]+nums[j]==target) {
                    first=i;
                    sec=j;
                }
            }
        }
        return {first,sec};
    }
};