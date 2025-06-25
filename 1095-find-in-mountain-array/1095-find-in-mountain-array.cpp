/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findPeakIndex(MountainArray &arr, int n) {
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr.get(mid) < arr.get(mid + 1))
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
    int searchIncreasing(MountainArray &arr, int low, int high, int target) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int val = arr.get(mid);
            if (val == target)
                return mid;
            else if (val < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
    int searchDecreasing(MountainArray &arr, int low, int high, int target) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int val = arr.get(mid);
            if (val == target)
                return mid;
            else if (val > target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        
        // Step 1: Find peak index
        int peak = findPeakIndex(mountainArr, n);

        // Step 2: Search in the increasing part
        int index = searchIncreasing(mountainArr, 0, peak, target);
        if (index != -1) return index;

        // Step 3: Search in the decreasing part
        return searchDecreasing(mountainArr, peak + 1, n - 1, target);
    }
};