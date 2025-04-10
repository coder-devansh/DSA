class Solution {
public:

long long find(string str,string s,int limit){
    if(str.size()<s.size()) return 0;
    long long  remainL=str.size()-s.size();
    long long  count1=0;
    string tailstring=str.substr(str.size()-s.size());
    for(int i=0;i<remainL;i++){
        int digit=str[i]-'0';
        if(digit<=limit){
            count1+=digit*pow(limit+1,remainL-i-1);


        }else{
            count1+=(long long )pow(limit+1,remainL-i);
            return count1;
        }
        
    }
    if(tailstring>=s){
        count1+=1;
    }
    return count1;
}

    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string finish_str=to_string(finish);
        string start_str=to_string(start-1);
       return  find(finish_str,s,limit)-find(start_str,s,limit);
    
        
    }
};