class Solution {
public:
vector<int>ans;
int max_diff;
void find_combination(int n,int k,vector<int>&temp){
    if(n<=0)return ;
    if(k==0){
        if(n==1)
        {
            int min_val=*min_element(temp.begin(),temp.end());
            int max_val=*max_element(temp.begin(),temp.end());
            int diff=max_val-min_val;
            if(diff<max_diff){
                ans=temp;
                max_diff=diff;

            }
        }
        return;
    }

    for(int i=1;i<=n;i++){
        if(n % i==0){
            temp.push_back(i);
            find_combination(n/i,k-1,temp);
            temp.pop_back();
        }
    }
}
    vector<int> minDifference(int n, int k) {
        max_diff=INT_MAX;
        vector<int>temp;
        find_combination(n,k,temp);
        return ans;


        
    }
};