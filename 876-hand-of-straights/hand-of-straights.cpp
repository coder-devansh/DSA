class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize!=0)return false;
        map<int,int>mp;
       for(auto it:hand){
        mp[it]++;

       }
       while(true && mp.size()>0){
        long long prev=-1;
        int count=0;
        if(mp.size()<groupSize)return false;
          for(auto it:mp){
            
            if(count==groupSize)break;
            cout<<it.first<<" ";
            if(prev==-1){
                prev=it.first;
            }else if(it.first-prev!=1){
                return false;
                
            }else{
                prev=it.first;
            }
            mp[it.first]--;
            if(mp[it.first]==0)mp.erase(it.first);
            count++;
          }
          cout<<endl;
       }


        return true;
        
    }
};