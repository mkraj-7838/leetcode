class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size())
            return false;

        queue<char> q1, q2;
        for (char c : s) {
            q1.push(c);
        }
        for (char c : goal) {
            q2.push(c);
        }
        int k = goal.size(); // Initialize k as goal.size()

        while (k--) {
            if (q1 == q2)
                return true;
            char ch = q2.front();
            q2.pop();
            q2.push(ch);
        }
        return false;
    }
};