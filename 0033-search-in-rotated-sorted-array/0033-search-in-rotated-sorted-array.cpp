class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // If found
        if (nums[mid] == target) return mid;

        // Check if left half is sorted
        if (nums[low] <= nums[mid]) {
            if (target >= nums[low] && target < nums[mid]) {
                high = mid - 1; // search in left half
            } else {
                low = mid + 1;  // search in right half
            }
        }
        // Else right half must be sorted
        else {
            if (target > nums[mid] && target <= nums[high]) {
                low = mid + 1;  // search in right half
            } else {
                high = mid - 1; // search in left half
            }
        }
    }
    return -1; // Not found
    }
};