class Solution {
    public int scoreOfParentheses(String s) {
        int count=0;
        Stack<String>st=new Stack<>();
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='('){
                st.push(s.charAt(i)+"");
            }
            else{
                if(st.peek().charAt(0)!='('){
                    count=Integer.parseInt(st.pop())*2;
                }else{
                    count++;
                }
                st.pop();
                if(!st.isEmpty() && st.peek().charAt(0)!='('){
                    count+=Integer.parseInt(st.pop());
                }
                st.push(count+"");
                count=0;

            }
        }
        return Integer.parseInt(st.peek());
       
        
    }
}