class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> nums;
        for(int i=1; i<=n; i++){
            if(n%i==0) nums.push_back(i); 
        }
        int size=nums.size();
        if(size<k) return -1;
        return nums[k-1];
    }
};