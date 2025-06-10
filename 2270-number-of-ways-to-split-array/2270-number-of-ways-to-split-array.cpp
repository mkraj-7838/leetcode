class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        int tSum=0; 
        for(int i=0; i<n; i++){
            tSum+=nums[i];
        }
        int cumSum=0;
        int count=0;
        for(int i=0; i<n-1; i++){
            cumSum+=nums[i];
            if(cumSum>=tSum-cumSum){
                count++;
            }
        }
        return count;
    }
};