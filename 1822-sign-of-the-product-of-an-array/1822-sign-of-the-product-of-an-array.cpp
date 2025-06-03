class Solution {
public:
    int arraySign(vector<int>& nums) {
        long long pdt=1;
        for(int i=0; i<nums.size(); i++){
            pdt=pdt*nums[i];
        }
        if(pdt>0) return 1;
        else if(pdt<0) return -1;
        else return 0;
    }
};