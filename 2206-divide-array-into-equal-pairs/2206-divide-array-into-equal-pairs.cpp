class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> arr(501,0);
        for(int i=0; i<nums.size(); i++){
            arr[nums[i]]++;
        }
        for(int i=1; i<=500; i++){
            if((arr[i]%2)!=0) return false;
        }
        return true;
    }
};