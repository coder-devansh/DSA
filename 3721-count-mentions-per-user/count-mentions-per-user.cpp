class Solution {
public:
static bool compare(vector<string>&a,vector<string>&b){
    if(stoi(a[1])==stoi(b[1])){
        return a[0]>b[0];
    }
    return stoi(a[1])<stoi(b[1]);
}
    vector<int> countMentions(int no, vector<vector<string>>& events) {
        unordered_map<int,int>offline_mentions;
        unordered_map<int,int>time;
        vector<int>mentions(no,0);
        sort(events.begin(),events.end(),compare);
        for(auto it:events){
            string message=it[0];
            string timestamp=it[1];
            string message_id=it[2];
            if(message=="MESSAGE"){
                int timeStamp=stoi(timestamp);
                if(message_id=="HERE"){
                    for(int i=0;i<no;i++){
                        if(time.find(i)!=time.end()){
                            if(time[i]<=stoi(timestamp)){
                               
                                mentions[i]++;
                            }
                            else if(time[i]>stoi(timestamp)){
                            
                           }
                        }
                        
                        else{
                            mentions[i]++;
                        }
                    }
                   continue;
                }
                if(message_id=="ALL"){
                    for(int i=0;i<no;i++){
                        mentions[i]++;

                    }
                    continue;
                    
                }
                int n=message_id.size();
                int i=0;
                while(i<n){
                    while(message_id[i]>='a' && message_id[i]<='z'){
                        i++;
                    }
                    string str="";
                    while(message_id[i]-'0'>=0 && message_id[i]-'0'<=9){
                        str+=message_id[i];
                        i++;

                    }
                    mentions[stoi(str)]++;
                    
                    i++;
                }
            }
            if(message=="OFFLINE"){
                int id=stoi(message_id);
                time[id]=stoi(timestamp)+60;
            }
        }
            
        return mentions;







        
    }
};