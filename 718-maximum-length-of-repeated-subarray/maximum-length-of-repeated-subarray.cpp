// 1,2,3,2,1
// 3,2,1,4,7

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int max_len=0;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    
                   int row=i;
                   int col=j;
while(row<nums1.size() && col<nums2.size() && nums1[row]==nums2[col]){
    row++;
    col++;

}
max_len=max(max_len,(row-i));
                }
            }
        }
        return max_len;
        
        
    }
};