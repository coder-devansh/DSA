class Solution {
public:
int count1=0;
void  merge(int low,int mid,int high,vector<int>&nums){
    int j = mid + 1;

    // Count reverse pairs
    for (int i = low; i <= mid; i++) {
        while (j <= high && nums[i] > 2LL * nums[j]) {
            j++;
        }
        count1 += (j - (mid + 1));
    }

    // Merge two sorted halves
    int i = low;
    j = mid + 1;
    vector<int>arr(high-low+1);
    int k=0;
    int count=0;
    while(i<=mid && j<=high){
       
        if(nums[i]<=nums[j]){
            arr[k++]=nums[i];
            i++;
        }else{
            arr[k++]=nums[j];
            j++;

        }
        

    }
    while(i<=mid){
        arr[k++]=nums[i++];
    }
    while(j<=high){
        arr[k++]=nums[j++];
    }
    for(int i=low;i<=high;i++){
        nums[i]=arr[i-low];

    }
    



}
void mergeSort(int low,int high,vector<int>&nums){
    if(low>=high){
    return ;
}
int mid=(low+high)/2;
mergeSort(low,mid,nums);
mergeSort(mid+1,high,nums);
merge(low,mid,high,nums);
}
    int reversePairs(vector<int>& nums) {

    
        mergeSort(0,nums.size()-1,nums);
        for(auto it:nums)cout<<it<<endl;
        return count1;
        
    }
};