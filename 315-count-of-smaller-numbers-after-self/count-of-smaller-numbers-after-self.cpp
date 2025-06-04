class Solution {
public:
int count1=0;

void  merge(int low,int mid,int high,vector<pair<int,int>>&nums,vector<int>&ans){
    int j = mid + 1;

    // Count reverse pairs

    // Merge two sorted halves
    int i = low;
    j = mid + 1;
    vector<pair<int,int>>arr;
    int k=0;
    int rightCount=0;
    while(i<=mid && j<=high){
       
        if(nums[i].first>nums[j].first){
            arr.push_back(nums[j]);
            j++;
            rightCount++;
        }else{
            ans[nums[i].second]+=rightCount;
            arr.push_back(nums[i]);
            i++;

        }
        

    }
    while(i<=mid){
        ans[nums[i].second]+=rightCount;
        arr.push_back(nums[i++]);
    }
    while(j<=high){

        arr.push_back(nums[j++]);
    }
    for(int i=low;i<=high;i++){
        nums[i]=arr[i-low];

    }
    



}
void mergeSort(int low,int high,vector<pair<int,int>>&nums,vector<int>&ans){
    if(low>=high){
    return ;
}
int mid=(low+high)/2;
mergeSort(low,mid,nums,ans);
mergeSort(mid+1,high,nums,ans);
merge(low,mid,high,nums,ans);
}
    vector<int>countSmaller(vector<int>& nums) {
    vector<int>ans(nums.size(),0);
       vector<pair<int,int>>arr;
       for(int i=0;i<nums.size();i++){
        arr.push_back({nums[i],i});
       }
        mergeSort(0,nums.size()-1,arr,ans);
        return ans;
        
    }
};