class DSU{
    vector<int>parent;
    vector<int>size;
    public:
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }

    }
    void unionBy(int ulp_u,int ulp_v){
        if(ulp_u==ulp_v)return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
        }else if(size[ulp_u]>size[ulp_v]){
            parent[ulp_v]=ulp_u;
        }else{
            size[ulp_v]++;
            parent[ulp_u]=ulp_v;
        }
    }
    int find(int node){
        if(parent[node]==node)return node;
        return parent[node]=find(parent[node]);
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int count=0;
        DSU*dsu=new DSU(n);
        for(auto it:connections){
            int u=dsu->find(it[0]);
            int v=dsu->find(it[1]);
            if(u==v){
                count++;
                continue;
            }
            dsu->unionBy(u,v);
            
        }
        int temp=-1;
        for(int i=0;i<n;i++){
            if(dsu->find(i)==i)temp++;
        }
        return temp<=count?temp:-1;
        
    }
};