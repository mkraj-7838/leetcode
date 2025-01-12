class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s); // To split the string `s` into words
        string word;

        while (ss >> word) {
            words.push_back(word);
        }
        // If the lengths mismatch, return false
        if (pattern.size() != words.size()) {
            return false;
        }

        unordered_map<char, string> letterToWord;
        unordered_map<string, char> wordToLetter;

        for (int i = 0; i < pattern.size(); ++i) {
            char letter = pattern[i];
            string word = words[i];

            // Check if letter is already mapped
            if (letterToWord.count(letter)) {
                if (letterToWord[letter] != word) {
                    return false;
                }
            } else {
                letterToWord[letter] = word;
            }

            // Check if word is already mapped
            if (wordToLetter.count(word)) {
                if (wordToLetter[word] != letter) {
                    return false;
                }
            } else {
                wordToLetter[word] = letter;
            }
        }

        return true;
    }
};