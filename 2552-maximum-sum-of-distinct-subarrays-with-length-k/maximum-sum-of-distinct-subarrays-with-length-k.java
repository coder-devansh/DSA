import java.util.HashMap;

class Solution {
    public long maximumSubarraySum(int[] nums, int k) {
        long sum = 0;           // To store the maximum sum of the subarray with k unique elements
        long currentSum = 0;    // Running sum of the current subarray
        HashMap<Integer, Integer> map = new HashMap<>();  // To keep track of the frequency of elements in the window
        
        for (int i = 0; i < nums.length; i++) {
            // Add the current element to the map and currentSum
            currentSum += nums[i];
            map.put(nums[i], map.getOrDefault(nums[i], 0) + 1);
            
            // If the window size exceeds k, remove the leftmost element
            if (i >= k) {
                int leftElement = nums[i - k];
                currentSum -= leftElement;
                map.put(leftElement, map.get(leftElement) - 1);
                
                // If the count of an element becomes zero, remove it from the map
                if (map.get(leftElement) == 0) {
                    map.remove(leftElement);
                }
            }
            
            // If the window size is exactly k and all elements are unique, check the sum
            if (i >= k - 1 && map.size() == k) {
                sum = Math.max(sum, currentSum);
            }
        }
        
        return sum;
    }
}
