class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
        int maxC=0;
        for(int num: nums){
            if(num==1){
                count++;
                maxC=max(maxC, count);
            }
            else count=0;
        }
        return maxC;
    }
};