class Solution {
public:
struct Info{
    int val;
    int val2;
    Info(int v1,int v2):val(v1),val2(v2){};
};
// bool operate(vector<vector<int>>board,int row,int col){
// return true;
// }
// void solve(int row,int col,vector<vector<int>>&board){
//     for(int i=0;i<board.size();i++){
//         if(i!=row){
//               board[i][col]++;
//         }
      
//     }
//     for(int j=0;j<board[0].size();j++){
//         if(j!=col){
//              board[row][j]++;
//         }
        
//     }
//     int i=row;
//     int j=col;
//     while(i>=0 && j>=0){
//            if(i==row && j==col){

//         }else{
//              board[i][j]++;
//         }
       
//         i--;
//         j--;
//     }
//     i=row;
//     j=col;
//     while(i<board.size() && j<board[0].size()){
//     if(i==row && j==col){

//         }else{
//              board[i][j]++;
//         }
       
//         i++;
//         j++;
//     }
//     i=row;
//     j=col;

//     while(i>=0 && j<board[0].size()){
//     if(i==row && j==col){

//         }else{
//              board[i][j]++;
//         }
//         i--;
//         j++;

//     }
//     i=row;
//     j=col;
    
//     while(i<board.size() && j>=0){
//          if(i==row && j==col){

//         }else{
//              board[i][j]++;
//         }
//         i++;
//         j--;
//     }
// }
        set<pair<int,int>>lamp;
        unordered_map<int,int>row_mp;
        unordered_map<int,int>col_mp;
        unordered_map<int,int>diagonal_mp1;
        unordered_map<int,int>diagonal_mp2;

int di[9]={-1,-1,0,1,1,1,0,-1,0};
int dc[9]={0,1,1,1,0,-1,-1,-1,0};
vector<int>ans;
vector<vector<int>>vis;
void operate(int row,int col,int n){
      if(row_mp[row]>0 || col_mp[col]>0 || diagonal_mp1[row-col]>0 || diagonal_mp2[row+col]>0){
        ans.push_back(1);
      }else{
        ans.push_back(0);
      }
      
       for(int k=0;k<9;k++){
        int new_row=row+di[k];
        int new_col=col+dc[k];
        if(new_row>=0 && new_row<n && new_col>=0 && new_col<n){
            if(lamp.count({new_row,new_col})){
                lamp.erase({new_row,new_col});
                row_mp[new_row]--;
                col_mp[new_col]--;
                diagonal_mp1[new_row-new_col]--;
                diagonal_mp2[new_row+new_col]--;
            }
            
        }
       }
       


    
   
   
}


    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
      
       for(auto it:lamps){
        if(lamp.count({it[0],it[1]})) continue;
        lamp.insert({it[0],it[1]});
        row_mp[it[0]]++;
        col_mp[it[1]]++;
        diagonal_mp1[it[0]-it[1]]++;
        diagonal_mp2[it[0]+it[1]]++;      
        // solve(it[0],it[1],board);
       }
    //    vis.resize(n,vector<int>(n,-1));
      for(auto & it:queries){
             
             operate(it[0],it[1],n);
      }
      return ans;
       


        
    }
};