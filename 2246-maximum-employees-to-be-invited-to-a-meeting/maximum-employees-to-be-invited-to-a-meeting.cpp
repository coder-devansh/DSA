class Solution {
public:
int bfs(int start,unordered_map<int,vector<int>>adj,vector<int>&vis){
    queue<pair<int,int>>q;
    q.push({start,0});
    int maxi=0;
    while(!q.empty()){
        auto [currNode,dist]=q.front();
        q.pop();
        for(auto &ngbr:adj[currNode]){
            if(!vis[ngbr]){
                vis[ngbr]=1;
                q.push({ngbr,dist+1});
                maxi=max(maxi,dist+1);
            }
        }
    }
    return maxi;

}
    int maximumInvitations(vector<int>& favourite) {
        int n=favourite.size();
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<favourite.size();i++){
            int v=favourite[i];
            adj[v].push_back(i);
        }
        int longestcyclecount=0;
        int happyEmpCoupleCount=0;// This is the cuple where cycle of length 2 exist
        vector<int>vis(favourite.size(),0);

        for(int i=0;i<favourite.size();i++){
            if(!vis[i]){
                unordered_map<int,int>mp;
                int currNode=i;
                int currNodeCount=0;
                while(!vis[currNode])
                {
                    vis[currNode]=1;
                    mp[currNode]=currNodeCount;
                    int nextNode=favourite[currNode];
                    currNodeCount+=1;
                    if(mp.count(nextNode)){
                        int cycleLength=currNodeCount-mp[nextNode];
                        longestcyclecount=max(longestcyclecount,cycleLength);
                        if(cycleLength==2){
                            vector<int>vis(favourite.size(),0);
                            vis[currNode]=1;
                            vis[nextNode]=1;
                            happyEmpCoupleCount+=2+bfs(currNode,adj,vis)+bfs(nextNode,adj,vis);
                        }
                        break;
                    }
                    currNode=nextNode;

                }
            }
            
        }
        return max(happyEmpCoupleCount,longestcyclecount);
        
    }
};