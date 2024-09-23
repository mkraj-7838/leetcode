class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0, y = 0;
        set<pair<int, int>> visited;
        visited.insert({x, y});
        for (char move : path) {
            if (move == 'N') {
                y += 1;
            } else if (move == 'S') {
                y -= 1;
            } else if (move == 'E') {
                x += 1;
            } else if (move == 'W') {
                x -= 1;
            }
            if (visited.find({x, y}) != visited.end()) {
                return true;
            }
            visited.insert({x, y});
        }
        return false;
    }
};