class Solution {
public:
int find(vector<vector<int>>&mat,int mid){
    int index=-1;
    int max_value=INT_MIN;
    for(int i=0;i<mat.size();i++){
        if(mat[i][mid]>max_value){
            index=i;
            max_value=mat[i][mid];
        }
    }
    return index;

}
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low=0;
        int high=mat[0].size()-1;
        while(low<=high){
            int mid=(low+(high-low)/2);
            int maxIndex=find(mat,mid);
            int left=(mid-1>=0)?mat[maxIndex][mid-1]:-1;
            int right=(mid+1<mat[0].size())?mat[maxIndex][mid+1]:-1;
            if(mat[maxIndex][mid]>left && mat[maxIndex][mid]>right){
                return {maxIndex,mid};
            }
            if(mat[maxIndex][mid]<left){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return {-1,-1};
        
        
    }
};