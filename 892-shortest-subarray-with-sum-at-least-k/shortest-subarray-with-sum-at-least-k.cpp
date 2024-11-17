class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        // Create a prefix sum array
        vector<long long> prefixSum(n + 1, 0);
        
        // Compute the prefix sum
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        int mini = INT_MAX;  // Initialize the minimum length as the largest possible value
        
        // Deque to store indices of the prefix sum array
        deque<int> dq;
        
        for (int i = 0; i <= n; ++i) {
            // Check if we can find a valid subarray with sum >= k
            while (!dq.empty() && prefixSum[i] - prefixSum[dq.front()] >= k) {
                mini = min(mini, i - dq.front());  // Update the minimum length
                dq.pop_front();  // Remove the front of the deque
            }

            // Maintain the deque in increasing order of prefix sums
            while (!dq.empty() && prefixSum[i] <= prefixSum[dq.back()]) {
                dq.pop_back();
            }

            // Add the current index to the deque
            dq.push_back(i);
        }
        
        return mini == INT_MAX ? -1 : mini;  // If no subarray is found, return -1
    }
};
