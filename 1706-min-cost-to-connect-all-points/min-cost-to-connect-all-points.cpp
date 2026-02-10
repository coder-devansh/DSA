#define ll long long 
struct compare{
    bool operator()(const pair<int,ll>&a,const pair<int,ll>&b){
        return a.second>b.second;
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<pair<int,ll>>>adj(n);
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare>pq;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++){
ll cost=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                adj[i].push_back({j,cost});
                adj[j].push_back({i,cost});
            }
        }
        vector<int>vis(n,0);
        pq.push({0,0});
        ll sum=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int node=it.first;
            ll distance=it.second;
            if(vis[node])continue;
            sum+=distance;
            vis[node]=1;
            for(auto it:adj[node]){
                int v=it.first;
                ll cost=it.second;
                if(!vis[v]){
                    pq.push({v,cost});
                }
            }
        }return sum;

        
    }
};