class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lines = 1, width = 0;
        for(int i=0; i<s.length(); i++) {
            if(widths[s[i] - 97] + width > 100) {
                lines++;
                width = widths[s[i] - 97];
            }
            else
                width += widths[s[i] - 97];
        }
        return {lines, width};
    }
};