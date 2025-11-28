class Solution {
   public int count=0;
    public  long dfs(int i,ArrayList<Integer>[]adj,int parent,int k,int []values,HashMap<String, Long> dp){
        String key1=i+","+parent;
        if(dp.getOrDefault(key1, (long)-1)!=-1)return dp.get(key1);
        long sum=0;
        for(int ele:adj[i]){
            if(ele!=parent){
               sum+=dfs(ele,adj,i,k,values,dp);
               sum=sum%k;

            }
        }
        sum+=values[i];
        sum=sum%k;
        if(sum==0){
            count++;
        }
        String key=i+","+parent;
       dp.put(key,sum);
       return sum;

    }
    public int maxKDivisibleComponents(int n, int[][] edges, int[] values, int k) {
        ArrayList<Integer>[]adj=new ArrayList[n];
        for(int i=0;i<n;i++){
            adj[i]=new ArrayList<>();
        }
        HashMap<String, Long> dp = new HashMap<>();
        for(int i=0;i<edges.length;i++){
            adj[edges[i][0]].add(edges[i][1]);
            adj[edges[i][1]].add(edges[i][0]);
        }
        int vis[]=new int[n];
        dfs(0,adj,-1,k,values,dp);
        return count;

    }
}