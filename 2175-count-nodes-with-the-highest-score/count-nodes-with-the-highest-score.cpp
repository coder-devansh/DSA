class Solution {
public:
int find_size(vector<vector<int>>&adj,int node,vector<int>&count){
    int size=1;
    for(auto it:adj[node]){
        size+=find_size(adj,it,count);
    }
    count[node]=size;
    return size;

}
    int countHighestScoreNodes(vector<int>& parents) {
        vector<int>count(parents.size()+1,0);
        
        vector<vector<int>>adj(parents.size()+1);
        
        for(int i=1;i<parents.size();i++){
            adj[parents[i]].push_back(i);
            
        }
            find_size(adj,0,count);
        long long max_score=0;
        int ans=1;
        for(int i=0;i<parents.size();i++)
        {
          long long score=1;
           int remaining=parents.size()-count[i];
           auto &it=adj[i];
           for(auto ele:it){
            score*=count[ele];
           }
           if(remaining>0){
            score*=remaining;
           }
           if(max_score==score){
            ans++;

           }else if(max_score<score){
            max_score=score;
            ans=1;
           }

        }
        return ans;


        
    }
};