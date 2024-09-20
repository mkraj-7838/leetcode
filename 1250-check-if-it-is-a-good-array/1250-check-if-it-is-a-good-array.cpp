class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int gcdVal=nums[0];
        for(int i=0; i<nums.size(); i++){
            gcdVal = gcd(gcdVal, nums[i] );
            if(gcdVal==1){
                return true;
            }
        }
        return false;
    }
};