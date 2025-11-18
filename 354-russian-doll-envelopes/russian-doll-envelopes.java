class Solution {
    
    static public int binary_search(int target,ArrayList<Integer>lis){
        int low=0;
        int high=lis.size()-1;
        int ans=lis.size();
        while(low<=high){
            int mid=(low+high)/2;
            if(lis.get(mid)>=target){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }

        }
        return ans;
    }
    public int maxEnvelopes(int[][] envelopes) {
        int n=envelopes.length;
        Arrays.sort(envelopes,(a,b)->{
            if(a[0]==b[0]){
                return b[1]-a[1];
            }
            return a[0]-b[0];
        });
        ArrayList<Integer>lis=new ArrayList<>();
        for(int i=0;i<envelopes.length;i++){
            int idx=binary_search(envelopes[i][1],lis);
            if(idx==lis.size()){
                lis.add(envelopes[i][1]);
            }else
            {
                lis.set(idx,envelopes[i][1]);
            }
        }
        return lis.size();
        
    }
}