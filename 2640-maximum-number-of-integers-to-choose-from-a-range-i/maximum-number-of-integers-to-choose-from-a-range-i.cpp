class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        map<int,int>mp;
        for(auto it:banned){
            mp[it]++;
        }
        vector<int>real;
        for(int i=1;i<=n;i++){
            if(mp.find(i)==mp.end()){
                real.push_back(i);
            }
        }
        if(real.size()==0){
            return 0;
        }
        int j=0;
        int count=0;
        int maxi=0;
        int sum=0;
        for(int i=0;i<real.size();i++){
            sum+=real[i];
            count++;
            while(j<real.size() && sum>maxSum){
                sum-=real[j];
                count--;
                j++;
                }
                maxi=max(maxi,count);

        }
        return maxi;
        
    }
};