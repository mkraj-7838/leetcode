class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.length();
        int a = 0, b = 0, c = 0;
        for (char ch : s) {
            if (ch == 'a')
                a++;
            if (ch == 'b')
                b++;
            if (ch == 'c')
                c++;
        }
        a = a - k, b = b - k, c = c - k;
        if(a<0 || b<0 || c<0) return -1;
        int cnt_a = 0, cnt_b = 0, cnt_c = 0;
        int r = 0, l = 0, maxi = -1;
        while (r < n) {
            if (s[r] == 'a')
                cnt_a++;
            if (s[r] == 'b')
                cnt_b++;
            if (s[r] == 'c')
                cnt_c++;
            while (cnt_a > a || cnt_b > b || cnt_c > c) {
                if (s[l] == 'a'){
                    cnt_a--;}
                if (s[l] == 'b'){
                    cnt_b--;}
                if (s[l] == 'c'){
                    cnt_c--;}
                cout<<l<<endl;
                l++;
            }
            maxi = max(maxi, r - l + 1);
            r++;
        }
        return (maxi == -1) ? -1 : (n-maxi);
    }
};