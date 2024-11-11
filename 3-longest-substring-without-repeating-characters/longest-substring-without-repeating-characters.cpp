class Solution {
public:
    int lengthOfLongestSubstring(string s) {
          map<char, int> mp; // To store the frequency of characters in the current window
    int max_count = 0;  // To store the maximum length of unique substring
    int l = 0;          // Left pointer of the window
    
    // Loop through the string with the right pointer `r`
    for (int r = 0; r < s.size(); r++) {
        char ch = s[r];

        // If the character at `r` is already in the window (map), move `l` to remove duplicates
        while (mp.find(ch) != mp.end() && mp[ch] > 0) {
            // Decrease the count of the character at `l` and move `l` to the right
            mp[s[l]]--;
            l++;
        }

        // Add the current character to the window (map)
        mp[ch]++;

        // Update the maximum length of the substring
        max_count = max(max_count, r - l + 1);
    }

    return max_count;
}
        
    
};