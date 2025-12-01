class Solution {
    public int maxScore(int[] cardPoints, int k) {
        int n=cardPoints.length;
        int size=n-k;
        int left=0;
        int right=0;
        int totalSum=0;
        for(int ele:cardPoints)totalSum+=ele;
        int sum=0;
        int maxi=Integer.MIN_VALUE;
        while(right<n){
            sum+=cardPoints[right];
            while((right-left+1)>(size)){
                sum-=cardPoints[left];
                left++;
            }
            if((right-left+1)==size)
            {
                maxi=Math.max(maxi,totalSum-sum);
            }
            right++;
        }
        return maxi;
        
    }
}