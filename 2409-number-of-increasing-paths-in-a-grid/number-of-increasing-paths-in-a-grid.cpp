class Solution{
    public:

const int MOD = 1000000007;  // Example modulus for large numbers
vector<vector<long long>>dp;

long long dfs(int row, int col, int n, int m, vector<vector<int>>& matrix) {
    if (dp[row][col] != -1) {
        return dp[row][col];
    }

int r[]={-1,0,1,0};
int c[]={0,1,0,-1};
    long long count = 1;

    for (int i = 0; i < 4; i++) {
        int new_row = row + r[i];
        int new_col = col + c[i];

        if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m && matrix[row][col] < matrix[new_row][new_col]) {
            count += dfs(new_row, new_col, n, m, matrix);
            count %= MOD;  // To ensure it doesn't overflow
        }
    }

    dp[row][col] = count;
    return dp[row][col];
}

int  countPaths(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    dp = vector<vector<long long>>(n, vector<long long>(m, -1));

    long long total_paths = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            total_paths += dfs(i, j, n, m, grid);
            total_paths %= MOD;  // To keep total result within bounds
        }
    }

    return total_paths;
}
};
