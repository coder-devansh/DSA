class Solution {
    public String removeStars(String s) {
        Stack<Character>st=new Stack<>();
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='*'){
                if(!st.isEmpty()){
                    st.pop();
                }
            }else{
                st.push(s.charAt(i));
            }
        }
        String ans="";
        while(!st.isEmpty()){
            ans+=st.pop();

        }
        String result="";
        for(int i=ans.length()-1;i>=0;i--){
            result+=ans.charAt(i);

        }
        return result;
    }
}