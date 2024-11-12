class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        // Edge case: If words is empty or s is empty, return empty result.
        if (words.empty() || s.empty()) return {};

        int wordLength = words[0].size();
        int totalLength = wordLength * words.size();
        map<string, int> mp; // To store frequency of words in the 'words' list
        vector<int> result;
        
        // Populate the map with word frequencies
        for (const string& word : words) {
            mp[word]++;
        }

        // Sliding window approach
        for (int i = 0; i < wordLength; i++) { // Loop to handle different starting positions
            int l = i, r = i;
            map<string, int> found;  // To store the current found words in the sliding window
            int count = 0;  // To track the number of valid words found in the current window

            while (r + wordLength <= s.size()) {
                // Get the next word in the window
                string word = s.substr(r, wordLength);
                r += wordLength;

                // If the word is valid (it exists in the words list)
                if (mp.find(word) != mp.end()) {
                    found[word]++;
                    count++;

                    // If we've found the word more times than it appears in words, move left pointer
                    while (found[word] > mp[word]) {
                        string leftWord = s.substr(l, wordLength);
                        found[leftWord]--;
                        count--;
                        l += wordLength;  // Shrink the window from the left
                    }

                    // If we've found all words in the correct number, add the index to the result
                    if (count == words.size()) {
                        result.push_back(l);
                    }
                } else {
                    // If the word is not in words, reset the window
                    found.clear();
                    count = 0;
                    l = r; // Move the left pointer to the right of the current invalid word
                }
            }
        }

        return result;
    }
};
