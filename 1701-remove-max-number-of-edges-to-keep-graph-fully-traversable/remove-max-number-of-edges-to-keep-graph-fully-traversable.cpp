class DSU{
    vector<int>parent;
    vector<int>size;
    public:
    DSU(int n){
        parent.assign(n+1,-1);
        size.assign(n+1,0);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }


    }
    void unionBy(int ulp_u,int ulp_v){
        if(ulp_u==ulp_v)return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
        }else if(size[ulp_v]<size[ulp_u])
        {
            parent[ulp_v]=ulp_u;
        }else{
            parent[ulp_u]=ulp_v;
            size[ulp_v]++;
        }
    }
    int find(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=find(parent[node]);
    }
};
class Solution {
public:
int dfs(int n,vector<vector<int>>&edges,int alice){
    int count=0;
    DSU*dsu=new DSU(n);
    for(auto it:edges){
        if(it[0]==3){
            int ulp_u=dsu->find(it[1]);
            int ulp_v=dsu->find(it[2]);
            
            dsu->unionBy(ulp_u,ulp_v);
        }
    }
    if(alice){
        for(auto it:edges){
            if(it[0]==1){
            int ulp_u=dsu->find(it[1]);
            int ulp_v=dsu->find(it[2]);
            if(ulp_u==ulp_v){
                count++;
                continue;
            }
            dsu->unionBy(ulp_u,ulp_v);
        }

        }
    }else{
        for(auto it:edges){
        if(it[0]==2){
            int ulp_u=dsu->find(it[1]);
            int ulp_v=dsu->find(it[2]);
            if(ulp_u==ulp_v){
                count++;
                continue;
            }
            dsu->unionBy(ulp_u,ulp_v);
        }
        }
    }
    for(int i=1;i<=n;i++){
        if(dsu->find(1)!=dsu->find(i))return -1;
    }
    return count;
    
}

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int count=0;
    DSU*dsu=new DSU(n);
    for(auto it:edges){
        if(it[0]==3){
            int ulp_u=dsu->find(it[1]);
            int ulp_v=dsu->find(it[2]);
            if(ulp_u==ulp_v)count++;
            dsu->unionBy(ulp_u,ulp_v);
        }
    }
        int left1=dfs(n,edges,1);
        int left2=dfs(n,edges,0);

        if(left1==-1 || left2==-1)return -1;
        return count+left1+left2;

    }
};