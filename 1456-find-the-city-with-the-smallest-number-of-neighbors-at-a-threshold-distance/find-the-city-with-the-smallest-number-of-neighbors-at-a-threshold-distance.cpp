#define ll long long
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
       vector<vector<ll>>vec(n,vector<ll>(n,(int)1e9));
       for(int i=0;i<n;i++){
        vec[i][i]=0;
       }
       for(auto it:edges){
        vec[it[0]][it[1]]=it[2];
        vec[it[1]][it[0]]=it[2];
       }
       for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(vec[i][j] == (int)1e9) {
	                    
	                    // Update the distance
	                   vec[i][j] = 
	                        vec[i][k] +vec[k][j];
	                }else{
                vec[i][j]=min(vec[i][j],vec[i][k]+vec[k][j]);
                    }
            }
        }
       }
       int max_count=INT_MAX;
       int ans=-1;
       for(int i=0;i<n;i++){
        int count=0;
        
        for(int j=0;j<n;j++)
        {
            if(i==j)continue;
            if(vec[i][j]<=distanceThreshold){
                count++;
            }
        }
       
        if(max_count>=count){
            ans=i;
            max_count=count;
        }
       }
       return ans;

        
    }
};