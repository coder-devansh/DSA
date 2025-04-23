class Solution {
public:
    int countLargestGroup(int n) {
        string str=to_string(n);
        int size=str.size();
        

        map<int,vector<int>>mp;
        int maxi=INT_MIN;
        for(int i=1;i<=n;i++){
            string str=to_string(i);
            int count=0;
            for(int i=0;i<str.size();i++){
                count+=(str[i]-'0');

            }
            mp[count].push_back(i);
            maxi=max(maxi,(int)mp[count].size());
        }
        int ans=0;
        for(auto it:mp){
            cout<<it.first<<" "<<it.second.size();
            cout<<endl;
           if(it.second.size()==maxi){
            ans++;
           }
        }
        // for(int i=1;i<=n;i++){
        //     if(m)
        // }
        return ans;
        

        
    }
};