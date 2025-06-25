class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] > nums[mid + 1])
                end = mid; // peak is in the left half or at mid
            else
                start = mid + 1; // peak is in the right half
        }

        return start; // or return end, both are same here
    }
};
