class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int count = 0;
        string word = "";
        
        for (int i = 0; i <= sentence.size(); i++) {
            if (i == sentence.size() || sentence[i] == ' ') {
                count++;
                if (word.find(searchWord) == 0) {
                    return count;
                }
                word = "";
            } else {
                word += sentence[i];
            }
        }
        return -1;
    }
};