class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size=nums.size();
        int nonZeroCount=0;
        if(size<=1) return;

        for(int i=0; i<size; i++){
            if(nums[i]!=0){
                nums[nonZeroCount]=nums[i];
                nonZeroCount++;
            }
        }
        for(int i=nonZeroCount; i<size; i++)
            nums[i]=0;
    }
};