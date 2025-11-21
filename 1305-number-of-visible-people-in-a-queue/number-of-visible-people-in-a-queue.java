class Solution {
    public int[] canSeePersonsCount(int[] heights) {
        int n=heights.length;
        Stack<Integer>st=new Stack<>();
        int ans[]=new int[n];
        int k=heights.length-1;
        for(int i=heights.length-1;i>=0;i--){
            int count=0;
            while(!st.isEmpty() && heights[st.peek()]<heights[i]){
                st.pop();
                count++;
            }
            if(!st.isEmpty())count++;
            ans[k--]=count;
            st.push(i);
           

        }
        return ans;


        
    }
}