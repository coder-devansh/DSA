class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        Stack<Integer>st=new Stack<>();
        int i=0;
        int j=0;
        while(i<pushed.length){
            while(!st.isEmpty() && st.peek()==popped[j] && j<popped.length){
                st.pop();
                j++;
            }
            st.push(pushed[i]);
            i++;
        }
            while(!st.empty() && j<popped.length &&  st.peek()==popped[j])      {
                st.pop();
                j++;
            }
        if(j<popped.length)return false;
        return true;

        
    }
}