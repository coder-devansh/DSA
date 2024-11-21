class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>matrix(m,vector<int>(n,-1));
        queue<pair<int,int>>q;
        for(const auto& it:guards){
            matrix[it[0]][it[1]]=0;
            q.push({it[0],it[1]});
        }
        for(const auto& it:walls){
            matrix[it[0]][it[1]]=1;
        }
        vector<vector<int>>vis(m,vector<int>(n,0));
        int rows[]={-1,0,1,0};
        int cols[]={0,1,0,-1};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int row=it.first;
            int col=it.second;
            for(int i=row+1;i<m;i++){
                if(matrix[i][col]==1 || matrix[i][col]==0){
                    break;
                }
                matrix[i][col]=2;
            }
            for(int i=row-1;i>=0;i--){
                if(matrix[i][col]==1 || matrix[i][col]==0)
                {
                    break;
                }
                matrix[i][col]=2;
            }
            for(int i=col-1;i>=0;i--){
                if(matrix[row][i]==1 || matrix[row][i]==0 )
                {
                    break;
                }
                matrix[row][i]=2;
            }
            for(int i=col+1;i<n;i++){
                if(matrix[row][i]==1 || matrix[row][i]==0)
                {
                    break;
                }
                matrix[row][i]=2;
            }

        }
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(matrix[i][j]==-1)
                {
                    count++;
                }
            }
           
        }
        cout<<endl;
        return count;

        
    }
};