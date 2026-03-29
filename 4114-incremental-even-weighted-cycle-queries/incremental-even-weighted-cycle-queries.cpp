class DSU{
    public:
    vector<int>parent;
    vector<int>parity;
    
    DSU(int n){
        parent.resize(n+1);
        parity.resize(n+1,0);
        for(int i=0;i<=n;i++)parent[i]=i;
    }
    void unionBy(int u,int v,int w){
        int parent_node=u;
        int child_node=v;
        parent[child_node]=parent_node;
        parity[parent_node]=(parity[parent_node]+parity[child_node]+w)%2;
        
    }
    pair<int,int>find(int node){
        if(parent[node]==node){
            return{node,0};
        }
        auto [root,par]=find(parent[node]);
        parity[node] ^=par;
        parent[node]=root;
        return {root,parity[node]};

    }
};
class Solution {
public:
    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {
        DSU*dsu=new DSU(n);
        int count=0;
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            auto [node1,parity1]=dsu->find(u);
            auto [node2,parity2]=dsu->find(v);
            if(node1!=node2){
                dsu->parent[node1] = node2;
                dsu->parity[node1] = parity1 ^ parity2 ^ w;

                 count++;
            }else{
                int val=(parity1+parity2+w)%2;
                if(val==0)
                { count++;
                }else{

                   
                }
            }

        }
        return count;
        
    }
};