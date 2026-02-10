class LockingTree {
public:
vector<vector<int>>adj;
vector<vector<int>>ancestors;
map<int,int>mp;
vector<int>list;
void dfs(int node,vector<vector<int>>&adj,bool&found){
    for(auto it:adj[node])
    {
        if(mp.find(it)!=mp.end()){
            found=true;
            mp.erase(it);
        }
        dfs(it,adj,found);

    }
}
bool dfs1(int node,vector<vector<int>>&adj){
    for(auto it:adj[node]){
        if(mp.find(it)!=mp.end())return false;
        if(!dfs1(it,adj))return false;
    }
    return true;
}

    LockingTree(vector<int>& parent) {
        list=parent;
        adj.resize(parent.size()+1);
         ancestors.resize(parent.size()+1);
     for(int i=0;i<parent.size();i++){
        
        if(parent[i]!=-1){
            adj[parent[i]].push_back(i);
            ancestors[i].push_back(parent[i]);
        }
     }
        
    }
    
    bool lock(int num, int user) {
        if(mp.find(num)==mp.end()){
            mp[num]=user;
            return true;
        }
        return false;

        
    }
    
    bool unlock(int num, int user) {
        if(mp.find(num)!=mp.end()  && mp[num]==user ){
            mp.erase(num);
            return true;

        }
        return false;
        
    }
    
    bool upgrade(int num, int user) {
        if(mp.find(num)==mp.end()){
           
        int cur = list[num];
while (cur != -1) {
    if (mp.find(cur) != mp.end()) return false;
    cur = list[cur];
}
bool found=false;
            dfs(num,adj,found);
           
           if(found){
            mp[num]=user;
            return true;
           }

        }
        return false;
        
        
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */