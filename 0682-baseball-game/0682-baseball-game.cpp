class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> score;
        for (string& op : ops) {
            if (op == "C") score.pop_back();
            else if (op == "D") score.push_back(2 * score.back());
            else if (op == "+") score.push_back(score.back() + score[score.size() - 2]);
            else score.push_back(stoi(op));
        }
        return accumulate(score.begin(), score.end(), 0);
    }
};