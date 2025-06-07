class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        int dup,mis;
        for(int i=0;i<n;i++){
            if(nums[abs(nums[i])-1]<0){
                dup=abs(nums[i]);
            }else{
                nums[abs(nums[i])-1] *= (-1);
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                mis=i+1;
            }
        }
        return {dup,mis};
    }
};