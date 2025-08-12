class DisjointSet{
    vector<int>parent,size;
    public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }

    int findUpar(int node){
        if(parent[node]==node){
            return node;
        }

        return parent[node]=findUpar(parent[node]);
    }

    void UnionBySize(int u,int v){
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<bool>isConnected(n,false);
        DisjointSet ds(n);
        int wire=0;
        for(auto it:connections){
            int node=it[0];
            int adjnode=it[1];
            if(ds.findUpar(node)==ds.findUpar(adjnode)){
                wire++;
            }else{
                isConnected[node]=true;
                isConnected[adjnode]=true;
                ds.UnionBySize(node,adjnode);
            }

        }
       
        map<int,int>mp;
        for(int i=0;i<n;i++){
            int find_par=ds.findUpar(i);
            if(mp.find(find_par)==mp.end()){
                mp[find_par]++;
            }
        }
        if(wire>=mp.size()-1)return mp.size()-1;
        return -1;
        
        
    }
};