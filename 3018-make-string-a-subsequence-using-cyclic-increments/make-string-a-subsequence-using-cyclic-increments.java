class Solution {
    public boolean canMakeSubsequence(String str1, String str2) {
        int l=0;
        int r=0;
        if(str2.length() > str1.length()){
            return false;
        }
        
        while(l<str1.length() && r<str2.length()){
             char c1 = str1.charAt(l);
            char c2 = str2.charAt(r);
            
          if (c1 == c2 || (c1=='z' && c2=='a') || c1 == c2 - 1) {
               
                l++;
                r++;
            } else {
                
                l++;
            }
          

        }
       return r==str2.length();
        
    }
}