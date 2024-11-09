class Solution {
    public int minAddToMakeValid(String s) {
        Stack<String>st=new Stack<>();
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='(')
            {
                st.push("(");
            }
            else if(s.charAt(i)==')')
            {
                if(!st.empty() && st.peek()=="(")
                {
                    st.pop();

                }
                else{
                    st.push(")");
                }
            }
        }
        return st.size();
        
    }
}