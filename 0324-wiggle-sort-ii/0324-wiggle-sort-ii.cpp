class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        
        int n = nums.size();
        int j = (n + 1) / 2 - 1;  // end of smaller half
        int k = n - 1;            // end of larger half
        
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                nums[i] = sorted[j--]; // smaller half in even positions
            } else {
                nums[i] = sorted[k--]; // larger half in odd positions
            }
        }
    }
};
