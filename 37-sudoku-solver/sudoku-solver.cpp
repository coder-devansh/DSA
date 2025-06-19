class Solution {
public:
bool isPossible(int row,int col,char val,vector<vector<char>>&board){
    int i=(row/3)*3;
    int j=(col/3)*3;
    for(int k=0;k<board[0].size();k++){
        if(board[row][k]==val)return false;
    }
    for(int k=0;k<board.size();k++){
        if(board[k][col]==val)return false;

    }
    for(int k=i;k<i+3;k++){
        for(int l=j;l<j+3;l++){
            if(board[k][l]==val){
                return false;
            }
        }
    }
    return true;

}
bool  solve(vector<vector<char>>&board){
     for(int i=0;i<board.size();i++){
        for(int j=0;j<board.size();j++){
            if(board[i][j]=='.'){
            for(char val='1';val<='9';val++){
            
        if(isPossible(i,j,val,board)){
            board[i][j]=(val);
            if(solve(board))return true;
            board[i][j]='.';
            
        }
        
        }
        return false;
    }
    
   }
}
return true;
    
  
   
}
    void solveSudoku(vector<vector<char>>& board) {
    
    solve(board);
    }
};