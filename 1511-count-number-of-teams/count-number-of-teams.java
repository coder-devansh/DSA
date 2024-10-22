class Solution {
    public int numTeams(int[] rating) {
        int n = rating.length;
        int count = 0;

        for (int i = 0; i < n; i++) {
            int leftLess = 0, rightGreater = 0;
            int leftGreater = 0, rightLess = 0;

            // Count elements less/greater than rating[i] on the left and right
            for (int j = 0; j < n; j++) {
                if (j < i) { // Elements to the left of i
                    if (rating[j] < rating[i]) {
                        leftLess++;
                    } else if (rating[j] > rating[i]) {
                        leftGreater++;
                    }
                } else if (j > i) { // Elements to the right of i
                    if (rating[j] < rating[i]) {
                        rightLess++;
                    } else if (rating[j] > rating[i]) {
                        rightGreater++;
                    }
                }
            }

            // Calculate number of valid teams with rating[i] as the middle element
            count += leftLess * rightGreater; // Increasing triplets
            count += leftGreater * rightLess; // Decreasing triplets
        }

        return count;
    }
}
