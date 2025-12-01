class Solution {
    public int characterReplacement(String s, int k) {
        int left=0;
        int right=0;
        int max_freq=0;
        int maxi=0;
        HashMap<Character,Integer>mp=new HashMap<>();
        while(right<s.length()){
            char ch=s.charAt(right);
            mp.put(ch,mp.getOrDefault(ch,0)+1);
            max_freq=Math.max(max_freq,mp.get(ch));
            if((right-left+1)-max_freq>k){
            while(left<right && (right-left+1)-max_freq>k){
                char chr=s.charAt(left);
                mp.put(chr,mp.getOrDefault(chr,0)-1);
                if(mp.get(chr)==0)mp.remove(chr);
                left++;

            }
            
        }
            maxi=Math.max(maxi,right-left+1);
            right++;


        } 
        return maxi;
        
    }
}