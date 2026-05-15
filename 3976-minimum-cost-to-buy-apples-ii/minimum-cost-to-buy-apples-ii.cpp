#define ll long long
struct obj{
    int v;
    int cost;
    int multiplier;
};
class Solution {
public:

vector<vector<int>>w_apple;
vector<int>best;
int  find(int i,vector<vector<obj>>&adj,vector<int>&prices){
    queue<int>q;
    q.push(i);
    vector<long long>dist(prices.size()+1,(int)1e9);
    dist[i]=prices[i];
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        for(auto ele:adj[it]){
            int node=ele.v;
            int cost=ele.cost;
            int multiplier=ele.multiplier;
            if(dist[it]+(long long)(cost*1ll*multiplier)<dist[node]){
                dist[node]=dist[it]+(cost*multiplier);
                q.push(node);
            }

        }
        
    }
     queue<int>pq;
    pq.push(i);
    vector<long long>dist1(prices.size(),1e9);
    dist1[i]=0;
    while(!pq.empty()){
        auto it=pq.front();
        pq.pop();
        for(auto ele:adj[it]){
            int node=ele.v;
            int cost=ele.cost;
            int multiplier=ele.multiplier;
            if(dist1[it]+(cost)<dist1[node]){
                dist1[node]=dist1[it]+(cost);
                pq.push(node);
            }

        }
        
    }
    int ele=i;
    
    for(int i=0;i<prices.size();i++){
        
        
        best[i]=min({(int)(dist1[i]+dist[i]),best[i]});
        
    }
    return -1;


    
}
    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) {
        best.resize(n,(int)1e9);
        w_apple.resize(n+1,vector<int>(n+1,0));
        vector<vector<obj>> adj(n);

for(auto it : roads){

    adj[it[0]].push_back({it[1], it[2], it[3]});
    adj[it[1]].push_back({it[0], it[2], it[3]});
}
       
        for(int i=0;i<n;i++){
            find(i,adj,prices);
        }
        return best;



        

    }
};