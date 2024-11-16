class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>matrix(n,vector<int>(n,1e9+7));
      for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				
				if (i == j) matrix[i][j] = 0;
			}
		}
        for(const auto&it:edges){
            int start=it[0];
            int end=it[1];
            int weight=it[2];
            matrix[start][end]=weight;
            matrix[end][start]=weight;
        }

		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
                    if(i==j){
                        continue;
                    }
					matrix[i][j] = min(matrix[i][j],
					                   matrix[i][k] + matrix[k][j]);
				}
			}
		}
        int ans=0;
        int mini=INT_MAX;




		for (int i = 0; i < n; i++) {
            int count=0;
			for (int j = 0; j < n; j++) {
                if(i==j) continue;
				if(matrix[i][j]<=distanceThreshold)
                {
                    count++;
                }
			}
            cout<<count<<endl;
            if(mini>=count){
                ans=i;
                mini=count;
            }
		}
        return ans;
	
        
    }
};