class Solution {
    public String minWindow(String s, String t) {
        int targetfreq[]=new int[256];
        int foundfreq[]=new int[256];
        StringBuilder sb=new StringBuilder();
        for(int i=0;i<t.length();i++){
            targetfreq[t.charAt(i)]++;

        }
        int l=0;
        int r=0;
        int found=0;
        int required=t.length();
        String ans="";
        if(t.length()>s.length()){
            return ans;
        }
        int minlen=Integer.MAX_VALUE;
        while(r<s.length())
        {
            char currentChar=s.charAt(r);
            sb.append(currentChar);
            foundfreq[currentChar]++;
            if(targetfreq[currentChar]>=foundfreq[currentChar])
            {
                found++;
            }
           
            while(l<=r && found==required){
                char leftChar=s.charAt(l);
            if(r-l+1<minlen){
                minlen=r-l+1;
                ans=sb.toString();
            }

                  foundfreq[leftChar]--;
                if(foundfreq[leftChar]<targetfreq[leftChar])
                {
                    found--;
                }
                sb.deleteCharAt(0);
              
                l++;
            }
            r++;


        }
        return ans;
        
    }
}