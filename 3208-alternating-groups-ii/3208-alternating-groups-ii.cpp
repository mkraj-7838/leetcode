class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            bool valid = true;

            for (int j = 0; j < k - 1; j++) {
                if (colors[(i + j) % n] == colors[(i + j + 1) % n]) {
                    valid = false;
                    break;
                }
            }
            if (valid) count++;
        }

        return count;
    }
};