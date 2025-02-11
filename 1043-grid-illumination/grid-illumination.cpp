class Solution {
public:
    set<pair<int, int>> lamp;
    unordered_map<int, int> row_mp;
    unordered_map<int, int> col_mp;
    unordered_map<int, int> diagonal_mp1;
    unordered_map<int, int> diagonal_mp2;

    int di[9] = {-1, -1, 0, 1, 1, 1, 0, -1, 0};
    int dc[9] = {0, 1, 1, 1, 0, -1, -1, -1, 0};
    vector<int> ans;
    vector<vector<int>> vis;
    void operate(int row, int col, int n) {
        if (row_mp[row] > 0 || col_mp[col] > 0 || diagonal_mp1[row - col] > 0 ||
            diagonal_mp2[row + col] > 0) {
            ans.push_back(1);
        } else {
            ans.push_back(0);
        }

        for (int k = 0; k < 9; k++) {
            int new_row = row + di[k];
            int new_col = col + dc[k];
            if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < n) {
                if (lamp.count({new_row, new_col})) {
                    lamp.erase({new_row, new_col});
                    row_mp[new_row]--;
                    col_mp[new_col]--;
                    diagonal_mp1[new_row - new_col]--;
                    diagonal_mp2[new_row + new_col]--;
                }
            }
        }
    }

    vector<int> gridIllumination(int n, vector<vector<int>>& lamps,
                                 vector<vector<int>>& queries) {

        for (auto it : lamps) {
            if (lamp.count({it[0], it[1]}))
                continue;
            lamp.insert({it[0], it[1]});
            row_mp[it[0]]++;
            col_mp[it[1]]++;
            diagonal_mp1[it[0] - it[1]]++;
            diagonal_mp2[it[0] + it[1]]++;
            // solve(it[0],it[1],board);
        }
        //    vis.resize(n,vector<int>(n,-1));
        for (auto& it : queries) {

            operate(it[0], it[1], n);
        }
        return ans;
    }
};