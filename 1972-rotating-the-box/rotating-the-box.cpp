class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m=box[0].size();
        int n=box.size();
        
        int j=0;
    vector<vector<char>>ans(m,vector<char>(n,'.'));
    for( int i=0;i<n;i++){
        int hash=0;
        j=0;
        for( ;j<m;j++){
            if(box[i][j]=='#')
            {
                hash++;
            }
            else if(box[i][j]=='*')
            {
                int row=j;
                int col=n-i-1;
                ans[row][col]='*';
                row--;
                while(hash>0){
                    ans[row][col]='#';
                    hash--;
                    row--;
                }
            }

        }
        int row=j-1;
    int col=n-i-1;
    while(hash>0){
        ans[row][col]='#';
        hash--;
        row--;
    }
    }
    
    return ans;
    }
};