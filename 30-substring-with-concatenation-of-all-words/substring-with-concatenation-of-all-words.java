class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
      ArrayList<Integer>arr=new ArrayList<>();
      if(s.length()==0 || words.length==0){
        return arr;
      }
      HashMap<String,Integer>wordCount=new HashMap<>();

      int wordlength = words[0].length();
      
      for(int i=0;i<words.length;i++){
        wordCount.put(words[i],wordCount.getOrDefault(words[i],0)+1);

      }
      for(int i=0;i<wordlength;i++){
        int l=i;
        int r=i;
         HashMap<String,Integer>found=new HashMap<>();
         int count=0;

        while(r+wordlength<=s.length()){
           
            String ans=s.substring(r,r+wordlength);
            r+=wordlength;
            if(wordCount.containsKey(ans))
            {
                found.put(ans,found.getOrDefault(ans,0)+1);

                count++;
                while(found.get(ans)>wordCount.get(ans) && l+wordlength<=s.length())
                {
                  String leftword=s.substring(l,l+wordlength);
                  found.put(leftword,found.get(leftword)-1);
                  l+=wordlength;
                  count--;
                }
                if(count==words.length){
                    arr.add(l);
                }
            }
            else{
                found.clear();
                count=0;
                l=r;
            }
        }

        }
        return arr;
      
        

        
    }
}