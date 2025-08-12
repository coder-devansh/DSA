class DisjointSet{
    vector<int>parent,size;
    public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            size[i]=1;
            parent[i]=i;
        }
    }
    int findUpar(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=findUpar(parent[node]);
    }

    void unionBySize(int u,int v){
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);
        if(ulp_u==ulp_v)return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }

    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int no_of_stones=stones.size();
        int maxi=0;
        int max_col=0;
        for(auto it:stones){
            maxi=max(maxi,it[0]);
            max_col=max(max_col,it[1]);
        }
        int n=maxi+max_col+1;
        DisjointSet ds(n);
        unordered_map<int,int>mp;
        for(auto it:stones){
            ds.unionBySize(it[0],it[1]+maxi+1);
            mp[it[0]]=1;
            mp[it[1]+maxi+1]=1;

        }
        int cnt=0;
        for(auto it:mp){
            if(ds.findUpar(it.first)==it.first){
                cnt++;
            }
        }
        // return cnt;
        return no_of_stones-cnt;
    
       

        
        
    }
};