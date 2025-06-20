class Solution {
public:
    int maxDistance(string s, int k) {
        int n = 0, south = 0, e = 0, w = 0;

        for (char ch : s) {
            if (ch == 'N')
                n++;
            else if (ch == 'S')
                south++;
            else if (ch == 'E')
                e++;
            else if (ch == 'W')
                w++;
        }

        int x = e - w;
        int y = n - south;

        int maxChange = min(k, (int)s.length());

        return abs(x) + abs(y) + 2 * maxChange;
    }
};