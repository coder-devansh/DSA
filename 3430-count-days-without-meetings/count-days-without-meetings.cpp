class Solution {
public:
static bool custom(vector<int>&a,vector<int>&b){
    return a[0]<b[0];
}
    int countDays(int days, vector<vector<int>>& meetings) {
       sort(meetings.begin(),meetings.end(),custom);
       int latestend=0;
       int freedays=0;
       for(int i=0;i<meetings.size();i++){
        int start=meetings[i][0];
        int end=meetings[i][1];
        if(start>latestend+1){
            freedays+=(start-latestend-1);
        }
        latestend=max(end,latestend);

       }
       freedays+=(days-latestend);
       return freedays;
      
    }
};