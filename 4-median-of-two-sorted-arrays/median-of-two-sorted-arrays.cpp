class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>arr(nums1);
        for(int i=0;i<nums2.size();i++){
            arr.push_back(nums2[i]);
        }
        sort(arr.begin(),arr.end());
        if(arr.size()%2!=0){
            int mid=(arr.size())/2;
            return (double)arr[mid];
        }
        int mid=arr.size()/2;
        double ans=(double)(arr[mid-1]+arr[mid])/2;
        return ans;
        
        
    }
};