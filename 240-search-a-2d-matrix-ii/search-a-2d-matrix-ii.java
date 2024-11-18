class Solution {
    public boolean searchMatrix(int[][] mat, int x) {
         int row=mat.length-1;
        int col=0;
        while(row>=0 && col<mat[0].length){
            if(mat[row][col]==x){
                return true;
            }
            else if(mat[row][col]<x){
                col++;
                
                
            }
            else{
                row--;
            }
            
        
            
        }
        return false;
    }
        
    
}