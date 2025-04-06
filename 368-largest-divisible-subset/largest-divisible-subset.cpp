class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1), prev(n, -1);

        int max_len = 1;
        int last_index = 0;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }

            if (dp[i] > max_len) {
                max_len = dp[i];
                last_index = i;
            }
        }

        // Reconstruct subset
        vector<int> result;
        for (int i = last_index; i >= 0; i = prev[i]) {
            result.push_back(nums[i]);
            if (prev[i] == -1) break;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
