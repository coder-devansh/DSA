class Solution {
public:
    int count = 0;

    void solve(vector<vector<int>>& requests, vector<int>& res, int idx, int resu) {
        if (idx >= requests.size()) {
            // ✅ Check if all buildings are balanced
            for (int x : res) {
                if (x != 0) return;
            }
            count = max(count, resu);
            return;
        }

        // Include current request
        int u = requests[idx][0];
        int v = requests[idx][1];
        res[u]--;
        res[v]++;
        solve(requests, res, idx + 1, resu + 1);
        res[u]++;
        res[v]--; // backtrack

        // Exclude current request
        solve(requests, res, idx + 1, resu);
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> res(n, 0);
        solve(requests, res, 0, 0);
        return count;
    }
};
