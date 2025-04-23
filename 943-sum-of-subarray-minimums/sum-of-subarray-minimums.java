class Solution {
    public static int sumSubarrayMins(int[] arr) {
        int []left=new int[arr.length];
        int []right=new int[arr.length];
        Stack<Integer>st=new Stack<>();
        int mod=1000000007;
        for(int i=0;i<arr.length;i++){
            while(!st.isEmpty() && arr[st.peek()]>arr[i]){
                st.pop();
            }
            if(st.isEmpty()){
                left[i]=-1;
            }else{
                left[i]=st.peek();
            }
            st.push(i);
        }
        st.clear();
        for(int i=arr.length-1;i>=0;i--){
            while(!st.isEmpty() && arr[st.peek()]>=arr[i]){
                st.pop();
            }
            if(st.isEmpty()){
                right[i]=arr.length;
            }else{
                right[i]=st.peek();
            }
            st.push(i);
            
        }
        long   cnt=0;
        for(int i=0;i<arr.length;i++){
           long leftCount = i - left[i];
    long rightCount = right[i] - i;
    long product = (leftCount * rightCount) % mod;
    product = (product * arr[i]) % mod;
    cnt = (cnt + product) % mod;
            
        }
        return (int)cnt;
        
        
        // code here
    }
}