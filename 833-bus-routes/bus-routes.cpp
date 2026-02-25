class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        map<int,set<int>>mp;
        for(int i=0;i<routes.size();i++){
            for(int j=0;j<routes[i].size();j++){
                mp[routes[i][j]].insert(i);
            }
        }
        vector<int>vis(routes.size(),0);
        queue<pair<pair<int,int>,int>>q;
        q.push({{source,0},-1});
        int mini=INT_MAX;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int node=it.first.first;
            int steps=it.first.second;
            int index=it.second;
            
            if(node==target){
                mini=min(mini,steps);
                continue;
            }
            if(index==-1)
            {
                for(auto it:mp[node]){
                    if(!vis[it]){
                        vis[it]=1;
                        q.push({{node,steps+1},it});
                    }
                }
            }else{
                for(int i=0;i<routes[index].size();i++){
                    if(routes[index][i]==target){
                        mini=min(mini,steps);
                        break;
                    }
                    for(auto it:mp[routes[index][i]]){
                        if(!vis[it]){
                        vis[it]=1;
                        q.push({{routes[index][i],steps+1},it});
                    }
                    }
                }
            }
        }
        if(mini==INT_MAX)return -1;
            return mini;
    }
};