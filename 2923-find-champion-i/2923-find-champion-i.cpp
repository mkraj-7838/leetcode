class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> mp(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    if (grid[i][j] == 1)
                        mp[i]++;
                    else
                        mp[j]++;
                }
            }
        }
        int champ = 0; // Default to the first player.
        for (int i = 1; i < n; i++) {
            if (mp[i] > mp[champ]) {
                champ = i; // Update the champion's index.
            }
        }
        return champ;
    }
};