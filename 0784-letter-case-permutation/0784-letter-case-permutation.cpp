class Solution {
public:
    void solve(vector<string>& ans, string ip, string op) {
        if (ip.size() == 0) {
            ans.push_back(op);
            return;
        }
        if(isalpha(ip[0])) {
            string op1 = op;
            string op2 = op;

            op1.push_back(tolower(ip[0]));
            op2.push_back(toupper(ip[0]));
            ip.erase(ip.begin()+0);

            solve(ans, ip, op1);
            solve(ans, ip, op2);
        }else{
            string op1 = op;
            op1.push_back(ip[0]);
            ip.erase(ip.begin()+0);
            solve(ans, ip, op1);
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string op = "";
        solve(ans, s, op);
        return ans;
    }
};