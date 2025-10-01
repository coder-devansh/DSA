class Solution {
public:
void find_minutes(int led,int start,int sum,vector<string>&temp){
    if(sum>59)return;
    if(led==0){
        temp.push_back(to_string(sum));
        return;
        
    }
    int val[6]={1,2,4,8,16,32};
    for(int i=start;i<6;i++){
        find_minutes(led-1,i+1,sum+val[i],temp);
    }
}
void find_hour(int led,int start,int sum,vector<string>&temp){
    if(sum>11)return;
    if(led==0){
        temp.push_back(to_string(sum));
        return;
        
    }
    int val[6]={1,2,4,8};
    for(int i=start;i<4;i++){
        find_hour(led-1,i+1,sum+val[i],temp);
    }
}

    vector<string> readBinaryWatch(int turnedOn) {
        vector<string>ans;
    for(int i=0;i<=turnedOn;i++){
        vector<string>temp;
        find_hour(i,0,0,temp);
        vector<string>str;
        find_minutes(turnedOn-i,0,0,str);
        string s="";
        for(auto it: temp) {
    for(auto ele: str) {
        string s = it; 
        if(ele.size() < 2) {
            s += ":0";
        } else {
            s += ":";
        }
        s += ele;
        ans.push_back(s);
    }
}

        
    }
    return ans;
        
    }
};