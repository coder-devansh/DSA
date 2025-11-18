class Solution {
public:
int find_score(int i,vector<pair<int,int>>&vec,int prev,int curr,vector<vector<int>>&dp){
    if(i==vec.size()){
        return 0;
    }
    if(dp[i][prev+1]!=-1)return dp[i][prev+1];
    int pick=0;
    if(prev==-1 || (vec[prev].first<=vec[i].first)){
       pick=vec[i].first+find_score(i+1,vec,i,curr,dp);
    }
    int not_pick=find_score(i+1,vec,prev,curr,dp);
    return dp[i][prev+1]=max(pick,not_pick);
}
static bool compare(const pair<int,int>&a,const pair<int,int>&b){
    if(a.second==b.second){
        return a.first<b.first;
    }
    return a.second<b.second;
}
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int max_val=*max_element(scores.begin(),scores.end());
        vector<pair<int,int>>vec;
        for(int i=0;i<scores.size();i++){
            vec.push_back({scores[i],ages[i]});
        }
        sort(vec.begin(),vec.end(),compare);
        vector<pair<int,int>>temp;

        vector<vector<int>>dp(scores.size()+1,vector<int>(scores.size()+1,-1));
        return find_score(0,vec,-1,-1,dp);
        
    }
};