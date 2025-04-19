class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int count=0;
        int n=nums.size();
        for(int i =0; i < n+1 ; i++){
            for(int j=i+1; j<n; j++){
                if(lower <= nums[i] + nums[j] &&  nums[i] + nums[j]<= upper){
                    count++;
                }
            }
        } 
        return count;
    }
};