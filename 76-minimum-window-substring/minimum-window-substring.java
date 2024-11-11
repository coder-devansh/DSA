public class Solution {
    public String minWindow(String s, String t) {
        String ans = "";
        if (t.length() > s.length()) {
            return ans;  // If s is smaller than t, return empty string
        }

        // Arrays to store the frequencies of characters in t and in the current window
        int[] targetFreq = new int[256]; // Frequency of characters in t
        int[] windowFreq = new int[256]; // Frequency of characters in current window

        // Populate targetFreq with the characters of t
        for (char c : t.toCharArray()) {
            targetFreq[c]++;
        }

        // Sliding window variables
        int l = 0, r = 0;  // Left and right pointers
        int minLen = Integer.MAX_VALUE;  // Minimum window length
        StringBuilder sb = new StringBuilder();  // StringBuilder to store the window content
        int required = t.length();  // Number of characters to match
        int formed = 0;  // How many characters in the current window meet the target frequency

        while (r < s.length()) {
            // Add the character at the right pointer to the window
            char currentChar = s.charAt(r);
            windowFreq[currentChar]++;
            sb.append(currentChar);  // Append to the StringBuilder

            // If the frequency of the current character in the window matches the target frequency
            if (windowFreq[currentChar] <= targetFreq[currentChar]) {
                formed++;
            }

            // Now, try to shrink the window from the left as long as it's valid
            while (l <= r && formed == required) {
                char leftChar = s.charAt(l);

                // Update the result if we found a smaller valid window
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    ans = sb.toString();  // Save the minimum window substring
                }

                // Remove the leftmost character from the window
                windowFreq[leftChar]--;
                if (windowFreq[leftChar] < targetFreq[leftChar]) {
                    formed--;  // We no longer have a valid character
                }

                sb.deleteCharAt(0);  // Remove the character from the StringBuilder (shift window)
                l++;  // Shrink the window from the left
            }

            // Move the right pointer to expand the window
            r++;
        }

        return ans; 
    }
} 