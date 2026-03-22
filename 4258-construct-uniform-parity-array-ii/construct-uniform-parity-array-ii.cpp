// 3 4 1 11 2 5
// even
// 3 3 1 11 1 5 
// true


class Solution {
public:
bool find(int val,vector<int>&temp){
    int low=0;
    int high=temp.size()-1;
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(temp[mid]>=val){
            high=mid-1;

        }
        else if (temp[mid]<val){
            return true;
        }
    }
    return false;
}
bool check(int even,vector<int>&nums,vector<int>&odd_no){
    for(int i=0;i<nums.size();i++){
        if(even){
            if(nums[i]%2==0)continue;
            else {
                bool found=find(nums[i],odd_no);
                if(!found)return false;
            }
            
        }
        if(!even){
            if(nums[i]%2!=0)continue;
            else{
                bool found=find(nums[i],odd_no);
                if(!found)return false;
            }

        }
    }
    return true;

}

    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(),nums1.end());
        vector<int>odd_no;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2!=0){
                odd_no.push_back(nums1[i]);
            }
        }
       return check(0,nums1,odd_no) || check(1,nums1,odd_no) ;



        
    }
};