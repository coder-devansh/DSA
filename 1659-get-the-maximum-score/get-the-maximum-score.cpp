class Solution {
public:
    int maxSum(vector<int>& arr1 , vector<int>& arr2) {
         sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end());
        int i=0;
        int j=0;
        long long  sum1=0;
        long long sum2=0;
        long long max_sum=0;
        long long result=0;
        int mod=(int)1e9+7;
        while(i<arr1.size() && j<arr2.size()){
            if(arr1[i]<arr2[j]){
                sum1+=arr1[i];
                i++;
            }
            else if(arr1[i]==arr2[j]){
                result+=max(sum1,sum2)+arr1[i];
                sum1=0;
                sum2=0;
                i++;
                j++;
            }else{
                sum2+=arr2[j];
                j++;
            }
        }
        while(i<arr1.size()){
            sum1+=arr1[i];
            i++;
        }
        while(j<arr2.size()){
            sum2+=arr2[j];
            j++;
        }
        result+=max(sum1,sum2);
        return result%mod;
    }
};