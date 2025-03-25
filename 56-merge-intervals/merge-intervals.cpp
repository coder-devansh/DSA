class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& Intervals) {
         vector<vector<int>>ans;
    sort(Intervals.begin(),Intervals.end());
    for(int i=0;i<Intervals.size();i++){
        auto first=Intervals[i];
        if(ans.empty()) ans.push_back({first[0],first[1]});
        else if(ans[ans.size()-1][1]>=first[0])
        {
            int node=min(ans[ans.size()-1][0],first[0]);
            int val=max(ans[ans.size()-1][1],first[1]);
            ans.pop_back();
            ans.push_back({node,val});
            
        }else if(ans[ans.size()-1][1]<first[0]){
            ans.push_back({first[0],first[1]});
        }

    }
    return ans;
        
    }
};