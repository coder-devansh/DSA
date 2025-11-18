class Solution {
    static public int find_score(int i,int [][]arr,int [][]dp,int prev){
        if(i==arr.length){
            return 0;
        }
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        int pick=0;
        if(prev==-1 || arr[i][0]>=arr[prev][0]){
            pick=arr[i][0]+find_score(i+1,arr,dp,i);
        }
        int not_pick=find_score(i+1,arr,dp,prev);
        return dp[i][prev+1]=Math.max(pick,not_pick);
    }
    public int bestTeamScore(int[] scores, int[] ages) {
        int n=scores.length;
        int arr[][]=new int[n][2];
        for(int i=0;i<n;i++){
            arr[i][0]=scores[i];
            arr[i][1]=ages[i];
        }
        Arrays.sort(arr,(a,b)->{
            if(a[1]==b[1])return a[0]-b[0];
            return a[1]-b[1];
        });
        int dp[][]=new int[n+1][n+1];
        for(int i=0;i<=n;i++){
            Arrays.fill(dp[i],-1);
        }
        return find_score(0,arr,dp,-1);
        
        
    }
}