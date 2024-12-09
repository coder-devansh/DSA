class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<bool> res;

        // Step 1: Precompute "bad" conditions (consecutive even or odd numbers)
        vector<int> bad(n, 0);
        
        // Mark where we have consecutive even or odd numbers
        for (int i = 1; i < n; i++) {
            if ((nums[i] % 2 == 0 && nums[i - 1] % 2 == 0) || (nums[i] % 2 != 0 && nums[i - 1] % 2 != 0)) {
                bad[i] = 1; // Mark this position as having a "bad" condition
            }
        }

        // Step 2: Create a prefix sum array for quick range queries
        vector<int> prefix(n, 0);
        prefix[0] = bad[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + bad[i];
        }

        // Step 3: Process each query
        for (const auto& query : queries) {
            int start = query[0], end = query[1];
            // Check if there's a "bad" condition in the range [start, end]
            bool hasBadCondition = (start > 0) ? prefix[end] - prefix[start] > 0 : prefix[end] > 0;
            res.push_back(!hasBadCondition);  // If there is no bad condition, it's a valid subarray
        }

        return res;
    }
};
