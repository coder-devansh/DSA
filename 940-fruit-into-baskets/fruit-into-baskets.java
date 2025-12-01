class Solution {
    public int totalFruit(int[] fruits) {
        HashMap<Integer,Integer>mp=new HashMap<>();
        int left=0;
        int right=0;
        int maxi=Integer.MIN_VALUE;
        while(right<fruits.length){
            mp.put(fruits[right],mp.getOrDefault(fruits[right],0)+1);
            while(mp.size()>2){
                mp.put(fruits[left],mp.getOrDefault(fruits[left],0)-1);
                if(mp.get(fruits[left])==0)mp.remove(fruits[left]);
                left++;
            }
            maxi=Math.max(maxi,right-left+1);
            right++;

        }
        return maxi;

        
    }
}