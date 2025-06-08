class Solution {
public:
    string originalDigits(string s) {
        int n = s.size();
        map<char,int> freq;
        for(auto it: s) freq[it]++;
        vector<int> d(10);
        d[0] = freq['z'];
        d[1]  = freq['o']-freq['z']-freq['w']-freq['u'];
        d[2] = freq['w'];
        d[3] = freq['h']-freq['g'];
        d[4] = freq['u'];
        d[5] = freq['f']-freq['u'];
        d[6] = freq['x'];
        d[7] = freq['s']-freq['x'];
        d[8] = freq['g'];
        d[9] = freq['i']-d[6]-d[5]-d[8];
        string ans = "";
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < d[i]; j++){
                char c = '0'+i;
                ans+=c;
            }
        }
        return ans;
    }
};