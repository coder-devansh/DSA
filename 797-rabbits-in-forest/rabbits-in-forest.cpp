class Solution {
public:
    int numRabbits(vector<int>& answers) {
     map<int,int>mp;
     int cnt=0;
     for(auto it:answers)
     {
       
        mp[it]++;
     }
     for(auto it:mp){
        int val=ceil((double)it.second/(it.first+1));
        cout<<val<<" ";
        cnt+=(val*(it.first+1));
     }
     return cnt;
        
        
    }
};