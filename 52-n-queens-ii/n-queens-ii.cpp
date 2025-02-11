class Solution {
public:
vector<vector<int>>vec;
vector<int>generate(vector<vector<int>>&board){
    vector<int>arr;
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board.size();j++){
            if(board[i][j]==1){
                arr.push_back(j+1);
            }
        }
    }
    return arr;
}
bool isSafe(int row,int col,vector<vector<int>>board){
    
    int n=board.size();
    for(int i=0;i<board.size();i++){
        if(i!=row && board[i][col]==1){
            return false;
        }
    }
    for(int j=0;j<board[0].size();j++){
        if(j!=col && board[row][j]==1) return false;
    }
    int i=row;
    int j=col;
    while(i>=0 && j>=0){
        if(board[i][j]==1 && i!=row && j!=col)
        {
            return false;
        }
        i--;
        j--;
    }
    i=row;
    j=col;
    while(i>=0 && j<board[0].size()){
        if(board[i][j]==1 && i!=row && j!=col){
            return false;
        }
        i--;
        j++;
    }
    i=row;
    j=col;
    while(i<board.size() && j>=0){
        if(board[i][j]==1 && i!=row && j!=col){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
void solve(int col,vector<vector<int>>&board){
    if(col==board.size()){
        
        vec.push_back(generate(board));

        return ;
    }
    for(int i=0;i<board.size();i++){
        if(isSafe(i,col,board)){
            board[i][col]=1;
            solve(col+1,board);
            board[i][col]=0;
        }
    }
}
    int totalNQueens(int n) {
        vector<vector<int>>board(n,vector<int>(n,0));
        solve(0,board);
        return vec.size();
    }
};