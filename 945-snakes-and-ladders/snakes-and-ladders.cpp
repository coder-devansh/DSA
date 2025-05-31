class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int N = n * n;
        vector<int> nums(N + 1, -1); // use -1 as default
        vector<int> dist(N + 1, INT_MAX);
        
        // 1D conversion from 2D board
        int idx = 1;
        bool leftToRight = true;
        for (int i = n - 1; i >= 0; --i) {
            if (leftToRight) {
                for (int j = 0; j < n; ++j)
                    nums[idx++] = board[i][j];
            } else {
                for (int j = n - 1; j >= 0; --j)
                    nums[idx++] = board[i][j];
            }
            leftToRight = !leftToRight;
        }

        // BFS
        queue<int> q;
        dist[1] = 0;
        q.push(1);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int i = 1; i <= 6 && curr + i <= N; ++i) {
                int next = curr + i;
                int dest = nums[next] == -1 ? next : nums[next];

                if (dist[curr] + 1 < dist[dest]) {
                    dist[dest] = dist[curr] + 1;
                    q.push(dest);
                }
            }
        }

        return dist[N] == INT_MAX ? -1 : dist[N];
    }
};
