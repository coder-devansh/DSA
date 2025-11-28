class Solution {
    public int partitionString(String s) {
        HashMap<Character,Integer>mp=new HashMap<>();
        int right=0;
        int left=0;
        int count=0;
        while(right<s.length())
        {
            char ch=s.charAt(right);
            mp.put(ch,mp.getOrDefault(ch,0)+1);
            if(mp.getOrDefault(ch,0)>=2){
                count++;
            while(left<right){
                char chr=s.charAt(left);
                mp.put(chr,mp.getOrDefault(chr,0)-1);
                left++;
            }
            
            }
            right++;
        }
        return count+1;
        
    }
}