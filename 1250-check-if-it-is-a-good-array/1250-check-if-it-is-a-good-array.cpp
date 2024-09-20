class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int gcdVal=nums[0];
        for(int i=1; i<nums.size(); i++){
            gcdVal = gcd(gcdVal, nums[i] );
            if(gcdVal==1){
                return true;
            }
        }
        return gcdVal==1;
    }
};