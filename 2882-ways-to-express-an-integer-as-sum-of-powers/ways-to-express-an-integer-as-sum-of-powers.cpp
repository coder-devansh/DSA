class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp;

    int find(int i, int target, int x) {
        int power = pow(i, x);
        if (power > target) return 0;
        if (power == target) return 1;

        if (dp[i][target] != -1) return dp[i][target];

        long long take = find(i + 1, target - power, x);
        long long skip = find(i + 1, target, x);

        return dp[i][target] = (take + skip) % MOD;
    }

    int numberOfWays(int n, int x) {
        int maxBase = pow(n, 1.0 / x);  // max value of i such that i^x <= n
        dp.resize(maxBase + 2, vector<int>(n + 1, -1));
        return find(1, n, x);
    }
};
