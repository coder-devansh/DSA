class Solution {
public:
bool merge(vector<pair<int,int>>&Intervals){
    vector<pair<int,int>>ans;
    sort(Intervals.begin(),Intervals.end());
    for(int i=0;i<Intervals.size();i++){
        auto first=Intervals[i];
        if(ans.empty()) ans.push_back({first.first,first.second});
        else if(ans[ans.size()-1].second>first.first)
        {
            int node=min(ans[ans.size()-1].first,first.first);
            int val=max(ans[ans.size()-1].second,first.second);
            ans.pop_back();
            ans.push_back({node,val});
            
        }else if(ans[ans.size()-1].second<=first.first){
            ans.push_back({first.first,first.second});
        }

    }
    return ans.size()>=3;
}
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int,int>>x_interval;
        vector<pair<int,int>>y_interval;
        for(auto it:rectangles){
            x_interval.push_back({it[0],it[2]});
            y_interval.push_back({it[1],it[3]});
        }
        cout<<"X"<<endl;
        bool left=merge(x_interval);
        cout<<'Y'<<endl;
        bool right=merge(y_interval);
       return left || right;
        
        
      

        
    }
};