import java.util.Arrays;

class Solution {

    // This function checks if the current speed 'mid' can help finish the piles within 'h' hours.
    public static boolean canFinish(int mid, int[] piles, int h) {
        int hours = 0;
        
        // For each pile, calculate how many hours it will take to eat that pile with speed 'mid'
        for (int pile : piles) {
            hours += (pile + mid - 1) / mid;  // Equivalent to Math.ceil(pile / mid)
        }
        
        // Check if we can finish within 'h' hours
        return hours <= h;
    }

    public int minEatingSpeed(int[] piles, int h) {
        Arrays.sort(piles);  // Sort the piles to make binary search more efficient
        int low = 1;  // The minimum speed (eating at least 1 banana per hour)
        int high = piles[piles.length - 1];  // The maximum speed (eating the largest pile in 1 hour)
        
        // Binary search for the minimum speed
        while (low < high) {
            int mid = (low + high) / 2;
            if (canFinish(mid, piles, h)) {
                high = mid;  // Try a smaller speed if it's possible to finish within 'h' hours
            } else {
                low = mid + 1;  // Otherwise, increase the speed
            }
        }
        
        return low;  // The minimum valid speed will be stored in 'low' at the end
    }
}
