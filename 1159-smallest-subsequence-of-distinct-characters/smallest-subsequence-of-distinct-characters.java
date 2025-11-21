class Solution {
    public String smallestSubsequence(String s) {
        int []freq=new int[26];
        for(int i=0;i<s.length();i++){
            freq[s.charAt(i)-'a']++;
        }
        Stack<Character>st=new Stack<>();
        boolean[] inStack = new boolean[26]; // for 'a' to 'z'
        for(int i=0;i<s.length();i++){
            if(inStack[s.charAt(i)-'a']==true){
                freq[s.charAt(i)-'a']--;
                continue;
            }
            while(!st.isEmpty() && st.peek()>=s.charAt(i)){
                if(freq[st.peek()-'a']==1)break;
                char ch=st.peek();
                freq[st.peek()-'a']--;
                inStack[ch-'a']=false;
                st.pop();

            }
            if(inStack[s.charAt(i)-'a']==false){
                st.push(s.charAt(i));
                inStack[s.charAt(i)-'a']=true;

            }
            
        }
        StringBuilder ans=new StringBuilder();
        

        while(!st.isEmpty())
        {
            ans.append(st.peek());
            st.pop();
        }
        String result=ans.reverse().toString();
        return result;

    }
}