// if l_time[i]>=time
class Solution {
public:
int binary_search(vector<pair<int,int>>&suffix,int val)
{
    int low=0;
    int high=suffix.size()-1;
    int index=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(suffix[mid].first<=val){
            index=mid;
           low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return index;
}
int calculate(int val,int dur,vector<int>&store){
    int low=0;
    int high=store.size()-1;
    int val1=-1;
    int mini=INT_MAX;
    while(low<=high){
        int mid=(low+high)/2;
        if(store[mid]<val){
            val1=store[mid];
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    if(val1==-1)return -1;
    return (val1+val-val1+dur);

}
int find(vector<pair<int,int>>&temp,vector<pair<int,int>>&val){
    int mini=INT_MAX;
    vector<int>store;
    
    for(auto it:val){
        store.push_back(it.first+it.second);
    }
    sort(store.begin(),store.end());
    for(int i=0;i<temp.size();i++){
        int start=temp[i].first;
        int dur=temp[i].second;
        int val1=calculate(start,dur,store);
        if(val1!=-1){
            mini=min(mini,val1);
        }
    }
    return mini;
    
}
    int earliestFinishTime(vector<int>& l_time, vector<int>& l_duration, vector<int>& w_time, vector<int>& w_duration) {
        vector<pair<int,int>>water;
        vector<pair<int,int>>land;
        int mini=INT_MAX;
        for(int i=0;i<l_time.size();i++){
            land.push_back({l_time[i],l_duration[i]});
        }
        for(int i=0;i<w_time.size();i++){
            water.push_back({w_time[i],w_duration[i]});
        }
        sort(land.begin(),land.end());
        sort(water.begin(),water.end());
        vector<int>s_land_time(l_time.size(),0);
        vector<int>s_water_time(w_time.size(),0);
        s_land_time[0]=land[0].second;
        for(int i=1;i<land.size();i++){
            s_land_time[i]=min(s_land_time[i-1],land[i].second);
        }

        s_water_time[0]=water[0].second;
        for(int i=1;i<water.size();i++){
            s_water_time[i]=min(s_water_time[i-1],water[i].second);
        }
        mini=min(mini,find(water,land));
        mini=min(mini,find(land,water));

       
        for(int i=0;i<l_time.size();i++){
            int end_time=l_time[i]+l_duration[i];
            int index=binary_search(water,end_time);
            if(index!=-1){
                mini=min(mini,end_time+s_water_time[index]);
            }
        }
        for(int i=0;i<w_time.size();i++){
            int end_time=w_time[i]+w_duration[i];
            int index=binary_search(land,end_time);
            if(index!=-1){
                mini=min(mini,end_time+s_land_time[index]);
            }
        }


    return mini;


        
    }
};