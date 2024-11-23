class Solution {
    int convert(string& s) {
        string h, m;
        h += s[0];
        h += s[1];

        m += s[3];
        m += s[4];

        int cnt = 0, HH, MM;
        HH = stoi(h);
        MM = stoi(m);

        for (int i = 0; i <= HH; i++) {
            cnt = cnt + 60;
        }
        cnt += MM;
        return cnt;
    }

public:
    int convertTime(string current, string correct) {
        int curr = convert(current);
        int corr = convert(correct);
        int ans = abs(curr - corr);
        int result = 0;
        if (ans >= 60) {
            result += ans / 60;
            ans = ans % 60;
        }
        if (ans >= 15) {
            result += ans / 15;
            ans = ans % 15;
        }
        if (ans >= 5) {
            result += ans / 5;
            ans = ans % 5;
        }
        return ans + result;
    }
};