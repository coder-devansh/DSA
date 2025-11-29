class Solution {
    public int maximumSum(int[] arr) {
        int n=arr.length;
        if(n==1)return arr[0];
        int forward[]=new int[n];
        int backward[]=new int[n];
        forward[0]=arr[0];
        for(int i=1;i<n;i++){
            forward[i]=Math.max(arr[i],forward[i-1]+arr[i]);
        }
        backward[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            backward[i]=Math.max(arr[i],backward[i+1]+arr[i]);
        }
        long  max_sum=arr[0];
        for(int i=1;i<n-1;i++){
            max_sum=Math.max(max_sum,forward[i-1]+backward[i+1]);

        }
        for(int i=0;i<n;i++){
            max_sum=Math.max(max_sum,forward[i]);
        }
        max_sum=Math.max(max_sum,forward[n-2]);
        max_sum=Math.max(max_sum,backward[1]);
        return Math.max(forward[n-1],(int)max_sum);
    }
}