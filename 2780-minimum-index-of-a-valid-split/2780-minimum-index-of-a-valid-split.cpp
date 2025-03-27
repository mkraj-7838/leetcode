class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> freq;
        int n = nums.size();
        int maxFreq = 0;
        int maxFreqNum = 0;
        for (int num : nums) {
            freq[num]++;
            if (freq[num] > maxFreq) {
                maxFreq = freq[num];
                maxFreqNum = num;
            }
        }
        int count = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == maxFreqNum)
                ++count;

            if (count * 2 > i + 1 && (maxFreq - count) * 2 > (n - i - 1))
                return i;
        }
        return -1;
    }
};