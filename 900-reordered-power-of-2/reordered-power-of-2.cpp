class Solution {
public:
    bool reorderedPowerOf2(int n) {
        map<string,int>mp;
       for(int i=0;i<31;i++){
       string str=to_string((int)pow(2,i));
       sort(str.begin(),str.end());
       cout<<str<<endl;
        mp[str]++;

       }
       string str=to_string(n);
       sort(str.begin(),str.end());
       if(mp.find(str)!=mp.end()){
        return true;
       }
       return false;

       


      
    }
};