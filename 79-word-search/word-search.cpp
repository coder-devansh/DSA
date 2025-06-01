class Solution {
public:

bool find_combo(int i,int j,vector<vector<char>>&board,string word,int k){
  if(k==word.size()) return true;
  if(i<0 || i>=board.size() || j>=board[0].size() || board[i][j]=='.') return false;
  if(board[i][j]!=word[k])return false;

  int d_row[4]={-1,0,1,0};
  int d_col[4]={0,-1,0,1};
  char temp=board[i][j];
  board[i][j]='.';
  for(int t=0;t<4;t++){
    if(find_combo(i+d_row[t],j+d_col[t],board,word,k+1)){
        return true;
    }

  }
  board[i][j]=temp;
  return false;
}
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    if(find_combo(i,j,board,word,0)){
                        return true;
                    }
                }
            }
        }
        return false;
        
    }
};