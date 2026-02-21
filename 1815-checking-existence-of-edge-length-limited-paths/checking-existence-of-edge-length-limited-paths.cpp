class Disjoint{
    vector<int>parent;
    vector<int>size;
    public:
    Disjoint(int n){
        parent.resize(n+1);
        size.assign(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    void unionBy(int ulp_u,int ulp_v){
        if(ulp_u==ulp_v)return;
        if(size[ulp_u]>size[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
        }else{
            size[ulp_u]++;
            parent[ulp_v]=ulp_u;
        }
    }
    int find(int node){
        if(parent[node]==node)return node;
        return parent[node]=find(parent[node]);
    }
};


class Solution {
public:
static bool compare(vector<int>&a,vector<int>&b){
    return a[2]<b[2];
}
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        
        vector<bool>ans(queries.size(),false);
        
        for(int i=0;i<queries.size();i++){
            queries[i].push_back(i);
        }
        sort(edgeList.begin(),edgeList.end(),compare);
        sort(queries.begin(),queries.end(),compare);
        Disjoint* dsu=new Disjoint(n);
        int j=0;
        for(auto it:queries)
        {
            int d=it[2];
            int u=it[0];
            int v=it[1];
            int index=it[3];
            if(dsu->find(u)==dsu->find(v)){
                ans[index]=true;
                continue;
            }
           
            for(;j<edgeList.size();){
            vector<int>edge=edgeList[j];
                if(edge[2]<d){
                    int ulp_u=dsu->find(edge[0]);
                    int ulp_v=dsu->find(edge[1]);
                    dsu->unionBy(ulp_u,ulp_v);
                    j++;
                   
                   
                    
                }else break;
            }
            if(dsu->find(u)==dsu->find(v)){
                ans[index]=(true);
            }else{
                ans[index]=(false);
            }
        


        }
        return ans;

        
    }
};