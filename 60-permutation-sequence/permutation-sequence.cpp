#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        // Initialize factorials
        vector<int> factorial(n);
        factorial[0] = 1;
        for (int i = 1; i < n; ++i) {
            factorial[i] = factorial[i - 1] * i;
        }

        // Create a list of numbers to get permutations
        vector<int> numbers;
        for (int i = 1; i <= n; ++i) {
            numbers.push_back(i);
        }

        // Convert k to zero-based index
        k--;

        string result;
        for (int i = 0; i < n; ++i) {
            // Determine the index of the current digit
            int idx = k / factorial[n - 1 - i];
            result += to_string(numbers[idx]);

            // Remove used number
            numbers.erase(numbers.begin() + idx);

            // Update k for the next position
            k %= factorial[n - 1 - i];
        }

        return result;
    }
};

// Example usage
