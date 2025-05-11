class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
     int zeros_nums1=0;
     int zeros_nums2=0;
     long long  sum_nums1=0;
    long long  sum_nums2=0;
     for(int i=0;i<nums1.size();i++){
        if(nums1[i]==0){
            zeros_nums1++;
            sum_nums1++;
           
        }
        sum_nums1+=nums1[i];
     }
     for(int i=0;i<nums2.size();i++){
        if(nums2[i]==0){
            zeros_nums2++;
            sum_nums2++;
            
        }
        sum_nums2+=nums2[i];

     }
     int ans=min(sum_nums1+zeros_nums1,sum_nums2+zeros_nums2);
     if(zeros_nums1==0){
        if(sum_nums2>sum_nums1) return -1;
        
     }
     if(zeros_nums2==0){
        if(sum_nums1>sum_nums2) return -1;
     }

     if((zeros_nums1==0 && sum_nums1<sum_nums2) || (zeros_nums2==0 && sum_nums2<sum_nums1)){
        return -1;
     }
     return max(sum_nums1,sum_nums2);



       
          

        

        
    }
};