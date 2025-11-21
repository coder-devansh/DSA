class Solution {
    public int countPalindromicSubsequence(String s) {
        int n=s.length();
        int first[]=new int[26];
        int last[]=new int[26];
        
        int freq[]=new int[n+1];
        Arrays.fill(first,-1);
        Arrays.fill(last,-1);
        for(int i=0;i<n;i++){
            char ch=s.charAt(i);
            if(first[ch-'a']==-1){
                first[ch-'a']=i;
            }
            last[ch-'a']=i;
        }
        int count=0;
        for(char ch='a';ch<='z';ch++){
            if(first[ch-'a']!=-1 && last[ch-'a']!=-1){
                HashSet<Character>st=new HashSet<>();
                for(int i=first[ch-'a']+1;i<last[ch-'a'];i++){
                    st.add(s.charAt(i));
                }
                count+=st.size();

            }
        }
        return count;
    

        
    }
}