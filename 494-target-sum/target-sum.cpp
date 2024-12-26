class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int offset = 1000; // To handle negative sums, we shift the range by 1000
        int maxSum = 2000; // Total possible range [-1000, 1000] becomes [0, 2000]

        // Initialize DP table with size (n+1) x (maxSum+1) and set all values to 0
        vector<vector<int>> dp(n + 1, vector<int>(maxSum + 1, 0));

        // Base case: At index 0, sum of 0 (shifted by offset) can be achieved in 1 way
        dp[0][offset] = 1;

        // Fill the DP table iteratively
        for (int i = 1; i <= n; i++) {
            for (int currSum = 0; currSum <= maxSum; currSum++) {
                if (dp[i - 1][currSum] > 0) { // If there's a way to achieve this sum
                    // Add the current number
                    if (currSum + nums[i - 1] <= maxSum) {
                        dp[i][currSum + nums[i - 1]] += dp[i - 1][currSum];
                    }
                    // Subtract the current number
                    if (currSum - nums[i - 1] >= 0) {
                        dp[i][currSum - nums[i - 1]] += dp[i - 1][currSum];
                    }
                }
            }
        }

        // The answer is the number of ways to achieve the target shifted by offset
        return dp[n][target + offset];
    }
};
